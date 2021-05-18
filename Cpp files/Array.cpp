#include "Array.h"

//*****����һ��len���ȵ��������飬����������׵�ַ*****
int * cyf_CreateArray(int len)
{
	if(len <= 0)
		return nullptr;

	int * pnew = new int[len];
	memset(pnew, 0, sizeof(int)*len); //�����ʼ��Ϊ0

	return pnew;
}

//*****Ϊ���鸳n���������ֵ����ֵ��Χ1~1000*****
void  cyf_InitArray(int * a, int len, int n)
{
	if(a == nullptr || n <= 0)
	{
		return;
	}
	
	SYSTEMTIME t;
	GetLocalTime(&t);
	srand(t.wMilliseconds);  //�������������;
	
	n = (len >= n)?n:len; //�ж�n�Ƿ񳬳����鳤��
	
	for(int i=0;i<n;i++)
		a[i] = rand()%1000 + 1;
}

//*****��ʾ��������Ч����*****
void  cyf_ShowArray(int * a, int len, int n)
{
	if(a == nullptr || n <= 0)
	{
		return;
	}

    n = (len >= n)?n:len; //�ж�n�Ƿ񳬳����鳤��

	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


//*****������n������������--ð����������*****
void  cyf_SortArray_Maopao(int * a, int len, int n)
{
	if(a == nullptr || n <= 0)
	{
		return;
	}
	
    n = (len >= n)?n:len; //�ж�n�Ƿ񳬳����鳤��

	int i,j;
	int tmp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}

//*****����������ð�������ʱ�临�Ӷ�*********
int  cyf_SortArray_Maopao_TimeComplex(int * a, int len, int n)
{
    int count = 0;
	if(a == nullptr || n <= 0)
	{
		return 0;
	}
	
    n = (len >= n)?n:len; //�ж�n�Ƿ񳬳����鳤��
	
	int i,j;
	int tmp;
	for(i=0;i<n;i++)
	{
		count += 2; //i<n;i++ ��������
		for(j=0;j<n-i-1;j++)
		{
			count += 4;
			if(a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				count += 5;//3�θ�ֵ���� 2��+����
			}
			count += 2; //a[j] > a[j+1] �ȽϺ�+����
		}
	}
	return count;
}

//*****��ҵ1����һ��len���� n����Ч��������������a[0]~a[n-1]������ɾ��ָ����Ԫ�أ�Ҫ��ɾ����������Ȼ����*********
//len: ���鳤��    n: ��Ч���ָ���   m:Ҫɾ��������
//return: ����ɾ�����������Ч���ָ���  ��1 2 3 4 4 5 6 0 0 0 0  ɾ��4 ���:1 2 3 5 6 0 0 0 0 0 0
int cyf_DeleteElement(int * a, int len, int n, int m)
{
	int* st = a;

	//��ɾ���ο�ͷ
	while (*st != m)
		++st;
	if (st == a + (n + 1))
		return n;

	//��ɾ���ν�β
	int* en = st+1;
	while (*en == m)
		++en;
	len = en - st;

	//����
	int* oldp = st, * newp = en, * target = a + n + 1;
	while (newp != target)
		*oldp++ = *newp++;

	//��0
	while (oldp < en)
		*oldp++ = 0;

	return n-len;
}

//*****��ҵ2����һ��Ԫ����ӽ�����
//len: ���鳤��    n: ��Ч���ָ���   m:Ҫ��ӵ�����
//return: ������Ӻ��������Ч���ָ���  ��1 2 3 5 6 0 0 0 0  ���4 ���:1 2 3 4 5 6 0 0 0 0 0 
int cyf_AddElement(int * a, int len, int n, int m)
{
	if (n == len)
	{
		cout << "���������" << endl;
		return n;
	}

	int* pos = a;
	while (*pos < m)
		++pos;

	if (pos != a + (n + 1))	
	{
		int *target = pos-1;
		int *now = a + n;
		while (now != target)
		{
			*(now + 1) = *now;
			--now;
		}
	}
	*pos = m;
	return n+1;
}

//*****��ҵ3����һ��Ԫ����ӽ�����
//len: ���鳤��    n: ��Ч���ָ���   m:Ҫ��ӵ�����
//return: ������Ӻ�������׵�ַ  
//��a: 1 2 3 5 6 0 0 0 0  b: 3 7 0 0 0 0  ��Ӻ�: a: 1 2 3 3 4 5 6 7 0
//��a: 1 2 3 5 6 0 0 0 0  b: 3 7 8 9 9 9 9 0 0 0  ��Ӻ�: a: 1 2 3 3 4 5 6 7 8 9 9 9 9
void cyf_AddElement(int * & a, int & lena, int & na, int * b, int lenb, int nb)
{
	//���
	if (na + nb <= lena)
		for (int i = 0; i < nb; ++i)
			*(a + (na + i)) = *(b + i);
	else
	{
		int* newa = new int[na + nb];
		lena = na + nb;
		for (int i = 0; i < na; ++i)
			*(newa + i) = *(a + i);
		for (int i = 0; i < nb; ++i)
			*(newa + (na + i)) = *(b + i);
		a = newa;
	}
	na += nb;

	cyf_SortArray_Maopao(a, lena, na);
}