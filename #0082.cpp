ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        while(t1 && t1->next){
            if(t1->val == t2->val){
                t2 = t2->next;
                t1->next = t1->next->next;
            } else{
                t1 = t2;
                t2 = t2->next;
            }
        }
        return head;
    }