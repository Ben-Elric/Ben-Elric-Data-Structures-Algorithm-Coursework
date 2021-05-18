#include "SingleLinkedList.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define PIGS_DATA "pigs.txt"
#define PIGS_DELETE "pigs2delete.txt"

//������numberͷ��ĵ�����������ͷָ��
PigNode * CreatePigs(int number)
{
	//ͷ�ڵ��ÿգ�����Ϊͷָ��
	PigNode* phead = new PigNode;
	phead->pNextPig = nullptr;
	
	ifstream fin(PIGS_DATA);
	cout << "[info] ���ļ�" << PIGS_DATA << "����" << number << "ͷ�������";
	for (int i = 1; i <= number; ++i)
	{
		PigNode* pPig = new PigNode;
		fin >> pPig->PigName >> pPig->weight;
		pPig->pNextPig = phead->pNextPig;
		phead->pNextPig = pPig;
	}

	return phead;
}

//��������������򣬷�������ͷָ��
PigNode * SortPigsByName(PigNode * head)
{
	int cnt = GetPigsNumber(head);
	if (cnt == 0)
		return head;
	PigNode* list = new PigNode[cnt];

	PigNode* now = head->pNextPig;
	int top = 0;
	while (now != nullptr)
	{
		list[top++] = *now;
		now = now->pNextPig;
	}

	sort(list, list + cnt, [](PigNode& a, PigNode& b)
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
PigNode * SortPigsByWeight(PigNode * head)
{
	int cnt = GetPigsNumber(head);
	if (cnt == 0)
		return head;
	PigNode* list = new PigNode[cnt];
	
	PigNode *now = head->pNextPig;
	int top = 0;
	while (now != nullptr)
	{
		list[top++] = *now;
		now = now->pNextPig;
	}

	sort(list, list + cnt, [](PigNode& a, PigNode& b)
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
PigNode * InsertPig(PigNode * pHead, PigNode pig)
{
	PigNode* pPig = new PigNode;
	*pPig = pig;
	pPig->pNextPig = pHead->pNextPig;
	pHead->pNextPig = pPig;
	
	return pHead;
}

//ɱ�����ڵ���weight������������ɱ��������ͷָ��
PigNode * KillPigByWeight(PigNode * head, int weight)
{
	head = head->pNextPig;
	PigNode* prevPig = head;
	while (head != nullptr)
	{
		if (head->weight >= weight)
		{
			prevPig->pNextPig = head->pNextPig;
			delete head;
			head = prevPig->pNextPig;
		}
		else
		{
			prevPig = head;
			head = head->pNextPig;
		}
	}
	
	return head;
}

//ɱ��ָ�����ֵ�������ɱ��������ͷָ��
PigNode * KillPigByName(PigNode * head)
{
	ifstream fin(PIGS_DELETE);
	cout << "[info] ���ļ�" << PIGS_DELETE << "�����������������";
	char PigName[20];
	fin >> PigName;
	fin.close();

	head = head->pNextPig;
	PigNode* prevPig = head;
	while (head != nullptr)
	{
		if (strcmp(head->PigName,PigName) == 0)
		{
			prevPig->pNextPig = head->pNextPig;
			delete head;
			head = prevPig->pNextPig;
		}
		else
		{
			prevPig = head;
			head = head->pNextPig;
		}
	}
	
	return head;
}

//ɱ�����е���
void KillAllPigs(PigNode * head)
{
	head = head->pNextPig;
	PigNode* tmp;

	while (head != nullptr)
	{
		tmp = head->pNextPig;
		delete head;
		head = tmp;
	}
}

//��ȡ��������ĸ���
int GetPigsNumber(PigNode * head)
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
void ShowAllPigs(PigNode * head)
{
	head = head->pNextPig;
	int cnt = 0;
	while (head != nullptr)
	{
		printf("Pig%02d: %s\t%d", ++cnt, head->PigName, head->weight);
		head = head->pNextPig;
	}
}