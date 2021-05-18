#ifndef __BTREE_H__
#define __BTREE_H__

struct BNode
{
	char data;
	BNode * lchild;
	BNode * rchild;
	BNode()
	{
		lchild = rchild = nullptr;
	}
};

BNode * CreateBTree(); //创建书本146页图6.24二叉树
int     CreateBTree(BNode * root,int k, int end); //创建书本155页图6.30二叉树
void    ShowAllNodesByDLR(BNode * root);//前序遍历
void    ShowAllNodesByLDR(BNode * root);//中序遍历
void    ShowAllNodesByLRD(BNode * root);//后续遍历
void    DeleteBTree(BNode * root);      //销毁二叉树

#endif