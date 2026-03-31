class LinkedList {

    struct ListNode {

        int val;
        ListNode* next;


        ListNode(): val(0), next(nullptr) {}
        ListNode(int x): val(x), next(nullptr) {}

    };


    ListNode* head;
    ListNode* tail;

public:
    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* current = head->next;

        for(int i = 0; i < index && current; i++){
            current=current->next;
        }

            return (current) ? current->val : -1;
        
        
    }

    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);

        newNode->next = head->next;
        head->next = newNode;

        if (!newNode->next){
            tail = newNode;
        }

    }
    
    void insertTail(int val) {

        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        tail = newNode;
        
    }

    bool remove(int index) {
        
        ListNode* current = head;

        for (int i = 0; i < index && current->next; i++){
            current = current->next;
        }

       if (current && current->next){
       
            if(current->next == tail){
                tail = current;
                
            }
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }

        return false;
    }

    vector<int> getValues() {
        std::vector<int> vals;
        ListNode* current = head->next;

        while(current) {
            vals.push_back(current->val);
            current=current->next;
        }

        return vals;
        
    }
};
