/*
 * addDisplayinsertarrayelement.cpp
 *
 *  Created on: 20-Dec-2021
 *      Author: acer
 */

#include<iostream>
#include<stdio.h>
using namespace std;
struct Array
{
	int A[20];
	int size;
	int length;
};
void display(struct Array a)
{
	cout<<"Elements are : ";
	for (int i=0; i<a.length;i++)
	{
		cout<<a.A[i]<<"  ";
	}
	cout<<endl;

}
void Append(struct Array *a ,int n)
{
	if (a->length > a->size)
	{
		a->A[a->length++]=n;
	}

}
void inser(struct Array *a ,int n, int index)
{
	if (a->length > a->size)
	{
	for(int i=a->size;i >index; i-- )
	{
		a->A[i]=a->A[i-1];
	}
	a->A[index]=n;
	}

}
int main()
{
	struct Array a={{1,2,3,4,5},10, 5};
	int index=4, n=8;
	display(a);
	Append(&a, n);
	display(a);
	inser(&a, n,index);
	display(a);

}


