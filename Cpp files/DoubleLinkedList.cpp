#include "DoubleLinkedList.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define PIGS_DATA "pigs.txt"
#define PIGS_DELETE "pigs2delete.txt"

//������numberͷ���˫����������ͷָ��
DPigNode * DCreatePigs(int number)
{
	//ͷ�ڵ��ÿգ�����Ϊͷָ��
	DPigNode* phead = new DPigNode;
	phead->pNextPig = phead->pPrePig = nullptr;

	ifstream fin(PIGS_DATA);
	cout << "[info] ���ļ�" << PIGS_DATA << "����" << number << "ͷ�������";

	for (int i = 0; i < number; ++i)
	{
		DPigNode* pPig = new DPigNode;
		fin >> pPig->PigName >> pPig->weight;
		pPig->pNextPig = phead->pNextPig;
		pPig->pPrePig = phead;
		phead->pNextPig->pPrePig = pPig;
		phead->pNextPig = pPig;
	}
	
	return phead;
}

//��������������򣬷�������ͷָ��
DPigNode * SortPigsByName(DPigNode * head)
{
	int cnt = GetPigsNumber(head);
	if (cnt == 0)
		return head;
	DPigNode* list = new DPigNode[cnt];

	DPigNode* now = head->pNextPig;
	int top = 0;
	while (now != nullptr)
	{
		list[top++] = *now;
		now = now->pNextPig;
	}

	sort(list, list + cnt, [](DPigNode& a, DPigNode& b)
	{
		//�ֵ���
		return strcmp(a.PigName, b.PigName) < 0;
	});

	now = head->pNextPig;
	cnt = 0;
	while (now != nullptr)
	{
		*now = list[cnt++];
		now = now->pNextPig;
	}
	return head;
}

//��������������򣬷�������ͷָ��
DPigNode * SortPigsByWeight(DPigNode * head)
{
	int cnt = GetPigsNumber(head);
	if (cnt == 0)
		return head;
	DPigNode* list = new DPigNode[cnt];

	DPigNode* now = head->pNextPig;
	int top = 0;
	while (now != nullptr)
	{
		list[top++] = *now;
		now = now->pNextPig;
	}

	sort(list, list + cnt, [](DPigNode& a, DPigNode& b)
	{
		//����
		return a.weight > b.weight;
	});

	now = head->pNextPig;
	cnt = 0;
	while (now != nullptr)
	{
		*now = list[cnt++];
		now = now->pNextPig;
	}
	return head;
}

//����һͷ�µ���
DPigNode * InsertPig(DPigNode * head, DPigNode pig)
{
	DPigNode* pPig = new DPigNode;
	*pPig = pig;
	pPig->pNextPig = head->pNextPig;
	pPig->pPrePig = head;
	head->pNextPig->pPrePig = pPig;
	head->pNextPig = pPig;

	return head;
}

//ɱ�����ڵ���weight������������ɱ��������ͷָ��
DPigNode * KillPigByWeight(DPigNode * head, int weight)
{
	head = head->pNextPig;
	while (head != nullptr)
	{
		if (head->weight >= weight)
		{

			DPigNode *next = head->pNextPig;
			head->pPrePig->pNextPig = head->pNextPig;
			head->pNextPig->pPrePig = head->pPrePig;
			delete head;
			head = next;
		}
		else
			head = head->pNextPig;
	}

	return head;
}

//ɱ��ָ�����ֵ�������ɱ��������ͷָ��
DPigNode * KillPigByName(DPigNode * head)
{
	ifstream fin(PIGS_DELETE);
	cout << "[info] ���ļ�" << PIGS_DELETE << "�����������������";
	char PigName[20];
	fin >> PigName;
	fin.close();

	head = head->pNextPig;
	while (head != nullptr)
	{
		if (strcmp(head->PigName,PigName) == 0)
		{

			DPigNode* next = head->pNextPig;
			head->pPrePig->pNextPig = head->pNextPig;
			head->pNextPig->pPrePig = head->pPrePig;
			delete head;
			head = next;
		}
		else
			head = head->pNextPig;
	}

	return head;
}

//ɱ�����е���
void KillAllPigs(DPigNode * head)
{
	head = head->pNextPig;
	DPigNode* tmp;

	while (head != nullptr)
	{
		tmp = head->pNextPig;
		delete head;
		head = tmp;
	}
}

//��ȡ��������ĸ���
int GetPigsNumber(DPigNode * head)
{
	head = head->pNextPig;
	int cnt = 0;
	while (head != nullptr)
	{
		++cnt;
		head = head->pNextPig;
	}
	return cnt;
}

//��ʾ���������е���
void ShowAllPigs(DPigNode * head)
{
	head = head->pNextPig;
	int cnt = 0;
	while (head != nullptr)
	{
		printf("Pig%02d: %s\t%d", ++cnt, head->PigName, head->weight);
		head = head->pNextPig;
	}
}