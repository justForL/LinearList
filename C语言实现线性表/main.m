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
        addData(array1, (LJValuesNode)3);
        addData(array1, (LJValuesNode)4);
        addData(array1, (LJValuesNode)5);
        addData(array1, (LJValuesNode)6);
        addData(array1, (LJValuesNode)7);
        arrayPrint(array1);
        
    }
    return 0;
}
