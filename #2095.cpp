ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *follow = NULL;

    while (fast && fast->next)
    {
        follow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    follow->next = slow->next;
    return head;
}