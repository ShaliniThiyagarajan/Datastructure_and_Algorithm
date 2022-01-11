/*
 * Allfunctiontogether.cpp
 *
 *  Created on: 10-Jan-2022
 *      Author: shalini
 */


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
// Append the value in the last
void Append(struct Array *a ,int n)
{
	if (a->length > a->size)
	{
		a->A[a->length++]=n;
	}

}
// insert in the particular index
void inser(struct Array *a ,int n, int index)
{
	if (a->length > a->size)
	{
	for(int i=a->size;i >index; i-- )
	{
		a->A[i]=a->A[i-1];
	}
	a->A[index]=n;
	}

}
// Linear search
int linearsearch(struct Array *a, int n)
{
	for(int i=0; i<a->length; i++)
	{
		if (a-> A[i]== n)
			return i;
	}
	return -1;
}
// Swap two number
void swap(int *a,int *b)
{
	int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
}
// bring to front in linear search
int bringfront_linearsearch(struct Array *a, int n)
{
	for(int i=0; i<a->length; i++)
	{
		if (a-> A[i]== n)
		{
			swap(&a->A[i],&a->A[0]);
			return i;
		}
	}
	return -1;
}
// Transposition in linear search bring one step front
int trans_linearsearch(struct Array *a, int n)
{
	for(int i=0; i<a->length; i++)
	{
		if (a-> A[i]== n)
		{
			swap(&a->A[i],&a->A[i-1]);
			return i;
		}
	}
	return -1;
}
//binary search, which can be done only with sorted array
int binarysearch(struct Array *a, int n)
{
	int mid,l,h;
	l=0;
	h=a->length;
	while(l<=h)
	{
		mid=int((h+l)/2);
		if (n==a->A[mid])
			return(mid);
		else if (n<a->A[mid])
			h=mid;
		else if(n>a->A[mid])
			l=mid;
	}
	return -1;
}
// get the element from index
int get(struct Array *a, int index)
{
	if (index>=0 && index<a->length)
		return a->A[index];
	else
		return -1;
}
//set the element in the index
int set(struct Array *a, int index, int value)
{
	if (index>=0 && index<a->length)
	{
		a->A[index]=value;
	}
	else
		return -1;
}
// Average of the array elements
int average(struct Array *a)
{
	int sum=0;
	for(int i=0; i<a->length; i++)
	{
		sum=sum+a->A[i];
	}
	return (sum/a->length);
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
//Minimum of the array elements
int minimum(struct Array *a)
{
	int min=a->A[0];
	for(int i=1; i<a->length; i++)
	{
		if (min>a->A[i])
			min=a->A[i];
	}
	return min;
}
//reverse of the array elements
void reverse(struct Array *a)
{
	int i,j;
	int *B;
	B=(int *)malloc(a->length*sizeof(int));
	for (i=a->length-1,j=0;i>=0;i--,j++)
	{
		B[j]=a->A[i];
	}
	for(i=0;i<a->length;i++)
	{
		a->A[i]=B[i];
	}

}
//another way reverse an array
void reverse_n(struct Array *a)
{
	int l,mid, h;
	l=0;
	h=a->length;
	mid=(l+h)/2;
	for(int i=0, j=a->length-1; i<mid;i++,j--)
	{
		swap(&a->A[i],&a->A[j]);
	}
}


//merging sorted  array
struct Array* merging(struct Array *a,struct Array *a1)
{
	int i,j,k;
	i=j=k=0;
	struct Array *a2=(struct Array *)malloc(sizeof(struct Array));
	while(i<a->length &&  j<a1->length)
	{
		if(a->A[i]<a1->A[j])
			a2->A[k++]=a->A[i++];
		else
			a2->A[k++]=a1->A[j++];

	}

	for(;i<a->length;i++)
		a2->A[k++]=a->A[i];
	for(;j<a1->length;j++)
		a2->A[k++]=a1->A[j];

	a2->length=a->length+a1->length;
	a2->size=20;
	return a2;


}
//union of two sorted array
struct Array* union_sorted(struct Array *a,struct Array *a1)
{
	int i,j,k;
	i=j=k=0;
	struct Array *a2=(struct Array *)malloc(sizeof(struct Array));
	while(i<a->length &&  j<a1->length)
	{
		if(a->A[i]<a1->A[j])
			a2->A[k++]=a->A[i++];
		else if(a->A[i]>a1->A[j])
			a2->A[k++]=a1->A[j++];
		else
		{
			a2->A[k++]=a->A[i++];
			j++;
		}
	}

	for(;i<a->length;i++)
		a2->A[k++]=a->A[i];
	for(;j<a1->length;j++)
		a2->A[k++]=a1->A[j];
	a2->length=k;
	a2->size=20;
	return a2;
}
//intersection of two sorted array
struct Array* intersection_sorted(struct Array *a,struct Array *a1)
{
	int i,j,k;
	i=j=k=0;
	struct Array *a5=(struct Array *)malloc(sizeof(struct Array));
	while(i<a->length &&  j<a1->length)
	{
		if(a->A[i]<a1->A[j])
			i++;
		else if(a->A[i]>a1->A[j])
			j++;
		else
		{
			a5->A[k++]=a->A[i++];
			j++;
		}
	}

	a5->length=k;
	a5->size=20;
	return a5;
}

//union of two unsorted array
struct Array* union_unsorted(struct Array *a,struct Array *a1)
{
	int i,j,k;
	i=j=k=0;

	struct Array *a4=(struct Array *)malloc(sizeof(struct Array));
	for(;i<a1->length;i++)
	{
		a4->A[k++]=a->A[i];
	}
	for(;j<a1->length;j++)
	{
		int flag = 1;
		for(i=0;i<a->length;i++)
		{
			if(a1->A[j]==a->A[i])
			{
				flag =0;
				break;
			}

		}

		if(flag==1)
		{
			a4->A[k++]=a1->A[j];
		}
	}
	a4->length=k;
	a4->size=20;
	return a4;


}
//intersection of two unsorted array
struct Array* intersection_unsorted(struct Array *a,struct Array *a1)
{
	int i,j,k;
	i=j=k=0;

	struct Array *a6=(struct Array *)malloc(sizeof(struct Array));

	for(;j<a1->length;j++)
	{
		int flag = 0;
		for(i=0;i<a->length;i++)
		{
			if(a1->A[j]==a->A[i])
			{
				flag =1;
				break;
			}

		}

		if(flag==1)
		{
			a6->A[k++]=a1->A[j];
		}
	}
	a6->length=k;
	a6->size=20;
	return a6;


}
//difference of two unsorted array the element in array 2 should not be there in array 1
struct Array* difference_unsorted(struct Array *a,struct Array *a1)
{
	int i,j,k;
	i=j=k=0;

	struct Array *a7=(struct Array *)malloc(sizeof(struct Array));

	for(;j<a1->length;j++)
	{
		int flag = 1;
		for(i=0;i<a->length;i++)
		{
			if(a1->A[j]==a->A[i])
			{
				flag =0;

			}

		}

		if(flag==1)
		{
			a7->A[k++]=a1->A[j];
		}
	}
	a7->length=k;
	a7->size=20;
	return a7;


}
//Delete a element in array
void delete1(struct Array *a ,int index)
{
	for(int i=index;i <a->length; i++)
	{
		a->A[i]=a->A[i+1];
	}

}
int main()
{
	struct Array a={{1,2,3,4,5},10, 5};
	struct Array a1={{1,2,3,14,15},10, 5};
	struct Array *a2,*a3,*a4,*a5,*a6,*a7;
	int index, n;
	cout<<"Menu"<<endl;
	cout<<"1. Display the array"<<endl;
	cout<<"2. Append the array"<<endl;
	cout<<"3. Insert the array"<<endl;
	cout<<"4. Reverse the array in method1"<<endl;
	cout<<"5. Reverse the array with method2"<<endl;
	cout<<"6. Delete the element"<<endl;
	cout<<"7. Union of two sorted array"<<endl;
	cout<<"8. Union of two unsorted array"<<endl;
	cout<<"9. Difference of element in the array(the element in array 2 should not be there in array 1)"<<endl;
	cout<<"10. Intersection of two unsorted  array"<<endl;
	cout<<"11. Intersection of two sorted  array"<<endl;
	cout<<"12. Linear search of element in the array"<<endl;
	cout<<"13. Binary search of element in the array"<<endl;
	cout<<"14. Linear search of element in the array and display new array with found element one step before"<<endl;
	cout<<"15. Linear search of element in the array and display new array with found element bring front"<<endl;
	cout<<"16. Get index of the element in array"<<endl;
	cout<<"17. set a value to index in the array"<<endl;
	cout<<"18. Average of the element in the array"<<endl;
	cout<<"19. Maximum number in the array"<<endl;
	cout<<"20. Minimum number in the array"<<endl;
	cout<<"21. Merge two array"<<endl;

	cout<<"Enter user choice"<<endl;
	cin>>a;


	switch(a)
	{
	case 1 :
			cout<<"Displaying the  array elements"<<endl;
			display(a);
			break;
	case 2 : cout<<"Enter the value to be appended"<<endl;
			cin>>n;
			cout<<"Displaying the element appended array"<<endl;
			Append(&a, n);
			display(a);
			break;
	case 3 : cout<<"Enter the index and value"<<endl;
			cin>>index;
			cin>>n;
			cout<<"Displaying  the inserted array"<<endl;
			inser(&a, n,index);
			display(a);
			break;
	case 4 :
			cout<<"Dispalying reversed array in method1"<<endl;
			reverse(&a);
			display(a);
			break;
	case 5 :
			cout<<"Dispalying reversed array in method2"<<endl;
			reverse_n(&a);
			display(a);
			break;
	case 6 :  cout<<"Enter the index "<<endl;
			cin>>index;
			cout<<"Displaying  the element deleted array"<<endl;
			delete1(&a, index);
			display(a);
			break;
	case 7 :
				cout<<"Displaying  the union with  unsorted two array""<<endl;
				a4 = union_unsorted(&a,&a1);
				display(*a4);
				break;
	case 8 :
			cout<<"Displaying  the union with  sorted two array""<<endl;
			a3 = union_sorted(&a,&a1);
			display(*a3);
			break;
	case 9 :
			cout<<"Displaying the difference of element in the array(the element in array 2 should not be there in array 1)"<<endl;
			a7 = difference_unsorted(&a,&a1);
			display(*a7);
			break;
	case 10 :
				cout<<"Displaying the intersection of two unsorted array"<<endl;
				a6 = intersection_sorted(&a,&a1);
				display(*a6);
				break;

	case 11 :
			cout<<"Displaying the intersection of two sorted array"<<endl;
			a5 = intersection_sorted(&a,&a1);
			display(*a5);
			break;
	case 12 :  cout<<"Enter the value to search "<<endl;
				cin>>n;
				cout<<"Displaying the linear search index of element in the array"<<endl;
				int res=linearsearch(&a, n);
				cout<<res<<endl;
				break;
	case 13 :  cout<<"Enter the value to search "<<endl;
				cin>>n;
				cout<<"Displaying  Binary search index of element in the array"<<endl;
				int res3=binarysearch(&a, n);
				cout<<res3<<endl;
				break;

	case 14:  cout<<"Enter the value to search "<<endl;
				cin>>n;
				cout<<"Displaying  Linear search index of element in the array and display new array with found element one step before"<<endl;
				int res1=trans_linearsearch(&a, n);
				cout<<res1<<endl;
				display(a);
				break;
	case 15 :  cout<<"Enter the value to search "<<endl;
				cin>>n;
				cout<<"Displaying  the linear search index of element in the array and new array with found element bring front"<<endl;
				int res2=bringfront_linearsearch(&a, n);
				cout<<res2<<endl;
				display(a);
				break;


	case 16 :cout<<"Enter the index "<<endl;
			cin>>n;
			cout<<"Displaying the value in the index"<<endl;
			cout<<get(&a, n)<<endl;
			break;
	case 17 :  cout<<"Enter the index and value  "<<endl;
				cin>>index;
				cin>>n;
				cout<<"Displaying the new array with set value"<<endl;
				set(&a, index, n);
				display(a);
				break;
	case 18 :
				cout<<"Displaying  Average of number in array"<<endl;
				 cout<<average(&a)<<endl;
				break;

	case 19:
			cout<<"Displaying  Maximum  of number in array"<<endl;
			cout<<maximum(&a)<<endl;
			break;

	case 20 : cout<<"Displaying  Minimum  of number in array"<<endl;
			cout<<minimum(&a)<<endl;
			break;
	case 21 :
					cout<<"Displaying  the new array merged of two array"<<endl;
					a2=merging(&a,&a1)
					display(*a2);
					break;



	}



}
