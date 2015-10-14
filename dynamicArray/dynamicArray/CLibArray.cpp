#include <stdlib.h>
#include "CLibArray.h"

void array_initial(CArray *array){
    array->size = 0;
    array->capacity = 0;
    array->p = (int *)malloc(sizeof(int)*array->capacity);
};

//nonesense
int array_capacity(CArray *array){
    return array->capacity;
};

//nonesense2
int array_size(CArray *array){
    return array->size;
};

void array_recap(CArray *array,int size){
    array->p = (int *)realloc(array->p, sizeof(int)*size);
    array->capacity = size;
};


int *array_at(CArray *array,int index){
    return (array->p+index);
};

void array_append(CArray *array,int element){
    if (array->size >= array->capacity ) {
        array_recap(array, array->capacity*2);
    }
    array->p[array->size] = element;
    array->size++;
};

//use recursion
void array_insert(CArray *array,int index,int element){
    int temp;
    if (index < array->size) {
        //swap element and array[index]
        temp = array->p[index];
        array->p[index] = element;
        element = temp;
        array_insert(array,++index,element);
    }
    else array_append(array, element);
};

void array_copy(CArray *src,CArray *dst){
    array_recap(dst, src->capacity);
    for (int i = 0; i < src->size; ++i) {
        array_append(dst, *src->p+i);
    }
    
};

bool array_compare(CArray *array1,CArray *array2){
    int max_size = array1->size > array2->size ? array1->size:array2->size;
    for (int i = 0; i < max_size; ++i) {
        if (array1->p[i] != array2->p[i]) {
            return false;
        }
    }
    return true;
};

void array_destroy(CArray *array){
    free(array->p);
    array->size = 0;
    array->capacity = 0;
};