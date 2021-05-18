#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#define STACKSIZE  100

template<class T>   //新建一个模板类
class ArrayStack
{
private:
	T   stack[STACKSIZE]; 
	int top;
	int base;
	
public:
	ArrayStack<T>();
	~ArrayStack<T>();

	int  GetStackSize();   //获取栈的规模
	int  GetStackLength(); //获取栈的元素个数
	T    pop();            //出栈操作
	void push(T t);        //入栈操作
};

template<class T>
ArrayStack<T>::ArrayStack()
{
	top = -1;
	memset(stack,0,sizeof(T)*STACKSIZE);
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
	;
}

template<class T>
int  ArrayStack<T>::GetStackLength()
{
	return top+1;
}


template<class T>
int  ArrayStack<T>::GetStackSize()
{
	return STACKSIZE;
}

template<class T>
T  ArrayStack<T>::pop()
{
	if(top == -1)
	{
		cout<<"stack is empty!"<<endl;
		return 0;
	}

	T t = stack[top--];

	return t;
}

template<class T>	
void ArrayStack<T>::push(T t)
{
	if(top == STACKSIZE-1)
	{
		cout<<"stack is full!"<<endl;
		return;
	}
	stack[++top] = t;
}

#endif