/*
 * sumofnaturalnumber.cpp
 *
 *  Created on: 16-Dec-2021
 *      Author: acer
 */
#include<iostream>
#include<stdio.h>
using namespace std;
int sum1(int n)
{
	return n*(n+1)/2;
}
int sum(int n)
{
	if(n >0)
	{
		return n+sum(n-1);
	}
	return 0;

}
int sum2(int n)
{
	int sum=0;
	for(int i=10;i>0; i--)
	{
		sum=sum+i;
	}
	return sum;
}
int main()
{
	int n=10;
	printf("%d \n", sum(n));
	printf("%d \n", sum1(n));
	printf("%d \n", sum2(n));
}



