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

//������numberͷ���˫����������ͷָ��
DPigNode * DCreatePigs(int number);

//��������������򣬷�������ͷָ��
DPigNode * SortPigsByName(DPigNode * head);

//��������������򣬷�������ͷָ��
DPigNode * SortPigsByWeight(DPigNode * head);

//����һͷ�µ���
DPigNode * InsertPig(DPigNode * head, DPigNode pig);

//ɱ�����ڵ���weight������������ɱ��������ͷָ��
DPigNode * KillPigByWeight(DPigNode * head, int weight);

//ɱ��ָ�����ֵ�������ɱ��������ͷָ��
DPigNode * KillPigByName(DPigNode * head); 

//ɱ�����е���
void KillAllPigs(DPigNode * head);

//��ȡ��������ĸ���
int GetPigsNumber(DPigNode * head);

//��ʾ���������е���
void ShowAllPigs(DPigNode * head);

#endif