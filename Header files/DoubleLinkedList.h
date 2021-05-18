#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__
#include <cstring>

struct DPigNode
{
	char PigName[20];
	int  weight;
	DPigNode * pPrePig;
	DPigNode * pNextPig;

    DPigNode& operator =(const DPigNode& b)
    {
        if (this == &b)
            return *this;

        strcpy_s(PigName, b.PigName);
        weight = b.weight;
        pNextPig = b.pNextPig;
        pPrePig = b.pPrePig;
        return *this;
    }
};

//创建有number头猪的双向链表，返回头指针
DPigNode * DCreatePigs(int number);

//按照猪的名字排序，返回链表头指针
DPigNode * SortPigsByName(DPigNode * head);

//按照猪的体重排序，返回链表头指针
DPigNode * SortPigsByWeight(DPigNode * head);

//插入一头新的猪
DPigNode * InsertPig(DPigNode * head, DPigNode pig);

//杀掉大于等于weight重量的猪，返回杀完后的链表头指针
DPigNode * KillPigByWeight(DPigNode * head, int weight);

//杀掉指定名字的猪，返回杀完后的链表头指针
DPigNode * KillPigByName(DPigNode * head); 

//杀掉所有的猪
void KillAllPigs(DPigNode * head);

//获取链表中猪的个数
int GetPigsNumber(DPigNode * head);

//显示链表中所有的猪
void ShowAllPigs(DPigNode * head);

#endif