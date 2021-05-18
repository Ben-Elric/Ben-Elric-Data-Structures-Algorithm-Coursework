#include "DoubleLinkedList.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define PIGS_DATA "pigs.txt"
#define PIGS_DELETE "pigs2delete.txt"

//创建有number头猪的双向链表，返回头指针
DPigNode * DCreatePigs(int number)
{
	//头节点置空，仅作为头指针
	DPigNode* phead = new DPigNode;
	phead->pNextPig = phead->pPrePig = nullptr;

	ifstream fin(PIGS_DATA);
	cout << "[info] 从文件" << PIGS_DATA << "输入" << number << "头猪的数据";

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

//按照猪的名字排序，返回链表头指针
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
		//字典序
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

//按照猪的体重排序，返回链表头指针
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
		//降序
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

//插入一头新的猪
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

//杀掉大于等于weight重量的猪，返回杀完后的链表头指针
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

//杀掉指定名字的猪，返回杀完后的链表头指针
DPigNode * KillPigByName(DPigNode * head)
{
	ifstream fin(PIGS_DELETE);
	cout << "[info] 从文件" << PIGS_DELETE << "输入待清除的猪的名字";
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

//杀掉所有的猪
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

//获取链表中猪的个数
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

//显示链表中所有的猪
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