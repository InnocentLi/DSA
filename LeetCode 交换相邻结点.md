```c
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode ret;
    ret.next = head;
    struct ListNode *p, *q;
    p = &ret; q = head;
    while(p->next && q->next){
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
        p = q;
        q = q->next;
    }
    return ret.next;
 
 
    
}

```

