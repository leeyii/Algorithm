//
//  main.c
//  007-栈
//
//  Created by leeyii on 2020/4/12.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

#define SIZE 10

typedef int Status;
typedef int Element;

typedef struct {
    int* data;
    int top;
    int maxSize;
}SqStack, *SqStackP;

/// 顺序表的初始化
Status initStack(SqStackP s) {
    
    s->data = (Element *)malloc(sizeof(Element)*SIZE);
    if (s->data == NULL) return ERROR;
    s->top = -1;
    s->maxSize = SIZE;
    return OK;
}

/// 清空栈
Status clearStack(SqStackP s) {
    s->top = -1;
    return OK;
}

/// 判断栈是否为空
Status stackIsEmpty(SqStack s) {
    if (s.top == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/// 判断栈的长度

Status stackLength(SqStack s) {
    return s.top + 1;
}

/// 获取栈顶元素
Status getStackTop(SqStack s, Element *e) {
    
    if (s.top == -1) return ERROR;
    *e = s.data[s.top];
    return OK;
}

/// 入栈
Status push(SqStackP s, Element e) {
    
    if (s->top == (s->maxSize - 1)) {
        // 栈满了
        s->data = realloc(s->data, (s->maxSize + SIZE));
        if (s->data == NULL) return ERROR;
        s->maxSize += SIZE;
    }
    
    s->data[s->top + 1] = e;
    s->top++;
    return OK;
}

/// 出栈
Status pop(SqStackP s, Element *e) {
    if (s->top == -1) return ERROR;
    *e = s->data[s->top];
    s->top--;
    return OK;
}

/// 从栈低到栈顶遍历
void stackTraverse(SqStack s) {
    if (stackIsEmpty(s)) return;
    
    for (int i = 0; i <= s.top; i++) {
        printf("%d  ", s.data[i]);
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    SqStack stack;
    int e;
    
    initStack(&stack);
    
    for (int i = 0; i < 10; i++) {
        push(&stack, i);
    }
    printf("顺序栈中元素为:\n");
    stackTraverse(stack);
    
    pop(&stack, &e);
    printf("栈顶弹出元素为:%d\n", e);
    stackTraverse(stack);
    
    getStackTop(stack, &e);
    printf("栈顶元素为:%d\n", e);
    stackTraverse(stack);
    printf("是否为空栈:%d\n",stackIsEmpty(stack));
    printf("栈的长度为:%d\n", stackLength(stack));
    clearStack(&stack);
    printf("是否已经清空栈 %d, 栈长度为:%d\n",stackIsEmpty(stack), stackLength(stack));
    
    
    return 0;
}
