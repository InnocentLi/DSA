1.设置快慢指针，快指针每次走两步，慢指针每次走一步

2.若两指针相遇，有环存在

```c

bool hasCycle(struct ListNode *head) {
    if(head == NULL){
        return 0;
    }
    struct ListNode *first = head,*second = head->next;
    while(first != second && second && second->next){
        first = first->next;
        second = second->next->next;
    }
    if(second == NULL || second->next == NULL) return 0;
    return 1;
    
}

```

