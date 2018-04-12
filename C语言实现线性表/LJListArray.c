//
//  LJListArray.c
//  C语言实现线性表
//
//  Created by james on 2018/4/12.
//  Copyright © 2018年 james. All rights reserved.
//

#include "LJListArray.h"
#include <stdlib.h>
LJListArray * createList(int capacity) {
    if (capacity <=0) {
        //分配内存空间失败
        return NULL;
    }
    //申请堆区空间
    LJListArray *array = malloc(sizeof(LJListArray));
    
    //需要判断内存空间是否申请成功,申请成功的情况下初始化
    if (array) {
        //初始化
        array->capacity = capacity;
        array->length = 0;
        array->value = malloc(capacity * sizeof(LJValuesNode));
    }
    return array;
}


void destroyArray(LJListArray  *array) {
    if (array) {
        //先干掉value的堆控件
        free(array->value);
        //再释放array
        free(array);
    }
}
