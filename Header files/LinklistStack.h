#ifndef __LINKLISTSTACK_H__
#define __LINKLISTSTACK_H__

#define STACKSIZE  100

template<class T>   //�½�һ��ģ����
class LinklistStack
{
private:
	struct node
	{
		T data;
		node* next;
	};
	node* stack;

public:
	LinklistStack<T>();
	~LinklistStack<T>();

	bool IsStackEmpty();   //��ȡջ�Ƿ�Ϊ��
	int  GetStackLength(); //��ȡջ��Ԫ�ظ���
	T    pop();            //��ջ����
	void push(T t);        //��ջ����
};

template<class T>
LinklistStack<T>::LinklistStack()
{
	//����Ϊͷָ��
	stack = new node;
	stack->next = NULL;
}

template<class T>
LinklistStack<T>::~LinklistStack()
{
	while (!IsStackEmpty())
		pop();
}

template<class T>
int  LinklistStack<T>::GetStackLength()
{
	node* now = stack->next;
	int cnt = 0;
	while (now != NULL)
	{
		++cnt;
		now = now->next;
	}
	return cnt;
}


template<class T>
bool  LinklistStack<T>::IsStackEmpty()
{
	return stack->next == NULL;
}

template<class T>
T  LinklistStack<T>::pop()
{
	if (IsStackEmpty())
	{
		cout << "Stack is empty!" << endl;
		return 0;
	}

	T t = stack->next->data;
	node* del = stack->next;
	stack->next = stack->next->next;
	delete del;
	return t;
}

template<class T>
void LinklistStack<T>::push(T t)
{
	node* p = new node;
	p -> data = t;
	p -> next = stack->next->next;
	stack->next = p;
}

#endif