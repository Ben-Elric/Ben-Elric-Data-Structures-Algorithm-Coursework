#include <iostream>
#include "Array.h"
using namespace std;

void testArray()
{
    int timeSpent, na, lena;

    int* arr = cyf_CreateArray(10);
    lena = 10; na = 8;
    cyf_InitArray(arr, lena, na);
    cout << "1. 初始化：";
    cyf_ShowArray(arr, lena, na);
    cout << "\r\n2. 排序后：";
    timeSpent = cyf_SortArray_Maopao_TimeComplex(arr, lena, na);
    cyf_ShowArray(arr, lena, na);
    cout << "共进行" << timeSpent << "次运算" << endl;
    cout << "\r\n3. 添加两个元素1：";
    na = cyf_AddElement(arr, lena, na, 1);
    na = cyf_AddElement(arr, lena, na, 1);
    cyf_ShowArray(arr, lena, na);
    cout << "\r\n4. 删除所有元素1：";
    na = cyf_DeleteElement(arr, lena, na, 1);
    cyf_ShowArray(arr, lena, na);

    int addNums[] = { 8,2,0,0 };
    cout << "\r\n5. 新增2个元素并排序后：";
    cyf_AddElement(arr, lena, na, addNums, 4, 2);
    cyf_ShowArray(arr, lena, na);

    int addNums2[] = { 3,7,9,1,2,0,4,2,5,1 };
    cout << "\r\n6. 新增10个元素并排序后：";
    cyf_AddElement(arr, lena, na, addNums2, 10, 10);
    cyf_ShowArray(arr, lena, na);
}

int main()
{
    testArray();
    return 0;
}
