LeetCode 24



题目链接:

<https://leetcode-cn.com/problems/swap-nodes-in-pairs/>


```c
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p,*q,ret;
    ret.next = head;
    p = &ret;
    q = head;
    while(q&&q->next){
        p -> next = q -> next;
        q -> next = p -> next ->next;
        p -> next -> next = q;  
        p = q;
        q = p ->next;
    }
    return ret.next;
}

```

83



