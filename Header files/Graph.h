#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <list>
#include <vector>
using namespace std;
#define edge pair<int, int>
#define MAX 10//data can be modified



struct GNode
{
	char    GName;      //�ڵ�����
	int     cost;       //costȨֵ
	GNode * pNextNode;  //�ڵ�ָ��
};

class CGraph
{
	int numVertices;
	list<int>* adjLists;
	bool* visited;

	int  ArcNum;//������
	int     NodeNum;    //�ڵ�����
	GNode * MyGraph;    //�ڵ����� ͼ
public:
	CGraph(int vertices);
	~CGraph();

	int LocateVex(char GName);



	void CreateUndirectedGraph(int Nnum, GNode* g);                   //����һ������ͼ
	void DFSUndirectedGraph(int vertex);                        //���������������
	void BFSUndirectedGraph(int startVertex);                     //���������������
	void GetMiniCostSpanningTreeByKruskal();                     //Kruskal��С�������㷨
	void GetMiniCostSpanningTreeByPrim();                        //Prim��С�������㷨
	void GetMiniCostPathByDijistra(int Graph[MAX][MAX], char start, char target);     //Dijistra�㷨

	void GetMiniCostPathByInheritance(char start, char target);  //�Ŵ��㷨���Լ������ϣ�
	
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