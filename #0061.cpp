ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next)
        return head;
    int count = 0;
    ListNode *t1 = head;
    ListNode *run = head->next, *fol = head;
    while (t1)
    {
        count++;
        t1 = t1->next;
    }
    t1 = head;
    k %= count;
    if (k == 0)
        return head;
    int i = count - k;
    while (--i > 0)
    {
        run = run->next;
        fol = fol->next;
    }
    fol->next = nullptr;
    head = run;
    while (run && run->next)
        run = run->next;
    run->next = t1;
    return head;
}