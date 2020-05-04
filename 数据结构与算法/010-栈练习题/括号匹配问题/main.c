//
//  main.c
//  括号匹配问题
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
    *e = s->data[s->top];
    s->top--;
    return OK;
}

int StackLength(Stack s) {
    return s.top + 1;
}


/*
 括号匹配检验: (字节出现过的算法⾯试题/LeetCode)
 假设表达式中允许包含两种括号:圆括号与⽅括号,其嵌套顺序随意,即([]()) 或者[([][])]都是正 确的.⽽这[(]或者(()])或者([()) 都是不正确的格式. 检验括号是否匹配的⽅法可⽤”期待的急迫 程度"这个概念来描述.例如,考虑以下括号的判断: [ ( [ ] [ ] ) ]
 */
int checkMatchingBrackets(char * S){

    // 获取字符串长度
    unsigned long length = strlen(S);
    
    // 初始化栈
    Stack stack;
    InitStack(&stack);
    
    PushStack(&stack, S[0]);
    // 1.如果是左括号 入栈
    // 2.如果是右括号, 取栈顶元素, 如果括号可以匹配, 将栈顶元素出栈, 继续循环. 如果不配直接return.
   
    for (int i = 1; i < length; i++) {
        char c = S[i];
        switch (c) {
            case ']':
            {
                char top;
                GetTop(stack, &top);
                if (top == '[') {
                    PopStack(&stack, &top);
                    break;
                } else {
                    return -1;
                }
            }
            case '}':
            {
                char top;
                GetTop(stack, &top);
                if (top == '{') {
                    PopStack(&stack, &top);
                    break;
                } else {
                    return -1;
                }
            }
            case ')':
            {
                char top;
                GetTop(stack, &top);
                if (top == '(') {
                    PopStack(&stack, &top);
                    break;
                } else {
                    return -1;
                }
            }
            default:
                PushStack(&stack, c);
                break;
        }
    }
    
    if (StackLength(stack) == 0) {
        DestoryStack(&stack);
        return 0;
    } else {
        DestoryStack(&stack);
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char *str = "([())";
    
    if (checkMatchingBrackets(str) == 0) {
        printf("match\n");
    } else {
        printf("false\n");
    }
    
    printf("Hello, World!\n");
    return 0;
}
