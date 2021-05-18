#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <list>
#include <vector>
using namespace std;
#define edge pair<int, int>
#define MAX 10//data can be modified



struct GNode
{
	char    GName;      //节点名称
	int     cost;       //cost权值
	GNode * pNextNode;  //节点指针
};

class CGraph
{
	int numVertices;
	list<int>* adjLists;
	bool* visited;

	int  ArcNum;//边数量
	int     NodeNum;    //节点数量
	GNode * MyGraph;    //节点数组 图
public:
	CGraph(int vertices);
	~CGraph();

	int LocateVex(char GName);



	void CreateUndirectedGraph(int Nnum, GNode* g);                   //创建一个无向图
	void DFSUndirectedGraph(int vertex);                        //深度优先搜索遍历
	void BFSUndirectedGraph(int startVertex);                     //广度优先搜索遍历
	void GetMiniCostSpanningTreeByKruskal();                     //Kruskal最小生成树算法
	void GetMiniCostSpanningTreeByPrim();                        //Prim最小生成树算法
	void GetMiniCostPathByDijistra(int Graph[MAX][MAX], char start, char target);     //Dijistra算法

	void GetMiniCostPathByInheritance(char start, char target);  //遗传算法（自己查资料）
	
private:
	vector<pair<int, edge> > G;  // graph
	vector<pair<int, edge> > T;  // mst
	int* parent;
	int V;
	int find_set(int i);
	void union_set(int u, int v);
	int j;
};

#endif