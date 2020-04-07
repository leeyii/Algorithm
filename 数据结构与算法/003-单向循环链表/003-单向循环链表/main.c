//
//  main.c
//  003-单向循环链表
//
//  Created by leeyii on 2020/4/2.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define MAX_SIZE 10

typedef int Element;
typedef int Status;

// 数据结构的定义
typedef struct Node {
    Element data;
    struct Node *next;
}Node;

typedef struct Node * LinkList;

/*
 创建循环列表
 1.
 */
/// 创建循环列表
Status CreateList1(LinkList *l) {
    
    
    int a;
    Node *target, *temp = NULL;
    
    printf("输入节点的值,输入0结束.\n");
    
    while (1) {
        
        scanf("%d", &a);
        
        if (a == 0) break;
        //
        if (*l == NULL) {
            *l = malloc(sizeof(Node));
            if (*l == NULL) return ERROR;
            (*l)->data = a;
            (*l)->next = *l;
        } else {
            //查找尾结点
            for (target = *l; target->next != *l; target = target->next);
            temp = malloc(sizeof(Node));
            temp->data = a;
            temp->next = target->next;
            target->next = temp;
        }
    }
    
    return OK;
}

Status CreateList2(LinkList *l) {
    
    int a;
    Node *tail = NULL, *temp = NULL;
    
    printf("输入节点的值,输入0结束.\n");
    
    while (1) {
        
        scanf("%d", &a);
        
        if (a == 0) break;
        
        if (*l == NULL) {
            tail = malloc(sizeof(Node));
            if (!tail) return ERROR;
            tail->data = a;
            tail->next = tail;
            *l = tail;
        } else {
            temp = malloc(sizeof(Node));
            temp->data = a;
            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
        }
    }
    
    return OK;
}

Status ListInsert(LinkList *l, int i, Element e) {
    
    if (*l == NULL || i < 0) return ERROR;
    
    Node *p = NULL;
    Node *target = NULL;
    int j;
    
    if (i == 0) {
        // 如果插入位置是一个,需要特殊处理.
        
        // 1.创建需要插入的节点
        // 2.找到tail节点
        // 3.将tail->next 指向 插入的节点
        // 4.将查入节点的next 指向 首元结点
        // 5.将首元节点指针指向插入的节点
        
        // 1
        p = malloc(sizeof(Node));
        if (!p) return ERROR;
        p->data = e;
        // 2
        for (target = *l; target->next != *l; target = target->next);
        // 3
        target->next = p;
        // 4
        p->next = *l;
        // 5
        *l = p;
    } else {
        // 其他位置插入
        
        // 1.找到i-1的节点, 如果超过链表的长度, 则插入到尾部
        // 2.创建新的节点
        // 3.新节点的next指向 i-1节点的next
        // 4.i-1节点的next指向新节点
        
        // 1
        for (j = 0,  target = *l; target->next != *l && j != i - 1; target = target->next, j++);
        // 2
        p = malloc(sizeof(Node));
        if (!p) return ERROR;
        p->data = e;
        // 3
        p->next = target->next;
        // 4
        target->next = p;
    }
    
    return OK;
}



Status ListDelete(LinkList *l, int i) {
    
    // 循环链表删除也要考虑两种情况
    // 1. 删除节点是首元节点
    // 2. 删除节点非首元节点
    
    if (*l == NULL || i < 0) return ERROR;
    
    Node *temp, *target = NULL;
    int j;
    
    if (i == 0) {
        
        // 如果只剩下首元节点
        if ((*l)->next == *l) {
            free(*l);
            *l = NULL;
            return OK;
        }
        
        // 1.找到尾结点
        // 2.保存首元节点 为了释放内存
        // 3.将尾结点的next指向首元节点的next;
        // 4.将首元节点的指针指向首元节点的next
        // 5.释放首元节点
        
        // 1
        for (target = *l; target->next != *l; target = target->next);
        // 2
        temp = *l;
        // 3
        target->next = temp->next;
        // 4
        *l = temp->next;
        // 5
        free(temp);
    } else {
        
        // 1. 找到删除节点的前一个节点 target
        // 2. target->next 指向 删除节点的next
        // 3. 释放删除的节点
        
        // 1
        for (target = *l, j = 0; target->next != target && j != i - 1; target = target->next, j++) {
            temp = target->next;
            // 2
            target->next = temp->next;
            // 3
            free(temp);
        }
    }
    
    return OK;
}

int FindValue(LinkList l, int value) {
    
    if (l == NULL) return -1;
    
    int i = 0;
    Node * p = l;
    
    // 遍历链表
    while (p->data != value && p->next != l) {
        i++;
        p = p->next;
    }
    
    if (p->data == value) {
        return i;
    }
    
    return -1;
}

void PrintList(LinkList l) {
    
    if (l == NULL) return;
    
    LinkList temp = l;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != l);
}

int main(int argc, const char * argv[]) {
    
    LinkList l1;
    Status iStatus;
    
    iStatus = CreateList2(&l1);
    
    printf("原始链表:\n");
    PrintList(l1);
    
//    iStatus = ListInsert(&l1, 6, 99);
//
//    PrintList(l1);
    
    
    int i = FindValue(l1, 3);
    
    printf("查找的值在: %d\n", i);
    
    return 0;
}
