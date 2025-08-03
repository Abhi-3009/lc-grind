ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp;
        while(curr){
            temp=curr;
            curr=curr->next;
            temp->next=prev;
            prev=temp;
        }
        return temp;
    }