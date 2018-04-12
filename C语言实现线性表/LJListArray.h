//
//  LJListArray.h
//  C语言实现线性表
//
//  Created by james on 2018/4/12.
//  Copyright © 2018年 james. All rights reserved.
//

#ifndef LJListArray_h
#define LJListArray_h


#include <stdio.h>

typedef void * LJValuesNode;

typedef struct {
    int capacity;       //容量
    int length;         //长度
    LJValuesNode * value;       //数据指针
    
}LJListArray;



/**
 创建ListArray

 @param capacity 容量
 @return listArray
 */
LJListArray * createList(int capacity);

/**
 销毁线性表

 @param array array
 */
void destroyArray(LJListArray  *array);


/**
 清空线性表
 
 @param array array
 */
void cleanArray(LJListArray *array);


/**
 获取线性表的长度

 @param array array
 */
int arrayLength(LJListArray *array);

#endif /* LJListArray_h */
