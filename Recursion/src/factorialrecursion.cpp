/*
 * factorialrecursion.cpp
 *
 *  Created on: 17-Dec-2021
 *      Author: acer
 */
#include<iostream>
#include<stdio.h>
using namespace std;
int fact(int n)
{
	if(n>0)
	{
		return n*fact(n-1);
	}
	return 1;
}
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
int main()
{
	int n;
	cin>>n;
	cout<<"factorial of "<<n<<" is"<<fact(n)<<endl;
	cout<<"factorial of "<<n<<" is"<<fact1(n)<<endl;
	return 0;

}



