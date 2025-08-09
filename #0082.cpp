ListNode *deleteDuplicates(ListNode *head)
{
    ListNode dummy(0, head);
    ListNode *temp = &dummy;
    while (head)
    {
        if (head->next && head->val == head->next->val)
        {
            while (head->next && head->val == head->next->val)
                head = head->next;
            head = head->next;
            temp->next = head;
        }
        else
        {
            temp = head;
            head = head->next;
        }
    }
    return dummy.next;
}