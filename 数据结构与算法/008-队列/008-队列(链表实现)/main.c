//
//  main.c
//  008-队列(链表实现)
//
//  Created by leeyii on 2020/4/13.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

typedef int QElemType;
typedef int Status;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, QNodePtr;

typedef struct {
    QNodePtr front;
    QNodePtr rear;
} LinkQueue;

// 1.初始化
Status initQueue(LinkQueue *Q) {
    Q->rear = Q->front = (QNodePtr)malloc(sizeof(QNode));
    if (Q->front == NULL) return ERROR;
    Q->front = NULL;
    return OK;
}

// 2.销毁队列
Status destoryQueue(LinkQueue *Q) {
    
    return OK;
}

// 3.清空队列
Status clearQueue(LinkQueue *Q) {
    
    
    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
