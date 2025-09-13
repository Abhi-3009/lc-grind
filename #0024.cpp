ListNode *swapPairs(ListNode *head)
{
    ListNode dummy(0);
    dummy.next = head;

    ListNode *f = &dummy; // follower
    ListNode *r = head;   // runner

    while (r && r->next)
    {
        ListNode *first = r;
        ListNode *second = r->next;

        // swap
        f->next = second;
        first->next = second->next;
        second->next = first;

        // move f and r
        f = first;
        r = first->next;
    }

    return dummy.next;
}