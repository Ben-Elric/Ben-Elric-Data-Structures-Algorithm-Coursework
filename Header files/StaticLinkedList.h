#ifndef __STATICLINKEDLIST_H__
#define __STATICLINKEDLIST_H__
#include <cstring>

struct SPigNode
{
	char PigName[20];
	int  weight;
	int  nextpig;

    SPigNode& operator =(const SPigNode& b)
    {
        if (this == &b)
            return *this;

        strcpy_s(PigName,b.PigName);
        weight = b.weight;
        nextpig = b.nextpig;
        return *this;
    }
};

//创建有number头猪的静态链表，返回数组的头指针
SPigNode * CreatePigs(int number);

//按照猪的名字排序
void SortPigsByName(SPigNode * sp);

//按照猪的体重排序
void SortPigsByWeight(SPigNode * sp);

//插入一头新的猪
void InsertPig(SPigNode * sp, SPigNode pig);

//杀掉大于等于weight重量的猪
void KillPigByWeight(SPigNode * sp, int weight);

//杀掉指定名字的猪
void KillPigByName(SPigNode * sp); 

//杀掉所有的猪
void KillAllPigs(SPigNode * sp);

//获取链表中猪的个数
int GetPigsNumber(SPigNode * sp);

//显示链表中所有的猪
void ShowAllPigs(SPigNode * sp);

#endif