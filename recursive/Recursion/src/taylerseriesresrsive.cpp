/*
 * taylerseriesresrsive.cpp
 *
 *  Created on: 17-Dec-2021
 *      Author: acer
 */
#include<iostream>
#include<stdio.h>
using namespace std;
double tayler(double x, double n)
{
	static double p=1, f=1;
	double r=1;
	if (n==0)
	{
		return 1;

	}
	else
	{
		r=tayler(x,n-1);
		p=p*x;
		f=f*n;
		return r+(p/f);
	}
}
double tayler1(double m, double n)
{
	double s=1, num=1, dem=1;
	for(int i=1; i<n;i++)
	{
		num=m*num;
		dem=dem*i;
		s=s+((num/dem));
	}
	return s;
}
int main()
{
	double n;
	double x;
	cin>>n;
	cin>>x;
	printf("%lf \n", tayler(x,n));
	printf("%lf \n", tayler1(x,n));
	return 0;

}



