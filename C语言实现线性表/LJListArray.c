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


void cleanArray(LJListArray *array) {
    if (array) {
        array->length = 0;
    }
}


int arrayLength(LJListArray *array) {
    if (array) {
        return array->length;
    }
    return 0;
}


LJValuesNode getData(LJListArray *array, int index) {
    if (array == NULL || index < 0 || index >= array->length ) {
        return NULL;
    }
    return array->value[index];
}



void insertData(LJListArray *array, int index, LJValuesNode value) {
    if (array == NULL || index < 0 || index > array->length || value == NULL || array->length == array->capacity) {
        return;
    }
    //向后各串一位
    for (int i = array->length - 1; i >= index; i--) {
        array->value[i+1] = array->value[i];
    }
    //对index位进行赋值
    array->value[index] = value;
    //不要忘记增加线性表长度
    array->length++;
}


void addData(LJListArray *array, LJValuesNode value) {
    if (array == NULL || value == NULL ) {
        return;
    }
    insertData(array, array->length, value);
}


void setData(LJListArray *array, int index, LJValuesNode value) {
    if (array == NULL || index > array->length || value == NULL) {
        return;
    }
    array->value[index] = value;
}


void delateData(LJListArray *array, int index) {
    if (array == NULL || index > array->length) {
        return;
    }
    for (int i = index+1; i < array->length; i++) {
        array->value[i-1] = array->value[i];
    }
    array->length--;
}


void delateAllDataInArray(LJListArray *array, LJValuesNode value) {
    if (array == NULL || value == NULL) {
        return;
    }
    //记录需要删除的数据的位置偏移量
    int removeCount = 0;
    //遍历线性表
    for (int i = 0; i<array->length; i++) {
        if (array->value[i] == value) {     //需要删除
            removeCount++;
        }else{                              //不需要删除
            array->value[i-removeCount] = array->value[i];
        }
    }
    
    array->length -= removeCount;
}


void arrayPrintValues(LJListArray * array){
    printf("[");
    for (int i = 0; i < array->length; i++) {
        printf("%p",array->value[i]);
        if (i < array->length - 1) {
            printf(",");
        }
    }
    printf("];\n");
}

void arrayPrint(LJListArray *array){
    if (array == NULL) {
        return;
    }
    printf("list{\n");
    printf("\tlength = %d\n",array->length);
    printf("\tcapacity = %d\n",array->capacity);
    printf("\tvalues = ");
    arrayPrintValues(array);
    printf("}\n\n");
    
}

