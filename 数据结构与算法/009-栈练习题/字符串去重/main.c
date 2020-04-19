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
    
    char *letters = (char *)malloc(sizeof(char) * 26);
    memset(letters, 0, 26);
    
    unsigned long length = strlen(s);
    
    for (int i = 0; i < length; i++) {
        letters[s[i] - 'a'] =  letters[s[i] - 'a'] + 1;
    }
    
    Stack stack;
    InitStack(&stack);
    PushStack(&stack, s[0]);
    
    for (int i = 1; i < length; i++) {
        char c = s[i];
        char top;
        GetTop(stack, &top);
        if (c < top) {
            while (letters[top - 'a'] > 0 && StackLength(stack) != 0) {
                letters[top - 'a'] = letters[top - 'a'] - 1;
                PopStack(&stack, NULL);
            }
        }
        PushStack(&stack, c);
    }
    PushStack(&stack, '\0');
    return stack.data;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char *res = removeDuplicateLetters("bbccaa");
    printf("%s\n", res);
    return 0;
}
