

Invert a binary tree.

**Example:**

Input:

```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```

Output:

```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

#### 思路

1.如果树的根为空，直接返回NULL即可；

2.当根的左子树或者右子树存在的时候，将左右子树交换

3.递归交换接下来的左右子树；

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode * current_node = NULL;
    if(!root) return NULL;
    if(root->left || root->right){
        current_node = root->right;
        root->right = root->left;
        root->left = current_node;
        invertTree(root->left);
        invertTree(root->right);
    }
     return root;
}
```

