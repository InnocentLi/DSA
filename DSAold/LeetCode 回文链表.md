1.设置快指针fast慢指针slow找到链表的中间结点

2.两个指针同时从头节点和中间结点的next结点遍历

3.val值相同就是回文链表

```c++
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    struct ListNode *fast = head, *slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *last = slow->next, *temp;
    while (last->next != NULL) {
        temp = last->next;
        last->next = temp->next;
        temp->next = slow->next;
        slow->next = temp;
    }
    while (slow->next != NULL) {
        if (slow->next->val != head->val) return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

```

