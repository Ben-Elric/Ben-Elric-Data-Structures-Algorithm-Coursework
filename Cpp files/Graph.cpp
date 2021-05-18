#include "Graph.h"
#include "stdafx.h"
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "GeAlg.h"
#include "Chromosome.h"
using namespace std;

#define random(x) (rand()%x)
#define MAX 10 //data can be modified
#define INFINITY 9999


CGraph::CGraph(int vertices)
{
	numVertices = vertices;
	adjLists = new list<int>[vertices];
	visited = new bool[vertices];
	;
}
CGraph::~CGraph()
{
	;
}



//创建一个无向图
int CGraph::LocateVex(char GName)
{
	for (int i = 0; i < MAX; i++)
	{
		if (GName == MyGraph->GName)
		{
			return i;
		}
	}
	return -1;
}



void CGraph::CreateUndirectedGraph(int Nnum, GNode* g)
{
	int i, j;
	char v1, v2;
	cin >> NodeNum >> ArcNum;
	cin >> g->cost >> g->GName;
	char vexs[MAX];
	GNode* temp = new  GNode;
	for (int a = 0; a < MAX; a++)
	{
		vexs[a] = temp->GName;
		temp = temp->pNextNode;
	}

	int arcs[MAX][MAX];
	for (i = 0; i < NodeNum; i++)
	{
		for (j = 0; j < NodeNum; j++)
			arcs[i][j] = INFINITY;
	}

	for (int k = 0; k < ArcNum; k++)
	{
		arcs[i][j] = g->cost;
		arcs[j][i] = arcs[i][j];    //因为是无向图，所以矩阵对称
	}
}


//深度优先搜索遍历                   
void CGraph::DFSUndirectedGraph(int vertex)
{
	visited[vertex] = true;
	list<int> adjList = adjLists[vertex];


	list<int>::iterator i;
	for (i = adjList.begin(); i != adjList.end(); ++i)
		if (!visited[*i])
			DFSUndirectedGraph(*i);
	return;
}

//广度优先搜索遍历                                   
void CGraph::BFSUndirectedGraph(int startVertex)
{
	visited = new bool[numVertices];
	for (int i = 0; i < numVertices; i++)
		visited[i] = false;

	list<int> queue;

	visited[startVertex] = true;
	queue.push_back(startVertex);

	list<int>::iterator i;

	while (!queue.empty()) {
		int currVertex = queue.front();
		queue.pop_front();

		for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
			int adjVertex = *i;
			if (!visited[adjVertex]) {
				visited[adjVertex] = true;
				queue.push_back(adjVertex);
			}
		}
	}
	return;
}



//Kruskal最小生成树算法
void CGraph::union_set(int u, int v) {
	parent[u] = parent[v];
}
int CGraph::find_set(int i) {

	if (i == parent[i])
		return i;
	else

		return find_set(parent[i]);
}
void CGraph::GetMiniCostSpanningTreeByKruskal()
{
	int i, uRep, vRep;
	sort(G.begin(), G.end());  
	for (i = 0; i < G.size(); i++) {
		uRep = find_set(G[i].second.first);
		vRep = find_set(G[i].second.second);
		if (uRep != vRep) {
			T.push_back(G[i]);  
			union_set(uRep, vRep);
		}
	}
	return;
}

//Prim最小生成树算法        

void CGraph::GetMiniCostSpanningTreeByPrim()
{
	int G[MAX][MAX];
	int no_edge; 
	int selected[MAX];
	memset(selected, false, sizeof(selected));
	no_edge = 0;
	selected[0] = true;

	int x;  
	int y;  
	printf("Edge : Weight\n");

	while (no_edge < MAX - 1) {

		int min = INFINITY;
		x = 0;
		y = 0;

		for (int i = 0; i < MAX; i++) {
			if (selected[i]) {
				for (int j = 0; j < MAX; j++) {
					if (!selected[j] && G[i][j]) {  
						if (min > G[i][j]) {
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		printf("%d - %d : %d\n", x, y, G[x][y]);
		selected[y] = true;
		no_edge++;
	}
	return;
}

		

//Dijistra算法            

void CGraph::GetMiniCostPathByDijistra(int Graph[MAX][MAX], char start, char n)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;

	// Creating cost matrix
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (Graph[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = Graph[i][j];

	for (i = 0; i < n; i++) {
		distance[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0;
	}

	distance[start] = 0;
	visited[start] = 1;
	count = 1;

	while (count < n - 1) {
		mindistance = INFINITY;

		for (i = 0; i < n; i++)
			if (distance[i] < mindistance && !visited[i]) {
				mindistance = distance[i];
				nextnode = i;
			}

		visited[nextnode] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i]) {
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	return;
}




	//遗传算法




	void GetMiniCostPathByInheritance(char start, char target); 
{
		GeAlg* ga = new GeAlg(100, 0.2, 0.0001, 8);
ga->calc();

while (1)
{

	//while (ga->size() - 100 > 0)
	//{
		//ga->select();
	ga->select();
	ga->calc();
	//}
	ga->print();
	ga->next_generation();
}
	return;
}

//Thinking
//function gaSearch(iteratorNum, chromosomeNum) {
//	// 初始化第一代染色体
//	var chromosomeMatrix = createGeneration();
//
//	// 迭代繁衍
//	for (var itIndex = 1; itIndex < iteratorNum; itIndex++) {
//		// 计算上一代各条染色体的适应度
//		calAdaptability(chromosomeMatrix);
//
//		// 计算自然选择概率
//		calSelectionProbability(adaptability);
//
//		// 生成新一代染色体
//		chromosomeMatrix = createGeneration(chromosomeMatrix);
//
//	}
//}