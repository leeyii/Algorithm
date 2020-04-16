//
//  main.c
//  每日气温
//
//  Created by leeyii on 2020/4/16.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


/*
 根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

 */

// 暴力解法
//int* dailyTemperatures(int* T, int TSize, int* returnSize){
//
//    int *res = (int *)malloc(sizeof(int) * TSize);
//    *returnSize = TSize;
//
//    for (int i = 0; i < TSize; i++) {
//        int x = T[i];
//        int diff = 0;
//        for (int j = i + 1; j < TSize; j++) {
//            int y = T[j];
//            if (y > x) {
//                diff = j - i;
//                break;
//            }
//        }
//        res[i] = diff;
//    }
//    return res;
//}

/*
 解法二:
 栈
 */

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    
    int *stack = (int *)malloc(sizeof(int) * TSize);
    int top = -1;
    int *result = malloc(sizeof(int) * TSize);
    *returnSize = TSize;
    
    top++;
    stack[top] = 0;
    
    for (int i = 1; i < TSize; i++) {
        int temp = T[i];
        
        int topIndex = stack[top];
        int topTemp = T[topIndex];
        while (topTemp < temp) {
            result[topIndex] = i - topIndex;
            top--;
            if (top == -1) break;
            topIndex = stack[top];
            topTemp = T[topIndex];
        }
        top++;
        stack[top] = i;
    }
    if (top != -1) {
        int topIndex = stack[top];
        result[topIndex] = 0;
        while (top != -1) {
            result[stack[top]] = 0;
            top--;
        }
    }

    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int temps[] = {73,74,75,71,69,72,76,73};
    int returnSize;
    
    int *res = dailyTemperatures(temps, 8, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d  ", res[i]);
    }
    
    return 0;
}
