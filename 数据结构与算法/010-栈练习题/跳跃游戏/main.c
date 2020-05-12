//
//  main.c
//  跳跃游戏
//
//  Created by leeyii on 2020/4/17.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE    10
#define ERROR   0
#define OK      1

typedef int SElemType;
typedef int Status;

typedef struct Stack {
    SElemType *data;
    int top;
    int maxSize;
}Stack;

Status InitStack(Stack *s) {
    if (!s) return ERROR;
    s->data = (SElemType *)malloc(sizeof(SElemType)*SIZE);
    if (s->data == NULL) return ERROR;
    s->maxSize = SIZE;
    s->top = -1;
    return OK;
}

Status DestoryStack(Stack *s) {
    if (!s) return ERROR;
    free(s->data);
    s->maxSize = 0;
    s->top = -1;
    return OK;
}

Status ClearStack(Stack *s) {
    if (!s) return ERROR;
    s->top = -1;
    return OK;
}

Status GetTop(Stack s, SElemType *e) {
    
    if (s.top == -1) return ERROR;
    *e = s.data[s.top];
    return OK;
}

Status PushStack(Stack *s, SElemType e) {
    if (!s) return ERROR;
    if (s->top == s->maxSize - 1) {
        s->data = (SElemType *)realloc(s->data, sizeof(SElemType) * (s->maxSize + SIZE));
        if (!s->data) return ERROR;
        s->maxSize += SIZE;
    }
    s->top++;
    s->data[s->top] = e;
    return OK;
}

Status PopStack(Stack *s, SElemType *e) {
    if (!s) return ERROR;
    *e = s->data[s->top];
    s->top--;
    return OK;
}

int StackLength(Stack s) {
    return s.top + 1;
}

/*
 55. 跳跃游戏
 给定一个非负整数数组，你最初位于数组的第一个位置。

 数组中的每个元素代表你在该位置可以跳跃的最大长度。

 判断你是否能够到达最后一个位置。

 示例 1:

 输入: [2,3,1,1,4]
 输出: true
 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
 示例 2:

 输入: [3,2,1,0,4]
 输出: false
 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 
 
 */

int canJump(int* nums, int numsSize) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > k) return -1;
        k = i + nums[i] > k ? i + nums[i] : k;
        if (k > numsSize) return 0;
    }
    return -1;
}
//
//int canJump(int* nums, int numsSize){
//    int cpyNums[numsSize];
//    // copy nums
//    for (int i = 0; i < numsSize; i++) {
//        cpyNums[i] = nums[i];
//    }
//
//    // index stack
//    Stack stack;
//    InitStack(&stack);
//
//    PushStack(&stack, 0);
//
//    while (StackLength(stack) != 0) {
//        // 获取栈顶元素
//        int top;
//        GetTop(stack, &top);
//
//        int curMaxStep = cpyNums[top];
//        int index = top + curMaxStep;
//        if (index >= numsSize - 1) return 0;
//
//        if (curMaxStep > 0) {
//            PushStack(&stack, index);
//            cpyNums[top] = --curMaxStep;
//        } else {
//            PopStack(&stack, &top);
//        }
//    }
//
//    return -1;
//}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int arr[] = {0};
    
    if (canJump(arr, 1) == 0) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
