Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

> a binary tree in which the depth of the two subtrees of *every* node never differ by more than 1.

**Example 1:**

Given the following tree `[3,9,20,null,null,15,7]`:

```
    3
   / \
  9  20
    /  \
   15   7
```

Return true.
**Example 2:**

Given the following tree `[1,2,2,3,3,null,null,4,4]`:

```
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```

Return false.

给定二叉树，确定它是否是高度平衡的。

对于此问题，高度平衡二叉树定义为：

> 一个二叉树，其中*每个*节点的两个子树的深度从不相差超过1。

#### 思路

1.求左右子树的最大深度

2.两子树最大深度做差求绝对值<=1时满足条件

3.递归遍历左右子树是不是都满足平衡二叉树的条件

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Depth(struct TreeNode* root){
    if(root == NULL) return 0;
    int left = Depth(root->left);
    int right = Depth(root->right);
    return left > right ? left + 1 : right + 1;
}

bool isBalanced(struct TreeNode* root) {
    if(root == NULL) return true;
    if(abs(Depth(root->right) - Depth(root->left)) <= 1){
        return (isBalanced(root->left) && isBalanced(root->right));
    }else{
        return false;
    }
    return true;
}
```

