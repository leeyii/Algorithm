# RK算法

### 思路

RK算法的核心思路是：将模式串通过hash算法转换数字，然后将主串拆分成一个个子串，将子串用相同的hash算法转换成数字，然后一一进行比较。

要实现RK算法，首先需要解决一个问题，就是hash算法的设计，如何将一个字符串转换成数字，且尽量减少hash碰撞。

首先我们先来思考数字`127`是怎么计算得到的，很显然 $$127 = 1*10^2 + 2*10^1 + 7$$

通过上面公式，数字的计算是由每位上的数字`p`, 进制`d`, 第`i`位， `p * d^(i-1)`, 相加得到的。

如果我们要讲字符串转换成数字，我们需要解决两个问题:

1. 字符到数组的转换
2. 进制

我们先来解决第一个问题，我们可以通过字符的ASCII码将字符转换成对应的数字，例如`a`字符的ASCII码是`97`，需要注意的是题目中，字符串是由小写字符组成的，因此我们可以将字符`a`对应的数字转换成`1`，那么小写字母`char`到数字的转换公式就是: `char - 'a' + 1`, 字符`char`的ASCII码减字符`'a'`的ASCII码加1。

接着我们继续来解决第二个问题，小写字母是由26个字母组成的因此进制`d`就是26。

那么`abc`对应的 hash 值就是`'abc' = 1 * 26^2 + 2 * 26^1 + 3 * 26^0`。

例如：主串S = "abcacabdc", 模式串T = "abd"， 主串的长度为`n`, 模式串的长度为 `m`, 可以将主串拆分为`n - m`个子串，依次将模式串和每个子串的hash值进行对比。

计算一个字符串的hash值的代码实现：

```c
char *s = "abc";

int length = strlen(s);

int hashValue = 0;
// 进制
int d = 26;
    
for (int i = 0; i < length; i++) {
	hashValue = hashValue * d + (s[i] - 'a' + 1);
}
```

#### hash碰撞处理

两个相同的字符串生产的hash值一定是相等的，两个字符串生产的hash值相等，但是两个字符串不一定相等，如果两个不同的字符串生产相同的hash值，那么就称为hash碰撞。

要解决上面算法中hash碰撞的问题，其实非常简单，当子串和hash值和主串中的hash值相同时，我们在进行一次原始字符串的对比就可以了。

#### 子串的hash值计算

在进行子串和模式串进行对比时，我们可以先将模式串和主串中第一个子串的hash值计算出来，我们先计算出模式串T `abd`， 和子串 `abc` 的hash值，对比他们的hash值，他们的hash值不等，接着我们需要计算下一个子串`bca`的hash值。

这里我们可以使用一个小技巧利用上一个子串的hash值来计算下一个子串的hash值。

以数字`1278`为例， 我们如何可以通过`127`来计算`278`的值呢， 公式如下：$ (127 - 1 * 10^2) * 10 + 8 $

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
### 代码

```c
// 反向验证
int isMach(char *s, char *p, unsigned long m, int pos) {
    for (int i = 0; i < m; i++) {
        if (s[pos + i] != p[i]) return 0;
    }
    return 1;
}

int RK(char *s, char *p) {
    
    // 主串长度
    unsigned long n = strlen(s);
    // 模式串长度
    unsigned long m = strlen(p);
    
    /*
     hash算法:
     可以由:
     678 = 6 * 10^2 + 7 * 10^1 + 8 * 10^0
     推导出
     字符串的hash算法
     字符的ASCII码减去字符a的ASCII码加一
     这里如果不加一的, abc 和 bc 的值是一样的会产生hash碰撞
     'abc' = 1 * 26^2 + 2 * 26^1 + 3 * 26^0
     */
    
    // 主串的子串的hash值
    unsigned long sHash = 0;
    // 模式串的hash值
    unsigned long pHash = 0;
    
    // 26进制
    int d = 26;
    
    for (int i = 0; i < m; i++) {
        sHash = sHash * d + (s[i] - 'a' + 1);
        pHash = pHash * d + (p[i] - 'a' + 1);
    }
    
    unsigned long maxValue = pow(d, m - 1);
    
    for (int i = 0; i < n - m + 1; i++) {
        if (sHash == pHash) {
            if (isMach(s, p, m, i)) return i;
        }
        sHash = (sHash - (s[i] - 'a' + 1) * maxValue) * d + (s[i + m] - 'a' + 1);
    }
    
    return -1;
}
```