#include "BTree.h"
#include <iostream>
using std::cout;

// ���������������еݹ齨��
char xian[255];
char zhong[255];
int id = 0;
void CreateBTreeHelper(BNode*& root, int l, int r)
{
	if (l > r) 
		return;	//Ҷ�ӽڵ�
	root = new BNode;
	root->data = xian[id];

	int nowRoot;
	for (nowRoot = l; nowRoot <= r; ++nowRoot)  //�������������ҵ�ǰ�����ĸ�
		if (zhong[nowRoot] == xian[id])
			break;
	++id;
	CreateBTreeHelper(root->lchild, l, nowRoot - 1);
	CreateBTreeHelper(root->rchild, nowRoot + 1, r);
}

//�����鱾146ҳͼ6.24������
BNode * CreateBTree() 
{
	BNode* root = nullptr;
	id = 0;
	strcpy_s(xian, "ABECDFGHIJ");
	strcpy_s(zhong, "EBDCAFHIGJ");
	CreateBTreeHelper(root, 0, strlen("ABECDFGHIJ") - 1);
	
	return root;
}

//�����鱾155ҳͼ6.30������
int CreateBTree(BNode * root,int k, int end)
{
	id = 0;
	strcpy_s(xian, "ABCDEGF");
	strcpy_s(zhong, "CBEGDFA");
	CreateBTreeHelper(root, 0, strlen("ABCDEGF") - 1);

	return 0;
}

//ǰ�����
void ShowAllNodesByDLR(BNode * root)
{
	cout << root->data;
	if (root->lchild != NULL)
		ShowAllNodesByDLR(root->lchild);
	if (root->rchild != NULL)
		ShowAllNodesByDLR(root->rchild);
}

//�������
void ShowAllNodesByLDR(BNode * root)
{
	if(root->lchild != NULL)
		ShowAllNodesByDLR(root->lchild);
	cout << root->data;
	if (root->rchild != NULL)
		ShowAllNodesByDLR(root->rchild);
}

//��������
void ShowAllNodesByLRD(BNode * root)
{
	if (root->lchild != NULL)
		ShowAllNodesByDLR(root->lchild);
	if (root->rchild != NULL)
		ShowAllNodesByDLR(root->rchild);
	cout << root->data;
}

//���ٶ�����
void DeleteBTree(BNode * root)
{
	if (root->lchild != NULL)
		DeleteBTree(root->lchild);
	if (root->rchild != NULL)
		DeleteBTree(root->rchild);
	delete root;
}    