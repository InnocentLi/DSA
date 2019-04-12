1.首先遍历一遍链表，用count计数记录一共有多少个结点2.第二遍便利链表，用count1找到删除结点的位置

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
     if(head == NULL){
        return head;
    }
    struct ListNode *current_node = head;
    int count = 0;
    while(current_node != NULL){
        current_node = current_node->next;
        count++;
    }
    struct ListNode *current_node1 = head;
    int count1 = 0;
    if(n == count){
        struct ListNode *delete_node1 = head; 
        head = current_node1->next;
        free(delete_node1);
        return head;
    }
    while(current_node1->next != NULL && count1 < count - n - 1){
        current_node1 = current_node1->next;
        count1++;
    }
    if(count1 == count - n - 1&& current_node1->next != NULL){
        struct ListNode *delete_node = current_node1->next;
        current_node1->next = delete_node->next;
        free(delete_node);
        return head;
    }
    return head;
}

```

