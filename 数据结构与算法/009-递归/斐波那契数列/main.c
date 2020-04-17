//
//  main.c
//  斐波那契数列
//
//  Created by leeyii on 2020/4/14.
//  Copyright © 2020 leeyii. All rights reserved.
//

#include <stdio.h>

/*
 斐波那契数列指的是这样一个数列：
 1、1、2、3、5、8、13、21、34、
 这个数列从第3项开始，每一项都等于前两项之和。
 */

int fbi(int n) {
    if (n < 2)
        return 1;
    else
        return fbi(n - 1) + fbi(n - 2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    for (int i = 0; i < 10; i++) {
        printf("%d    ", fbi(i));
    }
    
    return 0;
}
