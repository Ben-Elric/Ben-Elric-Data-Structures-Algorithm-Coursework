#include "Applications.h"
#include <cstdarg>
#include <cstring>

//����ʽ����1�����ؽ��
//a[]: ��Ŷ���ʽ�ĸ���ϵ��a[0]���λ����4x4+6x3-2.3x2+0x+2x0    ��Ӧ4 6 -2.3  0  2    nֵΪ5
//len�����鳤��   n:��ЧԪ�ظ���
//x������
//return:���ض���ʽ������
double  PolynomialFunc(double * a, int len, int n, double x)
{
	double sum = 0;
	double xn = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		sum += xn * a[i];
		xn *= x;
	}

	return sum;
}

//����ʽ����2�����ؽ��
//n: ����ʽ������ ��n=4  ���λ����x�����η�
//x�����λϵ��������ɱ����������Ϊ����ʽ�ĸ���ϵ��
//return:���ض���ʽ������
double  PolynomialFunc(int n, double x, ...)
{
	double* ts = new double[n];

	va_list args;
	va_start(args, x);
	for (int i = 0; i < n; ++i)
		ts[i] = va_arg(args, double);
	va_end(args);

	double sum = PolynomialFunc(ts, n, n, x);
	delete[] ts;
	return sum;
}

//��ҵ2��������������� �����������š�
//����str�� �ַ���  �磺 1+2*3*(1+2)-4/(4/2)
//��� double�ͼ�����
bool doesCalc(char symbol_now, char symbol_stack)
{
	if (symbol_stack == '(')
		return false;

	else if (symbol_stack == '*' || symbol_stack == '/')
		return true;

	else if (symbol_stack == '+' || symbol_stack == '-')
	{
		if (symbol_now == '*' || symbol_now == '/')
			return false;
		else
			return true;
	}
	else
		return false;
}
double calc(double a,double b,char sym)
{
	switch (sym)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}
double  FourMixedOperations(char * str)
{
	double res = 0;
	ArrayStack<char> symbols;
	ArrayStack<double> nums;

	char *c = str;
	double nowNum = 0;
	do
	{
		if (*c >= '0' && *c <= '9')
			nowNum = nowNum * 10 + (*c - '0');
		else
		{
			nums.push(nowNum);
			nowNum = 0;
			switch (*c)
			{
			case '(':
				symbols.push('(');
				break;
			case ')':
				char nowSym;
				while ((nowSym = symbols.pop()) != '(')
				{
					nums.push(calc(nums.pop(),nums.pop(),symbols.pop()));
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				char stack_sym = symbols.pop();
				if (doesCalc(nowSym, stack_sym))
				{
					nums.push(calc(nums.pop(), nums.pop(), nowSym));
					symbols.push(stack_sym);
				}
				else
				{
					symbols.push(stack_sym);
					symbols.push(nowSym);
				}
				break;
			}
		}
	} while (*(++c) != '\0');

	while (symbols.GetStackLength() != 0)
	{
		char stack_sym = symbols.pop();
		if(stack_sym != '(')
			nums.push(calc(nums.pop(), nums.pop(), symbols.pop()));
	}

	return res;
}

//��ҵ2����ɽ���ת�� ʹ��ջ�Ľṹ��
//����int  17   188
//��� "0x11"
void DecToHexByRecursion_Help(int a,char *buf)
{
	static int nowIndex = 2;
	DecToHexByRecursion_Help(a / 16,buf);
	int res = a % 16;
	if (a < 10)
		buf[nowIndex++] = res + '0';
	else
		buf[nowIndex++] = res - 10 + 'A';

	if (a == 0)
		return;
}

char *  DecToHexByRecursion(int a) //�ݹ�ķ�ʽ
{
	char * p = new char[100];
	memset(p, 0, 100);
	p[0] = '0';
	p[1] = 'x';
	DecToHexByRecursion_Help(a, p);
	return p;
}
char *  DecToHexByStack1(int a) //��ͨ����16 ѹջ�ķ�ʽ ��������ջ
{
	char * p = new char[100];
	memset(p, 0, 100);
	p[0] = '0';
	p[1] = 'x';

	int nowIndex = 2;
	ArrayStack<int> stack;
	while (a > 0)
	{
		stack.push(a % 16);
		a /= 16;
	}
	while (stack.GetStackLength() != 0)
	{
		int res = stack.pop();
		if (res < 10)
			p[nowIndex++] = res + '0';
		else
			p[nowIndex++] = res - 10 + 'A';
	}
	return p;
}
char *  DecToHexByStack2(int a)  //��λ���� ѹջ ��ջ
{
	char* p = new char[100];
	memset(p, 0, 100);
	p[0] = '0';
	p[1] = 'x';

	int nowIndex = 2;
	LinklistStack<int> stack;
	while (a > 0)
	{
		stack.push(a % 16);
		a >>= 4;
	}
	while (stack.GetStackLength() != 0)
	{
		int res = stack.pop();
		if (res < 10)
			p[nowIndex++] = res + '0';
		else
			p[nowIndex++] = res - 10 + 'A';
	}
	return p;
}