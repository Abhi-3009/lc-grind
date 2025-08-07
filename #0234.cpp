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

bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *second_half = reverse(slow->next);
    ListNode *first_half = head;
    while (second_half)
    {
        if (second_half->val != first_half->val)
            return false;
        else
        {
            second_half = second_half->next;
            first_half = first_half->next;
        }
    }
    return true;
}