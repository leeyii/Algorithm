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
    Element* data;
    int top;
    int maxSize;
}SqStack, *SqStackP;

/// 顺序表的初始化
Status initStack(SqStackP s) {
    
    s->data = (Element *)malloc(sizeof(Element)*SIZE);
    if (s->data == NULL) return ERROR;
    // 初始栈顶索引
    s->top = -1;
    // 栈的最大容量, 用于扩容.
    s->maxSize = SIZE;
    return OK;
}

/// 清空栈
Status clearStack(SqStackP s) {
    // 将栈顶索引置为-1
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

/// 获取栈的长度
int stackLength(SqStack s) {
    return s.top + 1;
}

/// 获取栈顶元素
Status getStackTop(SqStack s, Element *e) {
    // 如果是空栈 return
    if (s.top == -1) return ERROR;
    *e = s.data[s.top];
    return OK;
}

/// 入栈
Status push(SqStackP s, Element e) {
    
    // 如果顺序栈容量达到最大值
    if (s->top == (s->maxSize - 1)) {
        // 扩容
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

/// 销毁栈
Status destoryStack(SqStackP s) {
    // 释放数组的空间
    free(s->data);
    
    s->top = -1;
    s->maxSize = 0;
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
    
    if (initStack(&stack)) {
        printf("顺序栈初始化成功\n");
    } else {
        printf("顺序栈初始化失败\n");
    }
    
    for (int i = 0; i < 20; i++) {
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
    printf("清空栈\n");
    clearStack(&stack);
    printf("是否已经清空栈 %d, 栈长度为:%d\n",stackIsEmpty(stack), stackLength(stack));
    
    if (destoryStack(&stack)) {
        printf("栈销毁成功\n");
    }
    
    return 0;
}
