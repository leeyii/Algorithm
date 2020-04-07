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
        Node *n = malloc(sizeof(Node));
        n->data = i;
        
        
        tail->next->prior = n;
        n->next = tail->next;
        
        n->prior = tail;
        tail->next = n;
        
        tail = n;
    }
    
    return OK;
}

//插入元素
Status ListInsert(LinkList *l, int index, Element e) {
    
    if (*l == NULL || index < 0) return ERROR;
    
    Node *p = (*l);
    
    for (int i = 0; i < index; i++) {
        p = p->next;
        if (p == *l) {
            printf("插入位置超过链表的长度\n");
            return ERROR;
        };
    }
    
    Node *n = malloc(sizeof(Node));
    if (!n) return ERROR;
    n->data = e;
    
    n->next = p->next;
    p->next->prior = n;
    
    p->next = n;
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
    
    for (int i = 0; i <= index; i++) {
        p = p->next;
        if (p == *l) {
            printf("删除位置超过链表长度\n");
            return ERROR;
        }
    }
    
    p->prior->next = p->next;
    p->next->prior = p->prior;
    *e = p->data;
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
