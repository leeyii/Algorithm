//
//  main.c
//  Linear_list_c
//
//  Created by leeyii on 2017/9/6.
//  Copyright © 2017年 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node * Node;
struct Node {
    int     x;
    int     y;
};


typedef struct List * List;
struct List {
    Node    p; // 线性表地址
    int     length; // 当前长度
    int     size; // 容量
};


_Bool InitList(List *l, int len); ///< 创建线性表
_Bool DestoryList(List l); ///< 销毁线性表
_Bool ClearList(List l); ///< 清空线性表
_Bool ListEmpty(List l); ///< 线性表是否为空
int   ListLength(List l); ///< 线性表长度
void  GetElem(List l, int i, Node e); ///< 获取线性表中的指定位置的元素
void  PoiorElem(List l, Node cur_e, Node per_e); ///< 获取前驱元素
void  NextElem(List l, Node cur_e, Node next_e);///< 获取后继元素
_Bool ListInsert(List l, int i, Node e);
_Bool ListDelete(List l, int i);



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    List l;
    int length;
    
    InitList(&l, 5);
    
    length = ListLength(l);
    
    _Bool isEmpty = ListEmpty(l);
    
    Node e1 = NULL;
    
    GetElem(l, 0, e1);
    
    e1 = malloc(sizeof(Node));
    e1 -> x = 1;
    ListInsert(l, 0, e1);
    e1 -> x = 2;
    ListInsert(l, 0, e1);
    e1 -> x = 3;
    ListInsert(l, 0, e1);
    e1 -> x = 4;
    ListInsert(l, 0, e1);
    e1 -> x = 5;
    ListInsert(l, 0, e1);
    
    
//    DestoryList(l);
    
    
    return 0;
}


/**
 初始化线性表 如果成功返回1 失败返回0

 @param l 线性表指针
 @param len 线性表长度
 @return 初始化结果
 */
_Bool InitList(List *l, int len) {
    
    // 为线性表分配内存
    List tmp = (List)malloc(sizeof(List));
    // 如果分配失败 返回0;
    if (tmp == NULL) {
        return FALSE;
    }
    // 为线性表
    tmp -> p = calloc(len, sizeof(Node));
    tmp -> length = 0;
    tmp -> size = len;
    
    *l = tmp;
    return TRUE;
}

/**
 销毁线性表

 @param l 线性表指针 如果指针为空返回0
 @return 销毁结果
 */
_Bool DestoryList(List l) {
    if (l == NULL) {
        return FALSE;
    }
    free(l -> p);
    free(l);
    return TRUE;
}

/**
 清空线性表

 @param l 线性表指针
 @return 清空结果
 */
_Bool ClearList(List l) {
    if (l == NULL) {
        return FALSE;
    }
    l -> length = 0;
    return TRUE;
}

/**
 线性表是否为空

 @param l 线性表指针
 @return 返回结果
 */
_Bool ListEmpty(List l) {
    
    return (l -> length) == 0;
}

int   ListLength(List l) {
    
    return l -> length;
}

/**
 获取指定位置的元素

 @param l 线性表
 @param i 指定位置
 @param e 元素的指针,用于接受获得的元素  如果i
 */
void  GetElem(List l, int i, Node e) {
    
    //
    if (i < 0 || i > l -> length - 1) {
        e = NULL;
        return;
    }
    
    e = (l -> p) + i;
}


/**
 获取指定元素的前驱元素

 @param l 线性表的指针
 @param cur_e 指向目标元素的指针
 @param per_e 存放前驱元素的指针
 */
void  PoiorElem(List l, Node cur_e, Node per_e) {
    
    if (l -> p < cur_e && cur_e <= l -> p + (l -> length - 1)) {
        
        per_e = cur_e - 1;
        
        return;
    }
    per_e = NULL;
}

/**
 获取指定元素的后继元素

 @param l 线性表的指针
 @param cur_e 指向目标元素的指针
 @param next_e 存放后继元素的指针
 */
void  NextElem(List l, Node cur_e, Node next_e) {
    
    if (l -> p <= cur_e && cur_e < l -> p + (l -> length - 2)) {
        next_e = cur_e + 1;
        return;
    }
    next_e = 0;
}

/**
 插入元素

 @param l 线性表指针
 @param i 插入元素的位置
 @param e 插入的元素
 @return 插入元素是否成功
 */
_Bool ListInsert(List l, int i, Node e) {
    
    if (i < 1 || i > ListLength(l) + 1) {
        return FALSE;
    }
    if (l -> length >= l -> size) {
        Node new = realloc(l -> p, sizeof(Node) * (l -> size * 2));
        if (!new) return FALSE;
        l -> length *= 2;
        l -> p = new;
    }
    Node q = &(l -> p[i -1]); //q为插入位置
    for (Node p = &(l -> p[l -> length - 1]); p >= q; p--) {
        *(p + 1) = *p;
    }
    *q = *e;
    l -> length++;
    return TRUE;
}

/**
 删除指定位置元素

 @param l 线性表指针
 @param i 删除元素的位置
 @return 操作结果
 */
_Bool ListDelete(List l, int i) {
    
    if (i < 1 || i > l -> length) {
        return FALSE;
    }
    
    for (Node q = &(l -> p[i - 1]); q <= &(l -> p[l -> length - 1]); q++) {
        *q = *(q + 1);
    }
    l -> length --;
    return TRUE;
}
