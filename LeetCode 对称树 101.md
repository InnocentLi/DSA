Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1

   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
给定二叉树，检查它是否是自身的镜像（即，围绕其中心对称）。

#### 思路

##### 一.

1.如果树为空，那么它一定是对称的；

2.如果两个结点的值相等，判断p的左子树和q的右子树以及p的右子树和q的左子树是否相等；

##### 二.

也可以用遍历顺序来区分

正常:根，左，右

镜子:根，右，左

对称树

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric_node(struct TreeNode* p, struct TreeNode* q) {
    if(!p && !q) return true;
    if(p == NULL || q == NULL) return false;
    if(p->val == q->val){
        return isSymmetric_node(p->left, q->right) && isSymmetric_node(p->right, q->left);
    }else{
        return false;
    }
}
bool isSymmetric(struct TreeNode* root) {
    if(!root) return true;
    return isSymmetric_node(root->left, root->right);
    
}
```

