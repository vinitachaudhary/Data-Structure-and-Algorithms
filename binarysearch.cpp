# include <iostream>
//# include <cmath>
//# include <cstdio>

using namespace std;

int binary_search(int *A, int p, int q, int t)
{
int i,r;

for (i=p;i<=q;i++)
	{
	 //a[i]=i;
	 cout<<A[i]<<endl;
	}

r=(p+q)/2;

if (q==p && A[p]!=t)
	return -1;
	
else if (A[r]==t)
	return r;
	
else if (A[r]>t)
	return binary_search(A,p,r-1,t);
	
else if (A[r]>t)
	return binary_search(A,r+1,q,t);
	
}

int main()
{
int a[10],t,i;
cin>>t;
for (i=0;i<10;i++)
	{
	 a[i]=2*i;
	 cout<<a[i]<<endl;
	}
//i=binary_search(a,0,9,t);

int f=0,l=9,m;

while (f<=l)
{
 m=(f+l)/2;
 
 if (a[m]==t)
 	{
 	cout<<"\n m = "<<m;
 	break;
 	}
 	
 else if (a[m]>t)
 	 l=m-1;

 else if (a[m]<t)
 	f=m+1;
}

if (f>l)
	cout<<"\n -1";


//cout<<"\n i : "<<i<<endl;
return 0;
}
