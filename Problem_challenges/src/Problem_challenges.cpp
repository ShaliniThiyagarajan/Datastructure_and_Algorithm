//============================================================================
// Name        : Problem_challenges.cpp
// Author      : Shalini
// Version     :
// Copyright   : Your copyright notice
// Description : Problems
//============================================================================

#include<iostream>
#include<stdio.h>
using namespace std;
struct Array
{
	int A[20];
	int size;
	int length;
};
void display(struct Array a)
{
	cout<<"Elements are : ";
	for (int i=0; i<a.length;i++)
	{
		cout<<a.A[i]<<"  ";
	}
	cout<<endl;

}
// Finding missing number with o(n^2) time complexity
struct Array* missing_number(struct Array *a)
{
	int l=a->A[0];
	int h=a->A[a->length];
	int dif= l;
	int k=0;
	struct Array *a1=(struct Array *)malloc(sizeof(struct Array));
	for(int i=1,j=1; i<a->length;i++,j++)
	{
		int diff1=a->A[i]-i;
		if(dif!=diff1)
		{
			while(j+dif<a->A[i])
			{
			a1->A[k]=dif+j;
			k++;
			j++;
			}
		}
	}
	a1->length=k;
	a1->size=10;
	return a1;

}
// missing number with o(n) time complexity and o(n) space complexity
void  missing_number_2(struct Array *a)
{
	int h=a->A[a->length-1];
	struct Array *a1=(struct Array *)malloc(sizeof(struct Array));
	for(int i=0; i<a->length;i++)
	{

		a1->A[a->A[i]] =1;
	}
	cout<<"Elements are:"<<endl;

	for(int i=1;i<h;i++)
	{

		if(a1->A[i]!= 1)
			cout<<i<<" ";
	}
	cout<<endl;
}
// Finding duplicate and count the duplicate in the sorted array o(n) complexity
void duplicate_count(struct Array *a)
{
	int lastduplicate,count;
	lastduplicate=count=0;
	cout<<"duplicate elements are:"<<endl;
	for (int i=0; i<a->length; i++)
	{
		if(a->A[i]== a->A[i+1] &&  a->A[i] != lastduplicate)
		{
			cout<<a->A[i]<<" ";
			lastduplicate=a->A[i];
			count++;
		}
	}
	cout<<endl;
	cout<<"Number of duplicate are"<<" ";
	cout<<count<<endl;

}
// Finding duplicate and count the number of times duplicate element  in the sorted array
void number_of_time_duplicate(struct Array *a)
{
	int j=0,res=0;
	for(int i=0;i<a->length-1;i++)
	{
		int count=1;
		if(a->A[i]==a->A[i+1])
		{
			cout<<a->A[i]<<" occurs ";
			j=i+1;
			while(a->A[i]==a->A[j])
			{
				j++;
				count++;
			}
			cout<<count<<"  times"<<endl;
			res++;
		}

	}
	cout<<"Total number of duplicates are "<<res<<endl;
}
// duplicate number with hashing, o(n) time complexity and o(n) space complexity in sorted array
void  number_of_time_duplicate1(struct Array *a)
{
	int h=a->A[a->length-1];
	int count=0;
	struct Array *a1=(struct Array *)malloc(sizeof(struct Array));
	for(int i=0; i<a->length;i++)
	{

		a1->A[a->A[i]]++;
	}
	cout<<"Elements are:"<<endl;


	for(int i=0;i<=h;i++)
	{
		if(a1->A[i]> 1)
		{
			cout<<i<<" occurs "<<a1->A[i]<<"  times"<<endl;
			count++;
		}
	}
	cout<<"Total number of duplicates are "<<count<<endl;
}
// Maximum of the array elements
int maximum(struct Array *a)
{
	int max=0;
	for(int i=0; i<a->length; i++)
	{
		if (max<a->A[i])
			max=a->A[i];
	}
	return max;
}
// duplicate number with hashing, o(n) time complexity and o(n) space complexity in unsorted array
void  number_of_time_duplicate3(struct Array *a)
{
	int h=maximum(a);
	int count=0;
	struct Array *a1=(struct Array *)malloc(sizeof(struct Array));
	for(int i=0; i<a->length;i++)
	{

		a1->A[a->A[i]]++;
	}
	cout<<"Elements are:"<<endl;


	for(int i=0;i<=h;i++)
	{
		if(a1->A[i]> 1)
		{
			cout<<i<<" occurs "<<a1->A[i]<<"  times"<<endl;
			count++;
		}
	}
	cout<<"Total number of duplicates are "<<count<<endl;
}
// Finding duplicate and count the number of times duplicate element  in the unsorted array
void  number_of_time_duplicate4(struct Array *a)
{
	cout<<"Elements are:"<<endl;
	int res=0;
	for(int i=0; i<a->length;i++)
	{
		int count=1;
		for(int j=i+1;j<=a->length;j++)
			{
				if (a->A[i]==a->A[j] && a->A[i]>=0)
				{
					count++;
					a->A[j]=-1;

				}
			}

		if(count> 1)
		{
			cout<<a->A[i]<<" occurs ";
			cout<<count<<"  times"<<endl;
			res++;
		}
	}
	cout<<"Total number of duplicates are "<<res<<endl;
}
// finding pair of element sum is k with unsorted array
void  pair_element(struct Array *a, int k)
{
	int count=0;
	for(int i=0; i<a->length;i++)
	{

		for(int j=i+1;j<a->length;j++)
			{
				if (a->A[i]+a->A[j]==k)
				{
					cout<<"Pair of two element which has sum as  "<<k<<" is "<< a->A[i] <<" and "<<a->A[j]<<endl;
					count++;

				}
			}


	}
	cout<<"Total number of pairs are "<<count<<endl;
}
//finding pair of element sum is k using hashtable o(n) time complexity with unsorted array
void  pair_element_hashing(struct Array *a, int k)
{
	int h=maximum(a);
	int count=0;
	struct Array *a1=(struct Array *)malloc(sizeof(struct Array));
	for(int i=0; i<a->length;i++)
	{

		a1->A[a->A[i]]++;
	}
	cout<<"Elements are:"<<endl;


	for(int i=0;i<a->length;i++)
	{
		if(a1->A[k-a->A[i]]!=0  )
		{
			cout<<"Pair of two element which has sum as  "<<k<<" is "<< a->A[i] <<" and "<<k-a->A[i]<<endl;
			count=count+a1->A[ a->A[i] ];
		}

	}
	cout<<"Total number of pairs are "<<count<<endl;
}
// finding the pair with sorted array
void pair_of_sorted(struct Array *a, int k)
{
	int i=0, j=a->length-1,count=0;
	while(i<j)
	{

		int sum=a->A[i]+a->A[j];
		if(sum==k)
		{
			cout<<"Pair of two element which has sum as  "<<k<<" is "<< a->A[i] <<" and "<<k-a->A[i]<<endl;
			count++;
			i++;
			j--;
		}
		else if (sum>k)
		{
			j--;
		}
		else if(sum<k)
			i++;
	}
	cout<<"Total number of pairs are "<<count<<endl;
}
int main() {
	struct Array a={{1,2,3,4,5,9,9,15,15},10, 9};
	struct Array a2={{1,8,3,8,5,9,9,15,15},10, 9};
	struct Array a3={{1,8,3,8,5,9,9,15,15},10, 9};
	struct Array a4={{1,2,3,4,5,9,9,15,15},10, 9};
	struct Array *a1;
	a1=missing_number(&a);
	display(*a1);
	missing_number_2(&a);
	duplicate_count(&a);
	number_of_time_duplicate(&a);
	number_of_time_duplicate1(&a);
	number_of_time_duplicate3(&a2);
	number_of_time_duplicate4(&a2);
	pair_element(&a3, 8);
	pair_element_hashing(&a,8);
	pair_of_sorted(&a4,8);
}
