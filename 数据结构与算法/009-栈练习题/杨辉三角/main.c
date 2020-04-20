//
//  main.c
//  杨辉三角
//
//  Created by leeyii on 2020/4/20.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*
 题目:给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    
    int **res = malloc(sizeof(int *) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    
    for (int i = 0; i < numRows; i++) {
        int *row = (int *)malloc(sizeof(int) * (i + 1));
//        row[0] = 1;
//        row[i] = 1;
        res[i] = row;
        res[i][0] = 1;
        res[i][i] = 1;
        (*returnColumnSizes)[i] = i + 1;
        if (i < 2) continue;
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int size = 5;
    int **res = generate(size, NULL, NULL);
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
