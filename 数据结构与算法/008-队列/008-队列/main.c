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

#define MAXSIZE 10

typedef int QElemType;
typedef int Status;

typedef struct {
    int data[MAXSIZE];  // 存放数据的数组
    int front;          // 队首索引
    int rear;           // 队尾索引
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
Status enqueue(SqQueue *Q, QElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}

// 7.出队
Status dequeue(SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}

// 遍历
void queueTraverse(SqQueue Q) {
    
    int i = Q.front;
    while (i != Q.rear) {
        printf("%d  ", Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    SqQueue Q;
    QElemType e;
    
    if (initQueue(&Q)) {
        printf("初始化队列成功\n");
    }
    
    for (int i = 0; i < 10; i++) {
        enqueue(&Q, i);
    }
    printf("队列中的元素为:");
    queueTraverse(Q);
    printf("队列的长度为:%d\n", queueLength(Q));
    dequeue(&Q, &e);
    printf("获取出队元素:%d\n", e);
    printf("队列中的元素为:");
    queueTraverse(Q);
    getQueueHead(Q, &e);
    printf("获取队列头部:%d\n", e);
    printf("队列是否为空:%d\n", queueEmpey(Q));
    printf("清空队列\n");
    clearQueue(&Q);
    printf("队列是否为空:%d\n", queueEmpey(Q));
    printf("队列中的元素为:");
    queueTraverse(Q);
    printf("队列的长度为:%d\n", queueLength(Q));
    
    return 0;
}


//初始化队列成功
//队列中的元素为:0  1  2  3  4  5  6  7  8
//队列的长度为:9
//获取出队元素:0
//队列中的元素为:1  2  3  4  5  6  7  8
//获取队列头部:1
//队列是否为空:0
//清空队列
//队列是否为空:1
//队列中的元素为:
//队列的长度为:0
