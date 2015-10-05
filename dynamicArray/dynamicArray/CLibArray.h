#ifndef  __CLIBARRAY__
#define __CLIBARRAY__

typedef struct
{
	int capacity;
	int size;
	int *p;
}CArray;

void array_initial(CArray *array);

int array_capacity(CArray *array);
int array_size(CArray *array);

void array_recap(CArray *array,int size);

int  *array_at(CArray *array,int index);//原来返回的是指针，但是测试文件中又要求返回数值真是莫名其妙！
void array_append(CArray *array,int element);
void array_insert(CArray *array,int index,int element);

void array_copy(CArray *src,CArray *dst);
bool array_compare(CArray *array1,CArray *array2);

void array_destroy(CArray *array);

#endif