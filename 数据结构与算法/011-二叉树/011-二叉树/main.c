//
//  main.c
//  011-二叉树
//
//  Created by leeyii on 2020/4/27.
//  Copyright © 2020 leeyii. All rights reserved.
//  二叉树顺序存储

#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40

#define Nil 0

typedef int Status;
typedef int CElemType;
typedef CElemType SqBiTree[MAXSIZE];

// 1. 初始化二叉树
Status InitBiTree(SqBiTree T) {
    
    for (int i = 0; i++; i < MAXSIZE) {
        T[i] = Nil;
        
    }
    
    return OK;
}

Status BiTreeIsEmpty(SqBiTree T) {
    if (T[0] == Nil) return TRUE;
    return FALSE;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
