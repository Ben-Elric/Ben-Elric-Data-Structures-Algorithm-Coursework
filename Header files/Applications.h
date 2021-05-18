#ifndef __APPLICATIONS_H__
#define __APPLICATIONS_H__

#include "Array.h"
#include "ArrayStack.h"
#include "LinklistStack.h"

//����ʽ����1�����ؽ��
//a[]: ��Ŷ���ʽ�ĸ���ϵ��a[0]���λ����4x4+6x3-2.3x2+0x+2x0    ��Ӧ4 6 -2.3  0  2    nֵΪ5
//len�����鳤��   n:��ЧԪ�ظ���
//x������
//return:���ض���ʽ������
double  PolynomialFunc(double * a, int len, int n, double x);

//����ʽ����2�����ؽ��
//n: ����ʽ������ ��n=4  ���λ����x�����η�
//x�����λϵ��������ɱ������һ��Ϊ����ʽ�ĸ���ϵ��
//return:���ض���ʽ������
double  PolynomialFunc(int n, double x, ...);

//��ҵ2��������������� �����������š�
//����str�� �ַ���  �磺 1+2*3*(1+2)-4/(4/2)
//��� double�ͼ�����
double  FourMixedOperations(char * str);

//��ҵ2����ɽ���ת�� ʹ��ջ�Ľṹ��
//����int  17   188
//��� "0x11"
char *  DecToHexByRecursion(int a); //�ݹ�ķ�ʽ
char *  DecToHexByStack1(int a); //��ͨ����16 ѹջ�ķ�ʽ ��������ջ
char *  DecToHexByStack2(int a);  //��λ���� ѹջ ��ջ

#endif