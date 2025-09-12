ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (!head || left == right)
        return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    // Step 1: move prev to node before 'left'
    for (int i = 1; i < left; i++)
    {
        prev = prev->next;
    }

    // Step 2: reverse sublist from left to right
    ListNode *curr = prev->next;
    ListNode *nextNode = nullptr;
    ListNode *prevNode = nullptr;

    for (int i = 0; i <= right - left; i++)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }

    // Step 3: reconnect
    prev->next->next = curr; // tail of reversed sublist points to remainder
    prev->next = prevNode;   // prev connects to new head of sublist

    return dummy.next;
}