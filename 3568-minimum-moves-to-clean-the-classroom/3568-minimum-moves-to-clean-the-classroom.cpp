class Solution {
public:

    struct State {
        int r;
        int c;
        int energy;
        int mask;
        int dist;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // ------------------------------------------------
        // Step 1: Find S and assign IDs to all litter
        // ------------------------------------------------

        int sr, sc;
        int litterCount = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        // All litter collected
        int allMask = (1 << litterCount) - 1;

        // ------------------------------------------------
        // Step 2: visited[r][c][energy][mask]
        // ------------------------------------------------

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        // ------------------------------------------------
        // Step 3: BFS
        // ------------------------------------------------

        queue<State> q;

        q.push({sr, sc, energy, 0, 0});

        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            State cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int currEnergy = cur.energy;
            int mask = cur.mask;
            int dist = cur.dist;

            // --------------------------------------------
            // If all litter collected
            // --------------------------------------------

            if (mask == allMask) {
                return dist;
            }

            // No energy -> cannot make another move
            if (currEnergy == 0) {
                continue;
            }

            // --------------------------------------------
            // Try 4 directions
            // --------------------------------------------

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // ----------------------------------------
                // Moving costs 1 energy
                // ----------------------------------------

                int newEnergy = currEnergy - 1;

                // ----------------------------------------
                // Collect litter if present
                // ----------------------------------------

                int newMask = mask;

                if (classroom[nr][nc] == 'L') {

                    int id = litterId[nr][nc];

                    newMask |= (1 << id);
                }

                // ----------------------------------------
                // Reset energy if we enter R
                // ----------------------------------------

                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // ----------------------------------------
                // Avoid duplicate states
                // ----------------------------------------

                if (!visited[nr][nc][newEnergy][newMask]) {

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask,
                        dist + 1
                    });
                }
            }
        }

        return -1;
    }
};