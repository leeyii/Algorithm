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
}QNode, *QNodePtr;

typedef struct {
    QNodePtr front;
    QNodePtr rear;
    int count;
} LinkQueue;

// 1.初始化
Status initQueue(LinkQueue *Q) {
    if (Q == NULL) return ERROR;
    // 初始化头结点
    Q->rear = Q->front = (QNodePtr)malloc(sizeof(QNode));
    if (Q->front == NULL) return ERROR;
    Q->front->next = NULL;
    Q->count = 0;
    return OK;
}

// 2.销毁队列
Status destoryQueue(LinkQueue *Q) {
    if (!Q) return ERROR;
    // 从头结点开始依次释放结点
    while (Q->front) {
        Q->rear = Q->front->next;
        Q->front = Q->front->next;
        free(Q->rear);
    }
    Q->count = 0;
    return OK;
}

// 3.清空队列
Status clearQueue(LinkQueue *Q) {
    if (!Q) return ERROR;
    // 保留头结点,释放其余结点
    QNodePtr p, q;
    // 指向首元结点
    p = Q->front->next;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    Q->front->next = NULL;
    Q->rear = Q->front;
    Q->count = 0;
    return OK;
}

// 4.队列是否为空
Status queueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

// 5.获取队列的长度
int queueLength(LinkQueue Q) {
    return Q.count;
}

// 6.获取队头
Status getQueueHead(LinkQueue Q, QElemType *e) {
    *e = Q.front->next->data;
    return OK;
}

// 7.入队
Status enqueue(LinkQueue *Q, QElemType e) {
    if (!Q) return ERROR;
    QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
    if (!p) return ERROR;
    p->next = NULL;
    p->data = e;
    Q->rear->next = p;
    Q->rear = p;
    Q->count++;
    return OK;
}

// 8.出队
Status dequeue(LinkQueue *Q, QElemType *e) {
    if (!Q) return ERROR;
    if (Q->count == 0) return ERROR;
    // 获取队头结点的值
    *e = Q->front->next->data;
    // 获取队头结点
    QNodePtr p = Q->front->next;
    Q->front->next = p->next;
    free(p);
    Q->count--;
    // 删空后,将队尾指向头结点
    if (Q->count == 0) Q->rear = Q->front;
    return OK;
}

// 9.遍历
void queueTraverse(LinkQueue Q) {
    
    QNodePtr p = Q.front->next;
    
    while (p) {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    LinkQueue q;
    int e;
    
    if (initQueue(&q)) {
        printf("队列初始化成功\n");
    }
    for (int i = 0; i < 10; i++) {
        enqueue(&q, i);
    }
    printf("队列中的元素为:");
    queueTraverse(q);
    printf("队列的长度为: %d\n", queueLength(q));
    printf("队列是否为空: %d\n", queueEmpty(q));
    dequeue(&q, &e);
    printf("出队元素为: %d\n", e);
    getQueueHead(q, &e);
    printf("获取队头: %d\n", e);
    printf("队列中的元素为:");
    queueTraverse(q);
    printf("队列的长度为: %d\n", queueLength(q));
    printf("队列是否为空: %d\n", queueEmpty(q));
    clearQueue(&q);
    printf("队列中的元素为:");
    queueTraverse(q);
    printf("队列的长度为: %d\n", queueLength(q));
    printf("队列是否为空: %d\n", queueEmpty(q));
    destoryQueue(&q);
    
    return 0;
}
