Given a string, find the length of the **longest substring** without repeating characters.

**Examples:**

Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.

Given `"bbbbb"`, the answer is `"b"`, with the length of 1.

Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note that the answer must be a **substring**, `"pwke"` is a *subsequence*and not a substring.

给定一个字符串，找到**最长子字符串**的长度而不重复字符。

**例子：**

鉴于`"abcabcbb"`，答案是`"abc"`，长度为3。

鉴于`"bbbbb"`，答案是`"b"`，长度为1。

给定`"pwwkew"`，答案是`"wke"`，长度为3.请注意，答案必须是**子字符串**，`"pwke"`是**子***序列*而不是子字符串。

#### 思路

1.ASCII码一共有128个，最长的ASCII字符串只有95个，所以hash数组开到128个足够用了；

2.滑动窗口法判断最长的子字符串:

​	(1)窗口的大小用于记录最长子字符串的大小；

​	(2)left指针表示窗口的左边，i表示窗口的右边，窗口长度为(i - left + 1)；

​	(3)hash数组用于存放该字符是否使用过；

​		Eg:hash[a] = 0,意味着hash[97] = 0,a字符在之前没有使用过；

​		Eg:hash[a] = 1,意味着a字符在字符串的第一个位置出现过一次；

​	(4)当hash[s[i]]没有使用过，或者hash[s[i]]使用过但是不在窗口内部，则可以将ans子字符串长度+1；

​	(5)字符串使用过而且在滑动窗口内部时，重新规划窗口，把之前的窗口丢弃，窗口左边界从重复字符后一个重新查找；

​		Eg:abbca当窗口走到第二个b时，将左边界设置为3，从第二个b之后找最长子字符串；

```c
int lengthOfLongestSubstring(char* s) {
    int hash[128] = {0}, left = 0, ans = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(hash[s[i]] == 0 || hash[s[i]] < left){
            ans = ans > i - left + 1 ? ans : i - left + 1;
        }else{
            left = hash[s[i]];
        }
        hash[s[i]] = i + 1;
    }
    return ans;
}
```

 二分查找答案

可以把这个题看成1110000问题

如果最长的字符串为3，那么就会找到字符串为2的窗口，所以我们可以二分答案，在二分中扫一遍字符串。

二分套判定

