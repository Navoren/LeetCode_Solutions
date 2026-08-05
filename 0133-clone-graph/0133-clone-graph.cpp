/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_map<Node*,Node*> mpp;
        stack<Node*> st;

        mpp[node] = new Node(node->val);
        st.push(node);

        while(!st.empty()){
            Node* curr = st.top();
            st.pop();

            for(auto it : curr->neighbors){
                if(mpp.find(it) == mpp.end()){
                    mpp[it] = new Node(it->val);
                    st.push(it);
                }

                mpp[curr]->neighbors.push_back(mpp[it]);
            }
        }

        return mpp[node];
    }
};