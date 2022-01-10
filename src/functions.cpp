/*
 * functions.cpp
 *
 *  Created on: 15-Dec-2021
 *      Author: acer
 */
#include <iostream>
#include<stdio.h>

using namespace std;
int add(int a, int b)// prototype or declaration a and b formal parameter
{
	int c;// definition of function
	c=a+b;
	return c;

}
int main()
{
	int x,y,z;// x,y and z actual parameter
	x=10;
	y=20;
	z=add(x,y);
	printf("sum is %d", z);

}



