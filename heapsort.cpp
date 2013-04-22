# include <iostream>
# include <cmath>
# include <cstdio>

using namespace std;

void MAX_HEAPIFY(int *A,int i,int k)	// k : heapsize
{
cout<<"\n MaxHeapify A : "<<i<<k<<endl;
int l,r,large,temp;

l=(2*i)+1;
r=(2*i)+2;
large=i;

if (l<k && A[l]>A[large])
	large=l;
if (r<k && A[r]>A[large])
	large=r;

if (large!=i)
	{
	temp=A[i];
	A[i]=A[large];
	A[large]=temp;
	MAX_HEAPIFY(A,large,k);
	}
	
for (i=0;i<10;i++)
	cout<<A[i]<<endl;
}

void BUILD_MAX_HEAP(int *A,int k)
{
cout<<"\nBuild";
for (int i=(k/2)-1; i>=0; i--)
	MAX_HEAPIFY(A,i,k);
}

void HEAPSORT(int *A, int k)
{
cout<<"\nHeapsort";
BUILD_MAX_HEAP(A,k);
int temp;
for (int i=k-1; i>=0; i--)
	{
	temp=A[i];
	A[i]=A[0];
	A[0]=temp;
	MAX_HEAPIFY(A,0,i);
	}
}

int main()
{
int A[10];
int i;

for (i=0;i<10;i++)
	A[i]=i;

cout<<"\n A : "<<endl;

for (i=0;i<10;i++)
	cout<<A[i]<<endl;

HEAPSORT(A,10);
//MAX_HEAPIFY(A,4,10);
cout<<"\n Sorted A : "<<endl;

for (i=0;i<10;i++)
	cout<<A[i]<<endl;
return 0;
}
