/*
 * towerofhiwairecursive.cpp
 *
 *  Created on: 17-Dec-2021
 *      Author: acer
 */

#include<iostream>
#include<stdio.h>
using namespace std;
int tower(int n, int A,int B, int c)
{
	if(n>0)
	{
	tower(n-1, A , c, B);
	cout<<"from "<<A<<"to"<<c<<endl;
	tower(n-1, B , A, c);
	}
}
int main()
{
	tower(3,1,2,3);
}


