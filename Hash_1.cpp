# include <iostream>

using namespace std;

class hash
{
int *A,n;
public :
	hash(int t)		
		{
		n=t;
		A=new int [t];
		for (int i=0; i<t; i++)
			A[i]=-1;		
		}
	~hash()		{delete []A;}
	int insert();
	int search(int k);
	void del();	
	void print_table();
};

int hash_func(int k, int i, int n)		
{return ((((513*k+437)%701) +(i*((231*k+607)%701)))%n);}

int hash::insert()
{
int k,j,i=0;
cout<<"\nEnter identifier to be inserted : ";
cin>>k;

do
	{
	j=hash_func(k,i,n);
	//cout<<j<<endl;
	if (A[j]==-1)
		{
		A[j]=k;
		return i;
		}
	
	else 
		i++;
	}while(i<=n);
cout<<"\nHash Table Overflow !!! \n";	
return 0;
}

int hash::search(int k)
{
int j,i=0;

do
	{
	j=hash_func(k,i,n);

	if (A[j]==k)
		return j;
	else
		i++;
	}while(i<n && A[j]!=-1);

return -1;		// not found
}

void hash::del()
{
int k,temp;
cout<<"\nEnter identifier to be deleted : ";
cin>>k;

temp=this->search(k);

if (temp==-1)
	cout<<"\nValue not found !!!\n";
else
	A[temp]=-1;
}

void hash::print_table()
{
for (int i=0; i<n; i++)
	{
	if (A[i]!=-1)
		cout<<A[i]<<"\t-->\t"<<i<<endl;
	}
}

int main()
{
int n,ch,collision=0;
cout<<"\nEnter Hash Table size : ";
cin>>n;
hash H(n);

do
{
cout<<"\nMenu : \n 1. Insert identifier \n 2. Delete identifier \n 3. Print statistics \n 4. Exit \nEnter choice : ";
cin>>ch;

switch (ch)
	{
	case 1 : collision+=H.insert();
			 break;
	
	case 2 : H.del();
			 break;

	case 3 : cout<<"\nNumber of Collisions : "<<collision;
			 cout<<"\nAverage no. of collisions : "<<float(collision)/float(n);
			 cout<<"\nHash Table : \n";
			 H.print_table();
			 break;
	}
}while(ch!=4);

return 0;
}