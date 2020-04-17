//
//  main.c
//  汉诺塔
//
//  Created by leeyii on 2020/4/14.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>

int step = 0;
void moves(int num, char source, char target) {
    step++;
    printf("将%c盘上编号为:%d的盘子移动到%c盘\n", source, num, target);
//    printf("%c --> %c\n", source, target);
}

// 将数量为n个盘子从a塔移动到c塔, b作为辅助塔.
void hanoi(int n, char a, char b, char c) {
    
    if (n == 1) {
        moves(1 ,a, c);
    } else {
        hanoi(n - 1, a, c, b);
        moves(n ,a, c);
        hanoi(n - 1, b, a, c);
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    hanoi(3, 'A', 'B', 'C');
    printf("实现所需步骤: %d\n", step);
    return 0;
}
