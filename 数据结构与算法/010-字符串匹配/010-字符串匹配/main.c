//
//  main.c
//  010-字符串匹配
//
//  Created by leeyii on 2020/4/20.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
 暴风算法:
 */
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

/// 计算字符串的hash值
/// @param s 字符串
/// @param length 字符串长度
int hashValue(char *s, int length) {
    
    int hashValue = 0;
    // 进制
    int d = 26;
    
    for (int i = 0; i < length; i++) {
        hashValue = hashValue * d + (s[i] - 'a' + 1);
    }
    return hashValue;
}

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

int KMP(char *s, char *p) {
    
    unsigned long n = strlen(s);
    unsigned long m = strlen(p);
    
    int *next = (int *)malloc(sizeof(int) * m);
    
    next[0] = -1;
    
    //abceabcd
    //00001200
    // c c a
    //-1 1 0
    
    // 推到 next 数组
    int j = 0;
    int k = -1;
    while (j < m) {
        if (k == -1 || p[j] == p[k]) {
            k++;
            j++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
    
    int i = 0;
    j = 0;
    while (i < n) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
            if (j >= m) return (int)(i - m);
        } else {
            j = next[j];
        }
    }
    
    return -1;
}

// 优化KMP算法

int * getNextVal(char *p, int size) {
    int *nextVal = (int *)malloc(sizeof(int) * size);
    nextVal[0] = -1;
    
    int i = 0;
    int j = -1;
    while (i < size) {
        if (j == -1 || p[i] == p[j]) {
            i++;
            j++;
            if (p[i] == p[j]) {
                nextVal[i] = nextVal[j];
            } else {
                nextVal[i] = j;
            }
            
        } else
            j = nextVal[j];
    }
    
    return nextVal;
}

int KMP1(char *s, char *p) {
    unsigned long n = strlen(s);
    unsigned long m = strlen(p);
    
    int *next = getNextVal(p, (int)m);
    
    int i = 0;
    int j = 0;
    while (i < n) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
            if (j >= m) return (int)(i - m);
        } else {
            j = next[j];
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    int index = KMP1("", "ccc");
    
    int index = BF("abcacabdc", "abd");
    
    printf("index: %d\n", index);
    
    return 0;
}
