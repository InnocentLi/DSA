1.判断val值是否相等

2.相等时删除重复元素

```c
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *current_node = head;
    while(current_node != NULL && current_node->next != NULL){
        if(current_node->val == current_node->next->val){
            struct ListNode *delete_node = current_node->next;
            current_node->next = delete_node->next;
            free(delete_node);
        }else{
            current_node = current_node->next;
        }
    }
    return head;
}

```

