ListNode *reverse(ListNode *head)
{
    ListNode *run = head->next, *fol = head;
    while (run)
    {
        head->next = run->next;
        run->next = fol;
        fol = run;
        run = head->next;
    }
    head = fol;
    return head;
}
ListNode *removeNodes(ListNode *head)
{
    if (!head || !head->next)
        return head;
    head = reverse(head);
    ListNode *t1 = head;
    ListNode *t2 = t1->next;
    while (t2)
    {
        if (t1->val > t2->val)
            t2 = t2->next;
        else
        {
            t1->next = t2;
            t1 = t2;
            t2 = t2->next;
        }
    }
    t1->next = NULL;
    return reverse(head);
}