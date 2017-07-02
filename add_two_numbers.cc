
    private:
     ListNode* addTwoNumbers(ListNode* l1,ListNode* l2, int diff,int &carry){
         if(!l1 && !l2){
             return NULL;
         }else{
             ListNode* node = (ListNode *) malloc(sizeof(struct ListNode));
             node->next = (diff>0 ?addTwoNumbers(l1->next,l2,diff-1,carry):addTwoNumbers(l1->next,l2->next,diff,carry));
             if(!diff){
                 node->val = (l1->val +l2->val +carry)%10;
                 carry = (l1->val +l2->val +carry) / 10;
             }else{
                 node->val = (l1->val +carry)%10;
                 carry = (l1->val +carry) / 10;
             }
             return node;
         }
     }
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int len1 =0,len2=0;
        ListNode* temp=l1;
        while(temp){
              len1++;temp = temp->next;
        }
        temp=l2;
        while(temp){
              len2++;temp = temp->next;
        }
        int diff = abs(len1-len2),carry=0;
        ListNode* head = (len1>len2 ?addTwoNumbers(l1,l2,diff,carry):addTwoNumbers(l2,l1,diff,carry));
        if(carry){
            ListNode* h = (ListNode*)malloc(sizeof(struct ListNode));
            h->next = head;
            h->val = carry;
            return h;
        }
       return head;
    }
