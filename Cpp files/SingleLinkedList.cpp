#include "SingleLinkedList.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define PIGS_DATA "pigs.txt"
#define PIGS_DELETE "pigs2delete.txt"

//创建有number头猪的单向链表，返回头指针
PigNode * CreatePigs(int number)
{
	//头节点置空，仅作为头指针
	PigNode* phead = new PigNode;
	phead->pNextPig = nullptr;
	
	ifstream fin(PIGS_DATA);
	cout << "[info] 从文件" << PIGS_DATA << "输入" << number << "头猪的数据";
	for (int i = 1; i <= number; ++i)
	{
		PigNode* pPig = new PigNode;
		fin >> pPig->PigName >> pPig->weight;
		pPig->pNextPig = phead->pNextPig;
		phead->pNextPig = pPig;
	}

	return phead;
}

//按照猪的名字排序，返回链表头指针
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
PigNode * InsertPig(PigNode * pHead, PigNode pig)
{
	PigNode* pPig = new PigNode;
	*pPig = pig;
	pPig->pNextPig = pHead->pNextPig;
	pHead->pNextPig = pPig;
	
	return pHead;
}

//杀掉大于等于weight重量的猪，返回杀完后的链表头指针
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

//杀掉指定名字的猪，返回杀完后的链表头指针
PigNode * KillPigByName(PigNode * head)
{
	ifstream fin(PIGS_DELETE);
	cout << "[info] 从文件" << PIGS_DELETE << "输入待清除的猪的名字";
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

//杀掉所有的猪
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

//获取链表中猪的个数
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

//显示链表中所有的猪
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