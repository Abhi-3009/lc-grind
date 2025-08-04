ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *temp;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        temp->next = prev;
        prev = temp;
    }
    return temp;
}

// recursive method
ListNode *reverseListRecursive(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
// iterative method
ListNode *reverseListIterative(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    while (curr)
    {
        next = curr->next; // Store next node
        curr->next = prev; // Reverse the link
        prev = curr;      // Move prev to current
        curr = next;      // Move to next node
    }
    return prev; // New head of the reversed list
}
// tail recursive method
ListNode *reverseListTailRecursive(ListNode *head, ListNode *prev = NULL)
{
    if (head == NULL)
        return prev;
    ListNode *next = head->next; // Store next node
    head->next = prev;           // Reverse the link
    return reverseListTailRecursive(next, head); // Recur with next node and current as previous
}
// in-place reversal of linked list
ListNode *reverseListInPlace(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *next = curr->next; // Store next node
        curr->next = prev;           // Reverse the link
        prev = curr;                 // Move prev to current
        curr = next;                 // Move to next node
    }
    return prev; // New head of the reversed list
}