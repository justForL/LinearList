//
//  main.m
//  C语言实现线性表
//
//  Created by james on 2018/4/12.
//  Copyright © 2018年 james. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LJListArray.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        LJListArray *array1 = createList(10);
        LJListArray *array2 = createList(10);
        LJListArray *array3 = createList(10);
        printf("%p\n",array1);
        printf("%p\n",array2);
        printf("%p\n",array3);
    }
    return 0;
}
