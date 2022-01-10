/*
 * passbyreference.cpp
 *
 *  Created on: 15-Dec-2021
 *      Author: acer
 */

#include<iostream>
#include<stdio.h>
using namespace std;

void swap(int &x, int &y)// call by reference , cpp only will do, swap will become the part of the function in the case of callby reference
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}

int main()
{
	int a,b;
	a=10;
	b=20;
	swap(a,b);
	cout<<b<<endl;
	cout<<a<<endl;
}



