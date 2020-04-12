//
//  main.c
//  栈的链表实现
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

typedef int Status;
typedef int Element;

typedef struct StackNode {
    Element data;
    struct StackNode *next;
}StackNode, *StackNodeP;

typedef struct LinkStack {
    StackNodeP top;
    int length;
}LinkStack;

/// 初始化
Status initStack(LinkStack *s) {
    
    s->top = NULL;
    s->length = 0;
    return  OK;
}

/// 清空栈
Status clearStack(LinkStack *s) {
    
    StackNodeP p, temp;
    
    p = s->top;
    while (p) {
        temp = p;
        p = p->next;
        free(temp);
    }
    s->length = 0;
    return OK;
}

/// 判断栈是否为空
Status stackIsEmpty(LinkStack s) {
    if (s.length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/// 判断栈的长度

Status stackLength(LinkStack s) {
    return s.length;
}

/// 获取栈顶元素
Status getStackTop(LinkStack s, Element *e) {
    if (s.top == NULL) return ERROR;
    *e = s.top->data;
    return OK;
}

/// 入栈
Status push(LinkStack *s, Element e) {
    
    StackNodeP n = malloc(sizeof(StackNode));
    if (n == NULL) return ERROR;
    n->data = e;
    n->next = s->top;
    s->top = n;
    s->length++;
    return OK;
}

/// 出栈
Status pop(LinkStack *s, Element *e) {
    
    if (s->top == NULL) return ERROR;
    StackNodeP n = s->top;
    s->top = s->top->next;
    *e = n->data;
    free(n);
    s->length--;
    return OK;
}

/// 遍历
void stackTraverse(LinkStack s) {
    
    StackNodeP p = s.top;
    
    while (p) {
        printf("%d  ", p->data);
        p = p->next;
    }
    
    printf("\n");
}


int main(int argc, const char * argv[]) {
    // insert code here...
    LinkStack stack;
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
