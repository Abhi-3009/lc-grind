ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return nullptr;
    ListNode *t1 = headA, *t2 = headB;
    int count1 = 0, count2 = 0, diff = 0;
    while (t1)
    {
        count1++;
        t1 = t1->next;
    }
    while (t2)
    {
        count2++;
        t2 = t2->next;
    }
    if (t1)
        count1++;
    if (t2)
        count2++;
    t1 = headA;
    t2 = headB;
    if (count1 > count2)
    {
        diff = count1 - count2;
        while (diff--)
            t1 = t1->next;
    }
    else
    {
        diff = count2 - count1;
        while (diff--)
            t2 = t2->next;
    }
    while (t1 && t2)
    {
        if (t1 == t2)
            return t1;
        t1 = t1->next;
        t2 = t2->next;
    }
    return nullptr;
}