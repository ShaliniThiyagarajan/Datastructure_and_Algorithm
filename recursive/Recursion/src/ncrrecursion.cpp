/*
 * ncrrecursion.cpp
 *
 *  Created on: 17-Dec-2021
 *      Author: acer
 */
#include<iostream>
#include<stdio.h>

using namespace std;

int fact1(int n)
{
	int fact =1;
	if(n>0)
	{
		for(int i=n; i>0;i--)
		{
			fact=fact*i;
		}
	}
	return fact;
}
int ncrbypascaltriangle(int n, int r)
{
	if(n==r||r==0)
		return 1;
	else
		return ncrbypascaltriangle(n-1,r-1)+ncrbypascaltriangle(n-1,r);
}
int main()
{
	int n, r;
	cin>>r;
	cin>>n;
	printf("%d \n", fact1(n)/(fact1(n-r)*fact1(r)));
	printf("%d \n", ncrbypascaltriangle(n,r));
}


