ListNode *partition(ListNode *head, int x)
{
    ListNode *low = new ListNode(0);
    ListNode *high = new ListNode(0);
    ListNode *low_end = low;
    ListNode *high_end = high;

    while (head)
    {
        if (head->val < x)
        {
            low_end->next = head;
            low_end = low_end->next;
        }
        else
        {
            high_end->next = head;
            high_end = high_end->next;
        }
        head = head->next;
    }
    high_end->next = NULL;
    low_end->next = high->next;

    ListNode *new_head = low->next;
    return new_head;
    
}