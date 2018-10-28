÷Given an array of integers that is already **sorted in ascending order**, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

**Note:**

- Your returned answers (both index1 and index2) are not zero-based.

- You may assume that each input would have *exactly* one solution and you may not use the *same* element twice.

**Example:**

```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
```

------

##### 暴力求解法:

1.循环遍历数组，认定numbers[i]为target的一个元素；

2.从i之后遍历数组，找new_target；


```c
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ans = malloc((*returnSize) * sizeof(int));
    for(int i = 0; i < numbersSize; i++){
        int new_target = target - numbers[i];
        for(int j = i + 1; j < numbersSize; j++){
            if(numbers[j] == new_target){
                ans[0] = i + 1;
                ans[1] = j + 1;
                return ans;
            }
        }
    }
    return 0;
}
```

##### 基于杨式矩阵法

时间复杂度O(n)

空间复杂度O(1)

代码量就减少很多啦

这是一种思维模式，把寻找两数之和看成一个二维数组，二维数组中存的数就是目标值target，从左下角向上爬楼梯和从右上角向下走楼梯都可以，以从右上角向下爬楼梯为例，(a[0]{3} = 17)>target,在杨式矩阵中，一个值的左边总是比这个值小，一个值的下面总是比这个值大，所以应该向左走一个格子，走到(a[0]{2} >target)，继续向左走，走到(a[0]{1}] = target)找到值，返回。

那么就这到题而言，我们并不需要开辟一个二维数组，我们只需要，把i看成是行，j看成是列

nums[i] + nums[j] > target 在杨式矩阵中向左走，即j--;

nums[i] + nums[j] < target 在杨式矩阵中向下走，即i++;

##### 注意:i = j时，不满足题意，记得舍去哟！！！

在杨式矩阵中找到一个值x可以有两种方法:1.从右上角 2.从左下角

![img](https://projecteuler.net/project/images/p015.gif)

|      |  2   |  7   |  11  |  15  |
| :--: | :--: | :--: | :--: | :--: |
|  2   |  4   |  9   |  13  |  17  |
|  7   |  9   |  14  |  18  |  22  |
|  11  |  13  |  18  |  22  |  26  |
|  15  |  17  |  22  |  26  |  30  |

```c
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ans = (int *)malloc(sizeof(int) * (*returnSize));
    int i = 0, j = numbersSize - 1;
    while(numbers[i] + numbers[j] != target){
        if(numbers[i] + numbers[j] > target) j--;
        else i++;
    }
    if(i == j) return ans;
    else ans[0] = i + 1, ans[1] = j + 1;

    
    
    return ans;
}
```

