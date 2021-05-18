#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#define QUEUESIZE  100

template<class T>   //�½�һ��ģ����
class ArrayQueue
{
private:
	T   queue[QUEUESIZE];
	int head, tail;
	int cnt;

public:
	ArrayQueue<T>();
	~ArrayQueue<T>();

	int  GetQueueSize();   //��ȡ���еĹ�ģ
	int  GetQueueLength(); //��ȡ���е�Ԫ�ظ���
	T    pop();            //���Ӳ���
	void push(T t);        //��Ӳ���
};

template<class T>
ArrayQueue<T>::ArrayQueue()
{
	head = tail = 0;
	cnt = 0;
	memset(queue, 0, sizeof(T) * QUEUESIZE);
}

template<class T>
ArrayQueue<T>::~ArrayStack()
{
	;
}

template<class T>
int  ArrayQueue<T>::GetQueueLength()
{
	return cnt;
}


template<class T>
int  ArrayQueue<T>::GetQueueSize()
{
	return QUEUESIZE;
}

template<class T>
T  ArrayQueue<T>::pop()
{
	if (cnt == 0)
	{
		cout << "Queue is empty!" << endl;
		return 0;
	}

	T t = stack[head];
	head = (head + 1) % QUEUESIZE;
	--cnt;
	return t;
}

template<class T>
void ArrayQueue<T>::push(T t)
{
	if (cnt == QUEUESIZE)
	{
		cout << "Queue is full!" << endl;
		return;
	}
	tail = (tail + 1) % QUEUESIZE;
	queue[tail] = t;
	++cnt;
}

#endif