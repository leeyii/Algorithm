//
//  main.c
//  去除重复字母
//
//  Created by leeyii on 2020/4/16.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE    10
#define ERROR   0
#define OK      1

typedef char SElemType;
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
    if (e)
    *e = s->data[s->top];
    s->top--;
    return OK;
}

int StackLength(Stack s) {
    return s.top + 1;
}


/*
 给你一个仅包含小写字母的字符串，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 */

char * removeDuplicateLetters(char * s){
    
    // 记录字符出现次数的数组
    int *letterAppearCount = (int *)malloc(sizeof(int) * 26);
    memset(letterAppearCount, 0, sizeof(int) * 26);
    // 记录字符是否在栈中的数组
    int *seen = (int *)malloc(sizeof(int) * 26);
    memset(seen, 0, 26 * sizeof(char));
    
    unsigned long length = strlen(s);
    
    for (int i = 0; i < length; i++) {
        letterAppearCount[s[i] - 'a']++;
        // printf("字符%c出现次数: %d\n", s[i], letterAppearCount[s[i] - 'a']);
    }
    
    char *stack = malloc(sizeof(char) * 27);
    int top = -1;
    
    for (int i = 0; i < length; i++) {
        char c = s[i];
        
        // 字符已经在栈中
        if (seen[c - 'a'] == 1) {
            // 当初字符的出现次数-1
            letterAppearCount[c - 'a']--;
            continue;
        }
        
        while (top != -1 &&
               stack[top] > c &&
               letterAppearCount[stack[top] - 'a'] > 1) {
            seen[stack[top] - 'a'] = 0;
            letterAppearCount[stack[top] - 'a']--;
            //printf("out %c, 剩余次数: %d\n", stack[top], letterAppearCount[stack[top] - 'a']);
            top--;
        }
        top++;
        stack[top] = c;
        seen[c - 'a'] = 1;
        //printf("in %c\n", c);
    }
    top++;
    stack[top] = '\0';
    //printf("result: %s\n", stack);
    return stack;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char *res = removeDuplicateLetters("edebbed");
    printf("%s\n", res);
    return 0;
}
