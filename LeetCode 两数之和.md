Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

给定一个整数数组，返回两个数字的**索引**，使它们相加到特定目标。

您可以假设每个输入**只有**一个解决方案，并且您可能不会两次使用*相同的*元素。

**例：**

```
给定nums = [2,7,11,15]，target = 9，

因为nums [ 0 ] + nums [ 1 ] = 2 + 7 = 9，
返回[ 0，1 ]。
```

#### 思路

这么简单的题暴力一点啦！

1.连续遍历nums 更新new_target = target - nums[i];

2.循环遍历找到new_target。

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *ans = (int *)malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize; i++){
        int new_target = target - nums[i];
        for(int j = i + 1; j < numsSize; j++){
            if(nums[j] == new_target){
                ans[0] = i;
                ans[1] = j;
            }
        }
    }
    return ans;
}

```

##### 杨式矩阵

在杨式矩阵中找到一个值x可以有两种方法:1.从右上角 2.从左下角

![img](https://projecteuler.net/project/images/p015.gif)

|      |  2   |  7   |  11  |  15  |
| :--: | :--: | :--: | :--: | :--: |
|  2   |  4   |  9   |  13  |  17  |
|  7   |  9   |  14  |  18  |  22  |
|  11  |  13  |  18  |  22  |  26  |
|  15  |  17  |  22  |  26  |  30  |



