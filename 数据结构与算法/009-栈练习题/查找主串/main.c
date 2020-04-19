//
//  main.c
//  查找主串
//
//  Created by leeyii on 2020/4/18.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 有主串S = "abcacabdc", 模式串T = "abd", 请查找出模式串在主串第⼀次出现的位置; 提 示: 主串和模式串均为⼩写字⺟且都是合法输⼊.
 */

int findMainString(char *s, char *pattern) {
    
    unsigned long mainLen = strlen(s);
    unsigned long patternLen = strlen(pattern);
    
    int start = -1;
    
    int isMach = 1;
    
    for (int i = 0; i < mainLen; i++) {
        char c = s[i];
        if (c == pattern[0]) {
            isMach = 1;
            // 主串中与模式串第一个字符匹配
            // 从这个位置开始对主串和模式串进行比对
            for (int j = 1; j < patternLen; j++) {
                // 主串字符
                char mc = s[i + j];
                // 模式串字符
                char pc = pattern[j];
                
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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int start = findMainString("abcacabdc", "ca");
    
    printf("%d\n", start);
    
    return 0;
}
