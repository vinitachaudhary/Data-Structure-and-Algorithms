# include <iostream>

using namespace std;

class node
{
public :
int key;
node *next;
};

class hash
{
node **A;
int n;
public :
	hash(int t)		
		{
		n=t;
		A=new node* [t];
		for (int i=0; i<t; i++)
			A[i]=NULL;
		}
	~hash()		{delete []A;}
	int insert();
	int search(int k);
	void del();	
	void print_table();
};

int hash_func(int k, int n)		
{return (((513*k+437)%701)%n);}

int hash::insert()
{
int k,j,i=0,flag=0;
cout<<"\nEnter identifier to be inserted : ";
cin>>k;

node *temp,*temp1;

temp=new node;
temp->key=k;
temp->next=NULL;

j=hash_func(k,n);
	
if (A[j]==NULL)
	{
	A[j]=temp;
	return 0;
	}
	
else 
	{
	for(temp1=A[j]; temp1!=NULL; temp1=temp1->next)
		{
		i++;
		if (temp1->key==k)
			{
			flag=1;
			break;
			}
		}

	if (flag!=1)
		{
		temp1=A[j];
		A[j]=temp;
		temp->next=temp1;
		}
	else
		cout<<"\nValue already in list !!!\n";
	
	return i;
	}
}

void hash::del()
{
int j,k,flag=0;
cout<<"\nEnter identifier to be deleted : ";
cin>>k;

node *temp,*temp1;
j=hash_func(k,n);

if (A[j]==NULL)
	cout<<"\nValue not found !!!\n";

else if (A[j]->key==k)
	A[j]=A[j]->next;

else
{
for(temp=A[j]->next,temp1=A[j]; temp!=NULL; temp=temp->next,temp1=temp1->next)
	{
	if ((temp->key)==k)
		{
		flag=1;
		break;
		}
	}

if (flag==0)
	cout<<"\nValue not found !!!\n";
else
		temp1->next=temp->next;
}
}

void hash::print_table()
{
for (int i=0; i<n; i++)
	{
	if (A[i]!=NULL)
		{
		cout<<"\nSlot "<<i<<"\t-->\t";
		for(node *temp1=A[i]; temp1!=NULL; temp1=temp1->next)
			cout<<temp1->key<<'\t';
		}
	}
}

int main()
{
int n,ch,comp=0,total=0;
cout<<"\nEnter Hash Table size : ";
cin>>n;
hash H(n);

do
{
cout<<"\nMenu : \n 1. Insert identifier \n 2. Delete identifier \n 3. Print statistics \n 4. Exit \nEnter choice : ";
cin>>ch;

switch (ch)
	{
	case 1 : comp+=H.insert();
			 total++;
			 break;
	
	case 2 : H.del();
			 break;

	case 3 : cout<<"\nNumber of Comparisons : "<<comp;
			 cout<<"\nAverage no. of comparisons : "<<float(comp)/float(total);
			 cout<<"\nHash Table : \n";
			 H.print_table();
			 break;
	}
}while(ch!=4);

return 0;
}
