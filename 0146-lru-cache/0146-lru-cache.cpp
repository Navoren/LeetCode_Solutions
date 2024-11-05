class LRUCache {
public:
class Node{
    public:
    int val;
    int key;
    Node* next;
    Node* prev;

    Node(int _key, int _val){
        key = _key;
        val = _val;
    }
};

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mpp;
    int cap;


    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node * newNode){
        Node * temp = head->next;

        newNode->next = temp;
        temp->prev = newNode;

        head->next= newNode;
        newNode->prev = head;
    }

    void deleteNode(Node * delNode){
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    
    int get(int key) {
        if(mpp.find(key)!= mpp.end()){
            Node* res = mpp[key];
            mpp.erase(key);
            deleteNode(res);
            insertAfterHead(res);
            mpp[key] = head->next;

            return res->val;
        }
        return -1;
    }
    
    void put(int key, int val) {
        if(mpp.find(key) != mpp.end()){
            Node* existingNode = mpp[key];
            deleteNode(existingNode);
            mpp.erase(key);
        }
        if(mpp.size() == cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertAfterHead(new Node(key,val));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */