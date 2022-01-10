/*
 * PointerArray.cpp
 *
 *  Created on: 15-Dec-2021
 *      Author: acer
 */
#include<iostream>
using namespace std;
struct Rectangle
{
	int length;
	int breadth;
};

int main()
{
	int A[5]={1,2,3,4,5};
	int *p=A;
	int *q;
	q=(int *)malloc(5*sizeof(int));
	q[0]=10;
	q[1]=9;
	struct Rectangle *R;
	cout<<A[0]<<endl;
	cout<<p<<endl;
	for (int i=0; i<5 ;i++)
	{
		cout<<A[i]<<endl;
		// value of a
		cout<<p[i]<<endl;
	}
	for (int i=0; i<5 ;i++)
		{

			// value of a
			cout<<q[i]<<endl;
		}
	//all pointer will take same 8 byte independent of the datatype
	cout<<sizeof(p)<<endl;
	cout<<sizeof(q)<<endl;
	cout<<sizeof(R)<<endl;
	delete[]p;//clear or deallocate the pointer in cpp
	free(q);//clear or deallocate the point in c
	cout<<"p value is :"<<p;




	return 0;
}



