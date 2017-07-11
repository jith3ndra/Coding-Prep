


class LRUCache {
    struct ListNode{
        ListNode* prev;
        ListNode* next;
        int val;
        int key;
    };
    int size=0;
    int max_size=0;
    unordered_map<int,ListNode*> map1;
    ListNode* head,*last,*curr,*temp;
    bool full_size = false;
public:
    void change_pri(ListNode* node){
        if(node== head){
            return;
        }
        ListNode* prev=node->prev,*next = node->next;
        if(last ==node){
            //cout << node->prev->val<<endl;
            //cout << node->next->val<<endl;
            last = prev;  //important
        }
        prev->next = next;
        next->prev = prev;
        
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
        
        head = node;
    }
    LRUCache(int capacity) {
        max_size = capacity;
        int ctr =0;
        while(ctr<max_size){
            ListNode* node = (ListNode*) malloc(sizeof(struct ListNode));
            //node->val = ctr+1;
            node->next = NULL;
            node->prev = temp;
            if(temp)
                temp->next = node;
            if(!ctr){
                head = node;
            }
            ctr++;
            temp = node;
        }
        temp->next = head;
        head->prev = temp;
        
        //last = temp; //bug following is the fix
        last = head;
        
        curr= head;
        //cout << head->val << endl;
        //cout << last->val << endl;
    }
    
    int get(int key) {
        if(map1.count(key)){
            change_pri(map1[key]);
            return map1[key]->val;
        }else
            return -1;
    }
    
    void put(int key, int value) {
        if(map1.count(key)){
            map1[key]->val = value;
            change_pri(map1[key]);
            return;
        }
        if(size==max_size ){
            //cout << last->val << endl;
            map1.erase(last->key);
            last->val = value;
            last->key = key;
            map1[key] = last;
            change_pri(last);
        }else{
                curr->val = value;
                curr->key = key;
                temp = curr->next;
                map1[key]= curr;
                change_pri(curr);
                curr = temp;
            size++;
        }
        //cout << last->val<< endl;
    }
};

