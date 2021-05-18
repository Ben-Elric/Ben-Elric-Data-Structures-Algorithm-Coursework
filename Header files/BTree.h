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

BNode * CreateBTree(); //�����鱾146ҳͼ6.24������
int     CreateBTree(BNode * root,int k, int end); //�����鱾155ҳͼ6.30������
void    ShowAllNodesByDLR(BNode * root);//ǰ�����
void    ShowAllNodesByLDR(BNode * root);//�������
void    ShowAllNodesByLRD(BNode * root);//��������
void    DeleteBTree(BNode * root);      //���ٶ�����

#endif