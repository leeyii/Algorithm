//
//  main.c
//  004--双向链表
//
//  Created by leeyii on 2020/4/5.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR   0;
#define OK      1;

typedef int Element;
typedef int Status;

typedef struct Node{
    Element data;       // 数据域
    struct Node *prior; // 前驱
    struct Node *next;  // 后继
    
} Node, *LinkList;


Status CreateLinkList(LinkList *l) {
    
    if (*l) return ERROR;
    
    // 正在被创建节点的指针
    Node *p = NULL;
    // 指向尾结点的指针
    Node *tail = NULL;
    
    // 1. 创建头结点
    Node *head = (LinkList)malloc(sizeof(Node));
    if (head == NULL) return ERROR;
    head->prior = NULL;
    head->next = NULL;
    head->data = -1;
    *l = head;
    tail = head;

    printf("依次输入创建双向链表的元素,0结束输入\n");
    int a;
    while (1) {
        scanf("%d", &a);
        if (a == 0) break;
        p = (LinkList)malloc(sizeof(Node));
        if (!p) return ERROR;
        p->data = a;
        p->prior = tail;
        p->next = NULL;
        
        tail->next = p;
        tail = p;
    }
    
    return OK;
}

void ShowList(LinkList l) {
    
    if (l == NULL || l->next == NULL) {
        printf("链表为空\n");
        return;
    }
    
    Node *p = l->next;
    printf("print link list: ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    
    printf("\n");
}

Status ListInsert(LinkList *l, int index, Element e) {
    
    if (*l == NULL || index < 0) return ERROR;
    
    Node *p = *l, *node = NULL;
    
    // 1. 寻找插入位置的前一个节点
    for (int i = 0; i < index; i++) {
        p = p -> next;
        if (p == NULL) {
            printf("插入位置大于链表长度\n");
            return ERROR;
        }
    }
    
    // 2. 创建插入节点
    node = (LinkList)malloc(sizeof(node));
    if (!node) return ERROR;
    node->data = e;
    node->prior = NULL;
    node->next = NULL;
    
    // 3. 插入节点
    
    // 插入位置在不是一个节点
    if (p->next != NULL) {
        // 建立插入节点和后继节点之间的关系
        node->next = p->next;
        p->next->prior = node;
    }
    // 建立插入节点和前驱节点之间的关系
    p->next = node;
    node->prior = p;
    
    return OK;
}

Status ListDelete(LinkList *l, int index, Element *e) {
    
    if (*l == NULL || index < 0) return ERROR;
    
    Node *p = *l;
    
    if (p->next == NULL) {
        printf("要删除的链表为空\n");
        return ERROR;
    }
    
    // 1.寻找要删除节点
    for (int i = 0; i <= index; i++) {
        p = p->next;
        if (!p) {
            // 删除位置不合法
            printf("删除位置大于链表长度\n");
            return ERROR;
        }
    }
    
    if (p->next == NULL) {
        p->prior->next = NULL;
    } else {
        p->prior->next = p->next;
        p->next->prior = p->prior;
    }
    *e = p->data;
    free(p);
    
    return ERROR;
}

Status ListDeleteValue(LinkList *l, Element e) {
    
    if (*l == NULL) return ERROR;
    
    Node *p = (*l)->next;
    
    while (p && p->data != e) {
        p = p->next;
    }
    
    if (!p) {
        printf("没有找到查到要删除的元素");
        return ERROR;
    }
    
    if (p->next == NULL) {
        p->prior->next = NULL;
    } else {
        p->prior->next = p->next;
        p->next->prior = p->prior;
    }
    free(p);
    
    return OK;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    LinkList list = NULL;
    
    Status iStatus;
    Element e;
    
    iStatus = CreateLinkList(&list);
    
    if (iStatus) {
        printf("链表创建成功\n");
    } else {
        printf("链表创建失败\n");
    }
    
    ShowList(list);
    
//    iStatus = ListInsert(&list, 6, 99);
//    ShowList(list);
    
    
//    iStatus = ListDelete(&list, 2, &e);
//    printf("删除的元素为: %d\n", e);
//    ShowList(list);
    
    iStatus = ListDeleteValue(&list, 3);
    
    ShowList(list);
    
    return 0;
}
