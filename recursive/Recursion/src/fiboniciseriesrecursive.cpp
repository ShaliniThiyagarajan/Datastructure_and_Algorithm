/*
 * fiboniciseriesrecursive.cpp
 *
 *  Created on: 17-Dec-2021
 *      Author: acer
 */

#include<iostream>
#include<stdio.h>
using namespace std;

int fibanic(int n)
{
	if(n<=1)
		return n;
	return fibanic( n-1)+fibanic( n-2);

}
int fibanic1(int n)
{
	int t1=0,t2=1,f;
	if(n<=1)
	{
		return n;
	}
	for(int i=2;i<=n;i++)
	{
		f=t1+t2;
		t1=t2;
		t2=f;
	}
	return f;
}
int f[10];
int fibanici(int n)
{

 if(n<=1)
 {

	 f[n]=n;
	 return n;
 }
 else
 {
 if(f[n-1]==-1)
 {

	 f[n-1]=fibanici(n-1);
 }
 if(f[n-2]==-1)
  {

 	 f[n-2]=fibanici(n-2);
  }
 f[n]=f[n-2]+f[n-1];
 return f[n-1]+f[n-2];
 }
}

int main()
{

	int n;
	cin>>n;

	for (int i=0;i<10;i++)
		f[i]=-1;

	cout<<"fibonacci series of "<<n<<" is "<<fibanic1(n)<<endl;
	cout<<"fibonacci series of "<<n<<" is "<<fibanici(n)<<endl;
	cout<<"fibonacci series of "<<n<<" is "<<fibanic(n);
}



