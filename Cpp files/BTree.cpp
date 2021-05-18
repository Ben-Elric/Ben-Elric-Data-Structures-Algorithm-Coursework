#include "BTree.h"
#include <iostream>
using std::cout;

// 先序序列中序序列递归建树
char xian[255];
char zhong[255];
int id = 0;
void CreateBTreeHelper(BNode*& root, int l, int r)
{
	if (l > r) 
		return;	//叶子节点
	root = new BNode;
	root->data = xian[id];

	int nowRoot;
	for (nowRoot = l; nowRoot <= r; ++nowRoot)  //在中序序列中找当前子树的根
		if (zhong[nowRoot] == xian[id])
			break;
	++id;
	CreateBTreeHelper(root->lchild, l, nowRoot - 1);
	CreateBTreeHelper(root->rchild, nowRoot + 1, r);
}

//创建书本146页图6.24二叉树
BNode * CreateBTree() 
{
	BNode* root = nullptr;
	id = 0;
	strcpy_s(xian, "ABECDFGHIJ");
	strcpy_s(zhong, "EBDCAFHIGJ");
	CreateBTreeHelper(root, 0, strlen("ABECDFGHIJ") - 1);
	
	return root;
}

//创建书本155页图6.30二叉树
int CreateBTree(BNode * root,int k, int end)
{
	id = 0;
	strcpy_s(xian, "ABCDEGF");
	strcpy_s(zhong, "CBEGDFA");
	CreateBTreeHelper(root, 0, strlen("ABCDEGF") - 1);

	return 0;
}

//前序遍历
void ShowAllNodesByDLR(BNode * root)
{
	cout << root->data;
	if (root->lchild != NULL)
		ShowAllNodesByDLR(root->lchild);
	if (root->rchild != NULL)
		ShowAllNodesByDLR(root->rchild);
}

//中序遍历
void ShowAllNodesByLDR(BNode * root)
{
	if(root->lchild != NULL)
		ShowAllNodesByDLR(root->lchild);
	cout << root->data;
	if (root->rchild != NULL)
		ShowAllNodesByDLR(root->rchild);
}

//后续遍历
void ShowAllNodesByLRD(BNode * root)
{
	if (root->lchild != NULL)
		ShowAllNodesByDLR(root->lchild);
	if (root->rchild != NULL)
		ShowAllNodesByDLR(root->rchild);
	cout << root->data;
}

//销毁二叉树
void DeleteBTree(BNode * root)
{
	if (root->lchild != NULL)
		DeleteBTree(root->lchild);
	if (root->rchild != NULL)
		DeleteBTree(root->rchild);
	delete root;
}    