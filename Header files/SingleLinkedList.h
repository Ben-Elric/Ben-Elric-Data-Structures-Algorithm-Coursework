#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__
#include <cstring>

struct PigNode
{
	char PigName[20];
	int  weight;
	PigNode * pNextPig;

    PigNode& operator =(const PigNode& b)
    {
        if (this == &b)
            return *this;

        strcpy_s(PigName, b.PigName);
        weight = b.weight;
        pNextPig = b.pNextPig;
        return *this;
    }
};

//������numberͷ��ĵ�����������ͷָ��
PigNode * CreatePigs(int number);

//��������������򣬷�������ͷָ��
PigNode * SortPigsByName(PigNode * head);

//��������������򣬷�������ͷָ��
PigNode * SortPigsByWeight(PigNode * head);

//����һͷ�µ���
PigNode * InsertPig(PigNode * head, PigNode pig);

//ɱ�����ڵ���weight������������ɱ��������ͷָ��
PigNode * KillPigByWeight(PigNode * head, int weight);

//ɱ��ָ�����ֵ�������ɱ��������ͷָ��
PigNode * KillPigByName(PigNode * head); 

//ɱ�����е���
void KillAllPigs(PigNode * head);

//��ȡ��������ĸ���
int GetPigsNumber(PigNode * head);

//��ʾ���������е���
void ShowAllPigs(PigNode * head);

#endif