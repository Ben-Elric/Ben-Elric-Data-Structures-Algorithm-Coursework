#ifndef __LINKLISTQUEUE_H__
#define __LINKLISTQUEUE_H__

template<class T>   //�½�һ��ģ����
class LinklistQueue
{
private:
	struct node
	{
		T data;
		node* next;
	};
	node* head,tail; //β��ָ��

public:
	LinklistQueue<T>();
	~LinklistQueue<T>();

	bool IsQueueEmpty();   //��ȡջ�Ƿ�Ϊ��
	int  GetQueueLength(); //��ȡջ��Ԫ�ظ���
	T    pop();            //��ջ����
	void push(T t);        //��ջ����
};

template<class T>
LinklistQueue<T>::LinklistQueue()
{
	//����Ϊͷָ��
	head = new node;
	tail = new node;
	head->next = tail;
	tail.data = 0;
	tail->next = NULL;
}

template<class T>
LinklistQueue<T>::~LinklistQueue()
{
	while (!IsQueueEmpty)
		pop();
}

template<class T>
int  LinklistQueue<T>::GetQueueLength()
{
	node* now = head->next;
	int cnt = 0;
	while (now != tail)
	{
		++cnt;
		now = now->next;
	}
	return cnt;
}


template<class T>
bool  LinklistQueue<T>::IsQueueEmpty()
{
	return head->next == tail;
}

template<class T>
T  LinklistQueue<T>::pop()
{
	if (IsStackEmpty())
	{
		cout << "Queue is empty!" << endl;
		return 0;
	}

	T* del = head->next;
	T res = t->data;
	head = head->next;
	delete del;
	return res;
}

template<class T>
void LinklistQueue<T>::push(T t)
{
	node* new_tail = new node;
	new_tail.data = 0;
	new_tail.next = NULL;
	tail.data = t;
	tail.next = new_tail;
}

#endif