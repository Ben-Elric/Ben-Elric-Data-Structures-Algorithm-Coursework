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

//创建有number头猪的静态链表，返回数组的头指针
SPigNode * CreatePigs(int number)
{
	SPigNode* pHead = new SPigNode[number+1];
	//0号作为头指针
	pHead[0].nextpig = 1;

	for (int i = 1; i < number; ++i)
		pHead[i].nextpig = i + 1;
	pHead[number].nextpig = LIST_END;
	//nextpig -1表示链表尾，0表示空闲位置

	ifstream fin(PIGS_DATA);
	cout << "[info] 从文件" << PIGS_DATA << "输入" << number << "头猪的数据";
	for (int i = 1; i <= number; ++i)
	{
		fin >> pHead[i].PigName >> pHead[i].weight;
	}
	fin.close();

	return pHead;
}

//按照猪的名字排序
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
		//字典序
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


//按照猪的体重排序
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
		//降序
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


//插入一头新的猪
void InsertPig(SPigNode * sp, SPigNode pig)
{
	int nowIndex = 0;
	while (sp[nowIndex].nextpig != LIST_EMPTY)
		++nowIndex;
	sp[nowIndex] = pig;
	sp[nowIndex].nextpig = sp[0].nextpig;
	sp[0].nextpig = nowIndex;
}


//杀掉大于等于weight重量的猪
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


//杀掉指定名字的猪
void KillPigByName(SPigNode * sp)
{
	ifstream fin(PIGS_DELETE);
	cout << "[info] 从文件" << PIGS_DELETE << "输入待清除的猪的名字";
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


//杀掉所有的猪
void KillAllPigs(SPigNode * sp)
{
	int nowIndex = sp[0].nextpig;

	while (nowIndex != LIST_END)
		sp[nowIndex].nextpig = 0;
	sp[0].nextpig = LIST_END;
}


//获取链表中猪的个数
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


//显示链表中所有的猪
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
