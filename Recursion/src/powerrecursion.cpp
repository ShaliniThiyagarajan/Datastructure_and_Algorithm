/*
 * powerrecursion.cpp
 *
 *  Created on: 17-Dec-2021
 *      Author: acer
 */
#include<iostream>
#include<stdio.h>
using namespace std;
int pow(int m, int n)
{
	if(n>0){
		return pow(m,n-1)*m;
	}
	return 1;
}
int pow1(int m, int n)
{
	int power=1;
	for (int i=0;i<n;i++)
	{
		power=power*m;
	}
	return power;

}
int pow2(int m, int n)
{
	if(n%2==0){
		return pow(m*m,n/2);
	}
	if (n==0){
		return 1;
	}
	else{
			return m*pow(m*m,(n-1)/2);
		}
}
int main()
{
	int m,n;
	cin>>m;
	cin>>n;
	cout<<"power"<< m<<","<< n <<" is"<<pow1(m,n)<<endl;
	cout<<"power"<< m<<","<< n <<" is"<<pow(m,n)<<endl;
	cout<<"power"<< m<<","<< n <<" is"<<pow2(m,n)<<endl;


}

