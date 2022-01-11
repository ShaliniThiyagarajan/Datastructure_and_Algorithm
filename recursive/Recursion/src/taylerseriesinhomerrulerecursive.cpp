/*
 * taylerseriesinhomerrulerecursive.cpp
 *
 *  Created on: 17-Dec-2021
 *      Author: acer
 */
#include<iostream>
#include<stdio.h>
using namespace std;
double tayler(double x, double n)
{
	static double s;
	if(n==0)
	{
		return s;
	}

		s=(1+x*s/n);
		return tayler(x,n-1);

}
double tayler1(double x, double n)
{
	static double s=1;
	for (;n>0;n--)
	{
		s=(1+x*s/n);
	}
	return s;
}
int main()
{
	double x, n;
	cin>>x;
	cin>>n;
	printf("%lf \n", tayler(x, n));
	printf("%lf \n", tayler1(x, n));
}



