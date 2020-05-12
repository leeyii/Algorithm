#  字符串匹配（一）BF算法

**问题：** 有主串S = "abcacabdc", 模式串T = "abd", 请查找出模式串在主串第⼀次出现的位置; 提示: 主串和模式串均为⼩写字⺟且都是合法输⼊.


### 思路

1. 从左到右依次将主串S中的字符，与模式串T中的首个字符进行比较。
2. 如果在主串S中的第`i`个字符与模式串中的首个字符相等，在主串S从i个字符开始，依次和模式串T中的字符进行比较。
3. 如果每个字符都能够匹配，则`i`就是模式串在主串中第一次出现的位置。
4. 在主串和模式串比较过程中某个字符不相等，则从主串中`i+1`开始继续和模式串的首个字符进行比较。

例如主串S `abcacabdc`, 模式串T `abd`，从主串第一个字符开始比较：

	abcacabdc
	abd
	*

主串和模式串中首字符相同，依次将主串和模式串进行比较

	abcacabdc
	abd
	 *

主串和模式串中第二个字符也相同，继续往下进行比较

	abcacabdc
	abd
	  *

此时，主串和模式串中字符不相同，从下图位置开始比较：

	abcacabdc
	 abd
	 *

主串和模式串中首字符不相等，继续向后进行比较：

	abcacabdc
	  abd
	  *

重复上述步骤...

	abcacabdc
	     abd
	     *

此时，主串和模式串中的每个字符都可以匹配，则找到了匹配的位置。

### 代码

```c
int BF(char *s, char *p) {
    
    unsigned long mainLen = strlen(s);
    unsigned long patternLen = strlen(p);
    
    int start = -1;
    
    int isMach = 1;
    
    for (int i = 0; i < mainLen; i++) {
        char c = s[i];
        if (c == p[0]) {
            isMach = 1;
            // 主串中与模式串第一个字符匹配
            // 从这个位置开始对主串和模式串进行比对
            for (int j = 1; j < patternLen; j++) {
                // 主串字符
                char mc = s[i + j];
                // 模式串字符
                char pc = p[j];
                
                if (mc != pc) {
                    isMach = 0;
                    break;
                }
            }
            if (isMach == 1) {
                start = i;
                break;
            }
        }
    }
    
    return start;
}
```

时间复杂度：**O(m*m)**

空间复杂度：**O(1)**