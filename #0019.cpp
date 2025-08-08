ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head || !head->next && n == 1)
        return nullptr;

    ListNode *count = head;
    int c = 0;
    while (count)
    {
        c++;
        count = count->next;
    }

    ListNode *temp = head;
    if (c == n)
        head = head->next;
    for (int i = 1; i < c - n; i++)
    {
        temp = temp->next;
    }
    if (temp->next)
        temp->next = temp->next->next;
    else
        temp->next = nullptr;

    return head;
}