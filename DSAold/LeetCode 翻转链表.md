```c

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode * current_node,*next_node,ret;
    if(head == NULL){
        return head;
    }
    current_node = head->next;
    head->next = NULL;
    while(current_node != NULL){
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}

```

