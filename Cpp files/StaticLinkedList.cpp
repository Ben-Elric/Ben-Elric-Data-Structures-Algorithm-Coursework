#include "StaticLinkedList.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

#define PIGS_DATA "pigs.txt"
#define PIGS_DELETE "pigs2delete.txt"
#define LIST_END -1
#define LIST_EMPTY 0

//������numberͷ��ľ�̬�������������ͷָ��
SPigNode * CreatePigs(int number)
{
	SPigNode* pHead = new SPigNode[number+1];
	//0����Ϊͷָ��
	pHead[0].nextpig = 1;

	for (int i = 1; i < number; ++i)
		pHead[i].nextpig = i + 1;
	pHead[number].nextpig = LIST_END;
	//nextpig -1��ʾ����β��0��ʾ����λ��

	ifstream fin(PIGS_DATA);
	cout << "[info] ���ļ�" << PIGS_DATA << "����" << number << "ͷ�������";
	for (int i = 1; i <= number; ++i)
	{
		fin >> pHead[i].PigName >> pHead[i].weight;
	}
	fin.close();

	return pHead;
}

//���������������
void SortPigsByName(SPigNode * sp)
{
	int cnt = GetPigsNumber(sp);
	if (cnt == 0)
		return;
	SPigNode* list = new SPigNode[cnt];

	int nowIndex = sp[0].nextpig;
	int nowCount = 0;
	while (nowIndex != LIST_END)
	{
		list[nowCount] = sp[nowIndex];
		++nowCount;
		nowIndex = sp[nowIndex].nextpig;
	}

	sort(list, list + cnt,[](SPigNode& a, SPigNode& b)
	{
		//�ֵ���
		return strcmp(a.PigName, b.PigName) < 0;
	});

	nowIndex = sp[0].nextpig;
	nowCount = 0;
	while (nowIndex != LIST_END)
	{
		sp[nowIndex] = list[nowCount];
		++nowCount;
		nowIndex = sp[nowIndex].nextpig;
	}
}


//���������������
void SortPigsByWeight(SPigNode * sp)
{
	int cnt = GetPigsNumber(sp);
	if (cnt == 0)
		return;
	SPigNode* list = new SPigNode[cnt];

	int nowIndex = sp[0].nextpig;
	int nowCount = 0;
	while (nowIndex != LIST_END)
	{
		list[nowCount] = sp[nowIndex];
		++nowCount;
		nowIndex = sp[nowIndex].nextpig;
	}

	sort(list, list + cnt, [](SPigNode& a, SPigNode& b)
	{
		//����
		return a.weight > b.weight;
	});

	nowIndex = sp[0].nextpig;
	nowCount = 0;
	while (nowIndex != LIST_END)
	{
		sp[nowIndex] = list[nowCount];
		++nowCount;
		nowIndex = sp[nowIndex].nextpig;
	}
}


//����һͷ�µ���
void InsertPig(SPigNode * sp, SPigNode pig)
{
	int nowIndex = 0;
	while (sp[nowIndex].nextpig != LIST_EMPTY)
		++nowIndex;
	sp[nowIndex] = pig;
	sp[nowIndex].nextpig = sp[0].nextpig;
	sp[0].nextpig = nowIndex;
}


//ɱ�����ڵ���weight��������
void KillPigByWeight(SPigNode * sp, int weight)
{
	int nowIndex = sp[0].nextpig;
	int prevIndex = 0;

	while (nowIndex != LIST_END)
	{
		if (sp[nowIndex].weight >= weight)
			sp[prevIndex].nextpig = sp[nowIndex].nextpig;
		prevIndex = nowIndex;
		nowIndex = sp[nowIndex].nextpig;
	}
}


//ɱ��ָ�����ֵ���
void KillPigByName(SPigNode * sp)
{
	ifstream fin(PIGS_DELETE);
	cout << "[info] ���ļ�" << PIGS_DELETE << "�����������������";
	char PigName[20];
	fin >> PigName;
	fin.close();

	int nowIndex = sp[0].nextpig;
	int prevIndex = 0;
	while (nowIndex != LIST_END)
	{
		if (strcmp(sp[nowIndex].PigName,PigName) == 0)
			sp[prevIndex].nextpig = sp[nowIndex].nextpig;
		prevIndex = nowIndex;
		nowIndex = sp[nowIndex].nextpig;
	}
}


//ɱ�����е���
void KillAllPigs(SPigNode * sp)
{
	int nowIndex = sp[0].nextpig;

	while (nowIndex != LIST_END)
		sp[nowIndex].nextpig = 0;
	sp[0].nextpig = LIST_END;
}


//��ȡ��������ĸ���
int GetPigsNumber(SPigNode * sp)
{
	int nowIndex = sp[0].nextpig;

	int cnt = 0;
	while (nowIndex != LIST_END)
	{
		++cnt;
		nowIndex = sp[nowIndex].nextpig;
	}

	return cnt;
}


//��ʾ���������е���
void ShowAllPigs(SPigNode * sp)
{
	int nowIndex = sp[0].nextpig;
	
	int cnt = 0;
	while (nowIndex != LIST_END)
	{
		printf("Pig%02d: %s\t%d", ++cnt, sp[nowIndex].PigName, sp[nowIndex].weight);
		nowIndex = sp[nowIndex].nextpig;
	} 
}
