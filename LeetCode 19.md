LeetCode 19



题目链接:

<https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/>

虚拟头节点 C

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
     struct ListNode ret;
     ret.next = head;
     struct ListNode* p = &ret;
     struct ListNode* q = &ret;
     if(!head -> next||!head){
         return head;
     }
     while(n--){
         p = p->next;
     }
     p = p->next;
     while(p!=NULL){
        p = p->next;
        q = q->next; 
     }
     q ->next = q->next->next ; 
     
     return ret.next;
}
```

注意⚠️最后的` return ret.next;`如果直接写`return head`逻辑上没有任何问题但是会报语法错误



如果不采用虚拟头节点

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
        struct ListNode* p1 = head;
        struct ListNode* p2 = head;
        while(n--){
            p1 = p1 -> next;
        }
        if(!p1){
            return head->next;
        }
        while(p1->next){
            p1=p1->next;
            p2=p2->next;
        }
        p2->next = p2->next->next;
        return head;     
}
```

