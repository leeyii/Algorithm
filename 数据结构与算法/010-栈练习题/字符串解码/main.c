//
//  main.c
//  字符串解码
//
//  Created by leeyii on 2020/4/17.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackData {
    char *repeat;
    char *content;
}StackData;

#define SIZE    10
#define ERROR   0
#define OK      1

typedef StackData SElemType;
typedef int Status;

typedef struct Stack {
    SElemType *data;
    int top;
    int maxSize;
}Stack;

Status InitStack(Stack *s) {
    if (!s) return ERROR;
    s->data = (SElemType *)malloc(sizeof(SElemType)*SIZE);
    if (s->data == NULL) return ERROR;
    s->maxSize = SIZE;
    s->top = -1;
    return OK;
}

Status DestoryStack(Stack *s) {
    if (!s) return ERROR;
    free(s->data);
    s->maxSize = 0;
    s->top = -1;
    return OK;
}

Status ClearStack(Stack *s) {
    if (!s) return ERROR;
    s->top = -1;
    return OK;
}

Status GetTop(Stack s, SElemType *e) {
    
    if (s.top == -1) return ERROR;
    *e = s.data[s.top];
    return OK;
}

Status PushStack(Stack *s, SElemType e) {
    if (!s) return ERROR;
    if (s->top == s->maxSize - 1) {
        s->data = (SElemType *)realloc(s->data, sizeof(SElemType) * (s->maxSize + SIZE));
        if (!s->data) return ERROR;
        s->maxSize += SIZE;
    }
    s->top++;
    s->data[s->top] = e;
    return OK;
}

Status PopStack(Stack *s, SElemType *e) {
    if (!s) return ERROR;
    *e = s->data[s->top];
    s->top--;
    return OK;
}

int StackLength(Stack s) {
    return s.top + 1;
}

/*
 字符串编码(LeetCode-中等) 给定⼀个经过编码的字符串，返回它解码后的字符串。 编码规则为: k[encoded_string]，表示其中⽅括号内部的 encoded_string 正好重复 k 次。 注意 k 保证为正整数。你可以认为输⼊字符串总是有效的；输⼊字符串中没有额外的空格， 且输⼊的⽅括号总是符合格式要求的。此外，你可以认为原始数据不包含数字，所有的数字只 表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输⼊。 例如: s = "12[a]2[bc]", 返回 "aaabcbc". s = "3[a2[c]]", 返回 "accaccacc". s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
 */

char * stringEncoding(char *s) {
    
    unsigned long length = strlen(s);
    
    for (int i = 0; i < length; i++) {
        char c = s[i];
        switch (c) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                break;
            case '[':
                break;
            case ']':
                break;
            default:
                break;
        }
    }
    
    return "";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
