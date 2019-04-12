1.增加虚拟头节点，存在头节点的删改时操作简单

2.设置当前结点current_node,若current_node->next ->val = val,删除current_node->next,否则后移 

```c

struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL) return head;
    struct ListNode * current_node,*delete_node,ret;
    ret.next = head;
    current_node = &ret;
    while(current_node != NULL && current_node->next != NULL){
        delete_node = current_node->next;
        if(delete_node->val == val){
            current_node->next = delete_node->next;
            free(delete_node);
        }else{
        current_node = current_node->next;
        }
    }
    return ret.next;
    
}

```

