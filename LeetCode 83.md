LeetCode 83



<https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/submissions/>

不考虑内存泄露

```c
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* p = head;
    while(p&&p->next){
        if(p->val == p->next->val){
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }
    return head;    
}
```



考虑内存泄露

```c

struct ListNode* deleteDuplicates(struct ListNode* head) {
       struct ListNode *p = head;
       struct ListNode *q;
        while(p && p->next){
            if(p->val != p->next->val){
                p = p->next;
            }else{
                q = p->next;
                p->next = q->next;
                free(q);
            }
        }
       return head;
}
```

