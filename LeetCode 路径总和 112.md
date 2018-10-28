Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

**Note:** A leaf is a node with no children.

**Example:**

Given the below binary tree and `sum = 22`,

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```

return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.

给定二叉树和求和，确定树是否具有根到叶路径，使得沿路径的所有值相加等于给定的总和。

####  思路

##### 错误分析

刚开始我的代码是这个样子滴

1.如果root为NULL且sum为0，那么就相当于找到路径

2.不然就将目标sum减去已找到的路径值，递归遍历左右子树中有没有路径

##### 未通过的原因 

Input:[] 

​	   0

Output:true

Expected:false

也就是说理解错题意了，当没有根结点的时候，哪怕是sum为0都找不到路径的

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if(!root && sum == 0) return true;
    if(root){
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
    return false;
}
```

##### 矫正

错在哪里了呢？

我们把返回true的条件重新梳理一下，当root为NULL的时候是不能返回true的

所以新的判断条件就变成:root && root->left == NULL && root->right == NULL && sum == root->val

注意这里sum不是判断== 0，而是root->val

```c
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root && root->left == NULL && root->right == NULL && sum == root->val) return true;
    if(root){
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
    return false;
}
```

Given the below binary tree and `sum = 22`,

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```

return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.