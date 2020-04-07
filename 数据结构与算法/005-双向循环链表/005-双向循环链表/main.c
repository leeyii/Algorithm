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
    
    Node *p = (*l)->next;
    
    for (int i = 0; i < index; i++) {
        
    }
    
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
<<<<<<< HEAD
    
    Status iStatus;
    LinkList list;
    
    // 创建
    iStatus = CreateList(&list);
    
    ShowList(list);
    
    return 0;
=======
    return 0;//
>>>>>>> 920f213147ebc4706dae697995b8d16d34d24ae6
}
