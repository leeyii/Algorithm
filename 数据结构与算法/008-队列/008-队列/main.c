//
//  main.c
//  008-队列
//
//  Created by leeyii on 2020/4/13.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>

#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

#define MAXSIZE 5

typedef int QElemType;
typedef int Status;

typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

// 1.初始队列
Status initQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

// 2.队列清空
Status clearQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

// 3.队列是否为空
Status queueEmpey(SqQueue Q) {
    return Q.rear == Q.front;
}

// 4.队列的长度
int queueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// 5.获取队列的头部
Status getQueueHead(SqQueue Q, QElemType *e) {
    if (Q.rear == Q.front) return ERROR;
    *e = Q.data[Q.front];
    return OK;
}

// 6.入队
Status inQueue(SqQueue *Q, QElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) return ERROR;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    Q->data[Q->rear];
    return OK
}

// 7.出队
Status outQueue(SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}

// 遍历
Status queueTraverse(SqQueue Q) {
    
    int i = Q.front;
    
    while ((i + 1) % MAXSIZE != Q.front) {
        printf("%d  ", Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    SqQueue Q;
    
    printf("初始化队列\n");
    initQueue(&Q);
    
    for (int i = 0; i < 12; i++) {
        inQueue(&Q, i);
    }
    
    return 0;
}
