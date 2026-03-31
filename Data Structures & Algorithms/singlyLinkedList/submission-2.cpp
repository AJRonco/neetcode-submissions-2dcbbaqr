class LinkedList {

    struct ListNode{

        ListNode* next;
        int value;
        ListNode() :  value(0), next(nullptr) {}
        ListNode(int x)  : value(x), next(nullptr){} 

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
        
        for (int i = 0; i < index && current != nullptr; i++){
            current=current->next;
        }

        return (current != nullptr) ? current->value : -1;
    }

    void insertHead(int val) {
        ListNode* insert = new ListNode(val);
        insert->next = head->next;
        head->next = insert;
        if (insert->next == nullptr) {
            tail = insert;
        }
    }
    
    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        tail = newNode;
    }

    bool remove(int index) {
        ListNode* current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }

        if (current != nullptr && current->next != nullptr) {
            if (current->next == tail) {
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
        std::vector<int> values;
        ListNode* current = head->next;

        while(current != nullptr){
            values.push_back(current->value);
            current = current->next;
        }

        return values;
    }
};