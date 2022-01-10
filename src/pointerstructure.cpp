/*
 * pointerstructure.cpp
 *
 *  Created on: 15-Dec-2021
 *      Author: acer
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;// which helps for cout and cin libs usage

struct Rectangle
{
	int length;
	int breadth;
};

int main()
{
	struct Rectangle r={10,5};// can intailize in cpp without struct , struct is mandatory in c
	cout<<r.length<<endl;
	cout<<r.breadth<<endl;

	Rectangle *p=&r;
	cout<<p->length<<endl;
	cout<<p->breadth<<endl;

	Rectangle *q;
	q=(struct Rectangle *)malloc(sizeof(struct Rectangle));// malloc take the size of structure
	q->breadth=10;
	cout<<q->breadth<<endl;



}
