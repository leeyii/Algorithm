//
//  main.c
//  005-双向循环链表
//
//  Created by leeyii on 2020/4/6.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Element;
typedef int Status;

typedef struct Node {
    Element data;
    struct Node *next;
    struct Node *prior;
}Node, *LinkList;


// 创建双向链表
Status CreateList(LinkList *l) {
    
    // 创建头结点
    *l = (LinkList)malloc(sizeof(Node));
    if (*l == NULL) return ERROR;
    (*l)->next = *l;
    (*l)->prior = *l;
    
    // 尾结点指针
    Node *tail = *l;
    
    for (int i = 0; i < 10; i++) {
        // 创建新的结点
        Node *n = malloc(sizeof(Node));
        n->data = i;
        // 1. 尾结点的后继的前驱指向新建结点, 相当于头结点的前驱指向 n
        tail->next->prior = n; // (*l)->prior = n;
        // 2. 新建结点的后继指向尾结点的后继, 相当于n的后继指向 头结点
        n->next = tail->next; // n->next = (*l);
        // 3. 新建结点的前驱指向尾结点
        n->prior = tail;
        // 4. 尾结点的后置指向新建结点
        tail->next = n;
        // 5. 尾指针指向新建结点
        tail = n;
    }
    
    return OK;
}

//插入元素
Status ListInsert(LinkList *l, int index, Element e) {
    
    if (*l == NULL || index < 0) return ERROR;
    
    Node *p = (*l);
    // 寻找插入位置的前一个结点
    for (int i = 0; i < index; i++) {
        p = p->next;
        // 遍历一遍, 还没有到插入位置, 直接return
        if (p == *l) {
            printf("插入位置超过链表的长度\n");
            return ERROR;
        };
    }
    
    Node *n = malloc(sizeof(Node));
    if (!n) return ERROR;
    n->data = e;
    // 插入结点的后继指向插入结点前驱的后继
    n->next = p->next;
    // 插入结点后继的前驱指向插入结点
    p->next->prior = n;
    // 插入结点前驱的后继指向插入结点
    p->next = n;
    // 插入结点前驱指向p
    n->prior = p;
    
    return OK;
}


Status ListDelete(LinkList *l, int index, Element *e) {
    
    if (*l == NULL || index < 0) return ERROR;
    
    Node *p = *l;
    
    if (p->next == p) {
        printf("链表为空\n");
        return ERROR;
    }
    // 查找删除的元素
    for (int i = 0; i <= index; i++) {
        p = p->next;
        if (p == *l) {
            printf("删除位置超过链表长度\n");
            return ERROR;
        }
    }
    // 删除结点的前驱的后继指向删除结点的后继
    p->prior->next = p->next;
    // 删除结点的后继的前驱指向删除结点的前驱
    p->next->prior = p->prior;
    *e = p->data;
    // 释放删除结点内存
    free(p);
    return OK;
}


void ShowList(LinkList list) {
    
    if (!list || list->next == list) return;
    
    printf("链表的内容为:");
    
    Node *p = list->next;
    
    while (p != list) {
        printf(" %d", p->data);
        p = p->next;
    }
    
    printf("\n");
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Status iStatus;
    LinkList list;
    
    // 创建
    iStatus = CreateList(&list);
    
    ShowList(list);
    
    // 插入链表
//    ListInsert(&list, 11, 99);
//    ShowList(list);
//
//    ListInsert(&list, 9, 99);
//    ShowList(list);
//
//    ListInsert(&list, 11, 99);
//    ShowList(list);
//
//    ListInsert(&list, 13, 99);
//    ShowList(list);
    
    int a;
    // 删除
    ListDelete(&list, 9, &a);
    printf("%d\n", a);
    ShowList(list);
    
//    ListDelete(&list, 0, &a);
//    printf("%d\n", a);
//    ShowList(list);
//
//    ListDelete(&list, 0, &a);
//    printf("%d\n", a);
//    ShowList(list);
    
    
    return 0;
}
