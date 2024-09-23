class Node
{
    public:
        int key;
        int val; 
        Node* next;
        Node* prev;

        Node() {}

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
};

class LRUCache 
{
    int capacity;
    Node* head;
    Node* tail;
    map<int, Node*> cache;

    void deleteNode(Node* curr)
    {
        Node* prev = curr->prev;
        Node* next = curr->next;

        if (prev) prev->next = next;
        if (next) next->prev = prev;
    }

    void moveFront(Node* curr)
    {
        Node* afterHead = head->next;

        head->next = curr;
        curr->next = afterHead;
        curr->prev = head;
        if (afterHead) afterHead->prev = curr;
    }

    public:

        LRUCache(int capacity) 
        {
            this->capacity = capacity;       
            head = new Node(); 
            tail = new Node();  
            head->next = tail;
            tail->prev = head;
        }
        
        int get(int key) 
        {
            if (cache.find(key) == cache.end()) 
            {
                return -1;
            }

            Node* curr = cache[key];
            deleteNode(curr);
            moveFront(curr);
            return curr->val;
        }
        
        void put(int key, int value) 
        {
            if (cache.find(key) != cache.end())
            {
                Node* curr = cache[key];
                curr->val = value;
                deleteNode(curr);
                moveFront(curr);
            }
            else
            {
                if (cache.size() == capacity)
                {
                    Node* last = tail->prev;
                    int currKey = last->key;
                    deleteNode(last);
                    cache.erase(currKey);
                }

                Node* curr = new Node(key, value);
                moveFront(curr);
                cache[key] = curr;
            }
        }

        ~LRUCache() 
        {
            delete head;
            delete tail;
        }
};
