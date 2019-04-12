Given a binary tree, return all root-to-leaf paths.

**Note:** A leaf is a node with no children.

**Example:**

```
Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
```

给定二叉树，返回所有根到叶路径。

**注意：**  叶子是没有子节点的节点。

#### 思路



```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//二叉树路径
void copy(int *str, char *result, int ind){
    int len = 0;
    for(int i = 0; i < ind; i++){
        len += sprintf(result + len, "%d->", str[i]);//sprintf是将整型str转换成字符型result->；
    }
    result[len - 2] = '\0';//最后一个字符不需要->，把ta强制转换为‘\0’结束；
}

void Paths(struct TreeNode* root, int* returnSize, char **ans, int *str, int *ind){//returnSize是二维数组的行数，ans是最后返回结果的二维数组，str是暂存的第某行的所有字符(也就是第n条路径)，ind是第n条路径的第i个数；
    if(root == NULL) return ;
    str[(*ind)++] = root->val;//把val存在str数组中；
    if(root->left == NULL && root->right == NULL){//当左右子树都为NULL时，表示这条路径走完了；
        ans[*returnSize] = (char *)malloc(sizeof(char) * 100);//就把这条路径存在第i行中，需要为这条路径开辟空间；
        copy(str, ans[*returnSize], *ind);//将这条路径的整型转换成字符串的形式；
        (*returnSize)++;//查找下一行；
        (*ind)--;//回溯遍历下一个路径；
        return ;
    }
    Paths(root->left, returnSize, ans, str, ind);//如果左右子树其中有不为空的情况，就继续遍历；
    Paths(root->right, returnSize, ans, str, ind);
    (*ind)--;//遍历之后回溯；
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
     int *ind = (int *)malloc(sizeof(int));
    *ind = 0;
    int *str = (int *)malloc(sizeof(int) * 100);
    char **ans = (char **)malloc(sizeof(char*) * 100);
    *returnSize = 0;
    if(root == NULL) return NULL;
    Paths(root, returnSize, ans, str, ind);
    return ans;
}
```



 