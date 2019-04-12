给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

}12345678910
```

**示例：**

> 给定一个链表: 1->2->3->4->5, 和 n = 2.
> 当删除了倒数第二个节点后，链表变为 1->2->3->5.

**说明：**

给定的 n 保证是有效的。

**进阶：**

你能尝试使用一趟扫描实现吗？

# 题解

**思路:** 让first指针先走n步，然后first,last同时向后走，直到first走到最后一个节点，last->next即为要删除的节点 
**note:** 要考虑只有一个节点和删除头节点的情况

给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.

```
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *first = head, *last = head;
    while (n--) {
        first = first->next;
    }
    if (first == NULL) {
        head = head->next;
        free(last);
        return head;
    }
    while (first->next != NULL) {
        first = first->next;
        last = last->next;
    }
    first = last->next;
    last->next = last->next->next;
    free(first);
    return head;
}12345678910111213141516171819
```

 