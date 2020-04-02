//
//  main.c
//  002-单链表
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


/// 初始化链表
/// @param l 链表
Status InitList(LinkList *l) {
    // 初始化头结点
    *l = malloc(sizeof(Node));
    // 初始化失败
    if (*l == NULL) return ERROR;
    // 将头结点指针域置空
    (*l)->next = NULL;
    return OK;
}

/// 插入链表
/// @param l 链表
/// @param i 插入位置
/// @param e 插入元素
Status ListInsert(LinkList *l, int i, Element e) {
    
    LinkList p = *l;
    int j = 0;
    
    // 1.寻找i-1个结点
    while (p && j < i) {
        j++;
        p = p->next;
    }
    
    if (!p || j > i) return ERROR;
    
    // 创建新的结点
    Node *node = malloc(sizeof(Node));
    node->data = e;
    // 新节点的next 指向p的next
    node->next = p->next;
    // p的next 指向新节点
    p->next = node;
    return OK;
}


/// 获取链表指定位置的元素
/// @param l 链表
/// @param i index
/// @param e 用来接收元素值得指针
Status GetElement(LinkList l, int i, Element *e) {
    
    if (!l || i < 0) return ERROR;

    // 指向首元结点
    Node *n = l->next;
    
    int j = 0;
    // 查找结点i
    while (n && j < i) {
        j++;
        n = n->next;
    }
    // 不存在结点i
    if (!n) return ERROR;
    
    *e = n->data;
    
    return OK;
}

Status ListDelete(LinkList *l, int i) {
    
    if (!(*l) || i < 0) return ERROR;
    
    Node *p = (*l);
    
    int j = 0;
    
    while (p && j < i) {
        p = p->next;
        j++;
    }
    
    if (!p || !(p->next)) return ERROR;
    
    Node *temp = p->next;
    p->next = temp->next;
    free(temp);
    
    return OK;
}


void printList(LinkList l) {
    
    Node *p = l->next;
    
    while (p) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Status iStatus;
    
    LinkList list;
    
    Element e;
    
    iStatus = InitList(&list);
    
    iStatus = ListInsert(&list, 0, 1);
    
    iStatus = ListInsert(&list, 0, 2);
    
    iStatus = ListInsert(&list, 1, 3);
    
    iStatus = ListInsert(&list, 3, 10);
    
    printList(list);
    
    iStatus = GetElement(list, 0, &e);
    
    printf("%d\n", e);
    
    iStatus = ListDelete(&list, 5);
    
    printList(list);
    
    
    return 0;
}
