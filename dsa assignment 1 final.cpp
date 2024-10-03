/*
Problem Statement:
Consider a student database of SEIT class (at least 15 records). 
Database contains different fields of 
every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in 
 ascending order (Use Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class.
 (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA,
 then print list 
 of all students having same SGPA.
e) Search a particular student according to name using binary search without
 recursion. (all the student records having the presence of search key should be 
 displayed)
 (Note: Implement either Bubble sort or Insertion Sort.)
*/
#include <iostream>
#include <string.h>
using namespace std;
int const size=3;
struct student
{
	int rno;
	char name[20];
	float SGPA;
};
void accept(struct student list [size]);//accept student data
void display(struct student list[size]);//display students data
void bubblesort(struct student list[size]);//arrange list of students according to the roll num.
void insertsort(struct student list[size],int k);//arrange list of students according to name.
void quicksort(struct student list[size],int a, int r);//search top 10 students according to their sgpa
void samesearch(struct student list[size]);//display of same sgpa students.
void binarysearch(struct student list[size]);//search particular student using binary search.

main()
{
	int ch=1,i;
	struct student data[20];
	cout<<"ENTER THE DETAILS OF "<<size<<" STUDENTS\n";
	accept(data);
	bool reverse;
	
	while(ch!=0)
	{
		
	cout<<"\n 1:Roll Number List";//bubblesort
	cout<<"\n 2:Alphabetical Name List";//insertsort
	cout<<"\n 3:First 10 topper List";//quicksort
	cout<<"\n 4:equal sgpa list";//Linear search
	cout<<"\n 5:search Student info";//binary search
	cout<<"\n 0:exit";
    cout<<"\n Enter your choice:\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			bubblesort(data);
			display(data);
			break;
		case 2:
			insertsort(data,0);
			display(data);
			break;
		case 3:
			quicksort(data,0,size-1);
			display(data);
			break;
		case 4:
			samesearch(data);
			break;
		case 5:
			binarysearch(data);
			break;
		case 0:
			break;
		default:
			cout<<"....invalid choice.....";
	}
    }
    
}
void accept(struct student list[size])
{
	int i;
	for(i=0;i<size;i++)
	{
		cout<<i+1<<". Roll no: ";
		cin>>list[i].rno;
		cout<<i+1<<". Name:";
		cin>>list[i].name;
		cout<<i+1<<". SGPA:";
		cin>>list[i].SGPA;
	}
}
void display(struct student list[size])
{
	int i;
	cout<<"\n Rno.\tName\tSGPA";
	for(i=0;i<size;i++)
	{
		cout<<"\n"<<list[i].rno<<"\t"<<list[i].name<<"\t"<<list[i].SGPA;
	}
}
void bubblesort(struct student list[size])
{
	int i,j;
	struct student temp;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-1-i;j++)
		{
			if(list[j].rno>list[j+1].rno)
			{
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
		}
	}
}
void insertsort(struct student list[size],int n)
{
	int k,j;
	struct student temp;
	string m;
	for(k=1;k<size;k++)
	{
		m=list[k].name;
		temp=list[k];
		j=k-1;
		while(list[j].name>m&&j>=0)
		{
			list[j+1]=list[j];
			j=j-1;
		}
	list[j+1]=temp;
	}
}
void swap(student list[],int i, int j)
{
	
	struct student temp=list[i];
	list[i]=list[j];
	list[j]=temp;
}
int partition(student list[],int l,int r)
{
	float pi=list[r].SGPA;
	int i=l-1;
	for(int j=l;j<r;j++)
	{
		if(list[j].SGPA>=pi)
		{
			i++;
			swap(list,i,j);
		}
	}
	swap(list,i+1,r);
	return (i+1);
}
void quicksort(struct student list[size],int l,int r)
{
	int pi;
	if(l<r)
	{
		
		pi=partition(list,l,r);
		quicksort(list,l,pi-1);
		quicksort(list,pi+1,r);
	} 
}
void samesearch(struct student list[size])
{
	int i;
	float search;
	cout<<"Enter the Sgpa you want to search:";
	cin>>search;
	
	cout<<"\n RollNo. \t Name \t Sgpa\n";
	for(i=0;i<size;i++)
	{
		if(list[i].SGPA==search)
		{
			cout<<"\n"<<list[i].rno<<"\t"<<list[i].name<<"\t"<<list[i].SGPA;
		}
		
		
	}
}
void binarysearch(struct student list[size])
{
	int k,lower,upper,mid;
	char search[80];
	cout<<"Enter the name you want to search:";
	cin>>search;
	
	lower=0;
	upper=size-1;
	mid=(lower+upper)/2;
	
	while(lower<=upper)
	{
		if(strcmp(list[mid].name,search)<0)
		lower=mid+1;
		else if(strcmp(list[mid].name,search)==0)
		{
			cout<<"\n"<<list[mid].rno<<"\t"<<list[mid].name<<"\t"<<list[mid].SGPA;
			break;
		}
		else
		{
			upper=mid-1;
			mid=(lower+upper)/2;
		}
		if(lower>upper)
		{
			cout<<search<<"Not found in the list";
		}
	}	
}


















