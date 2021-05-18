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

//������numberͷ��ľ�̬�������������ͷָ��
SPigNode * CreatePigs(int number);

//���������������
void SortPigsByName(SPigNode * sp);

//���������������
void SortPigsByWeight(SPigNode * sp);

//����һͷ�µ���
void InsertPig(SPigNode * sp, SPigNode pig);

//ɱ�����ڵ���weight��������
void KillPigByWeight(SPigNode * sp, int weight);

//ɱ��ָ�����ֵ���
void KillPigByName(SPigNode * sp); 

//ɱ�����е���
void KillAllPigs(SPigNode * sp);

//��ȡ��������ĸ���
int GetPigsNumber(SPigNode * sp);

//��ʾ���������е���
void ShowAllPigs(SPigNode * sp);

#endif