Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow **a node to be a descendant of itself**).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

```
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
```

**Example 1:**

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```

**Example 2:**

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself 
             according to the LCA definition.
```

**Note:**

- All of the nodes' values will be unique.
- p and q are different and both values will exist in the BST.

给定二叉搜索树（BST），找到BST中两个给定节点的最低共同祖先（LCA）。

根据[维基百科上LCA](https://en.wikipedia.org/wiki/Lowest_common_ancestor)的[定义](https://en.wikipedia.org/wiki/Lowest_common_ancestor)：“最低共同祖先在两个节点p和q之间定义为T中的最低节点，其中p和q都是后代（我们允许**节点成为其自身的后代**）。 ”

给定二叉搜索树：root = [6,2,8,0,4,7,9，null，null，3,5]

#### 思路

1.如果在左右子树中能分别找到p和q，那么它们的共同祖先就是root；

2.如果在左子树能找到p和q，那么左子树就是共同祖先；

3.如果在右子树能找到p和q，那么右子树就是共同祖先；

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(!root || root == p || root == q) return root;//当前结点为NULL，返回NULL；当前结点为p或q，返回root；
    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);//递归遍历左子树，找p和q，如果先找到p，返回p；先找到q就返回q；
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);//递归遍历右子树；
    if(l && r) return root;//如果左右子树都能找到p和q，那么root就是最低共同祖先，如Eg1所示；
    if(!l) return r;//如果左子树中找不到p和q，那么在右子树中先找到的p或q就是LCA；
    if(!r) return l;//如果右子树中找不到p和q，那么在左子树中先找到的p或q就是LCA；
    return root;
}
```

