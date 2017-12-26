//
//  main.c
//  线性链表
//
//  Created by leeyii on 2017/9/10.
//  Copyright © 2017年 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct ElemType {
    int x;
}ElemType;

// 存储结构 一个这样的结构体代表一个结点
typedef struct LNode {
    ElemType       *data; /// 数据域
    
    struct LNode   *next; /// 指针域 指向后继结点
}LNode, *LinkList;


void CreatList_L(LinkList *l, int n); // 创建线性表
int GetElem_L(LinkList l, int i, ElemType **data); // 获取指定位置的结点的 数据
int ListInsert_L()


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    LinkList l = NULL;
    
    CreatList_L(&l, 2);
    
    ElemType *e1 = NULL;
    ElemType *e2 = NULL;
    ElemType *e3 = NULL;
    int a = GetElem_L(l, 0, &e1);
    int b = GetElem_L(l, 1, &e2);
    int c = GetElem_L(l, 3, &e3);
    
    return 0;
}

/**
 创建链表

 @param l 指向链表头结点的指针的指针
 @param n 长度
 */
void CreatList_L(LinkList *l, int n) {
    
    LinkList head = (LinkList)malloc(sizeof(LNode));
    
    head -> next = NULL;
    
    LinkList p = NULL;
    
    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(LNode));
        p -> data = malloc(sizeof(ElemType));
        p -> data -> x = i;
        p -> next = head -> next;
        head -> next = p;
    }
    *l = head;
}

/**
 获取指定位置的数据

 @param l 带头结点的单链表的指针
 @param i index
 @param data 储存数据的指针
 @return 状态 0 链表不存在 或者 i 不合法, 1 返回元素成功
 */
int GetElem_L(LinkList l, int i, ElemType **data) {
    
    // 当第i个元素存在是返回1, 第i个元素不存在返回0
    LinkList p = l -> next;
    int j = 1;
    
    while (p && j < i) {
        p = p -> next;
        j++;
    }
    
    if (!p || j > i) return 0;
    
    *data = (p -> data);
    return 1;
}

