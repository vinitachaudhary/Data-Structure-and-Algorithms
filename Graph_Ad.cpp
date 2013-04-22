# include <iostream>
# include <stdlib.h>
using namespace std;

class vertex
{
public:
float x,y;
};

class node 
{
public:
int key;
node *next;
};

void insert(node **A , int k)
{
node *temp;
temp=new node;
temp->key=k;

if (*A==NULL)
	{
	*A=temp;
	(*A)->next=NULL;
	}
else
	{
	node *temp1;
	temp1=*A;
	*A=temp;
	temp->next=temp1;
	}
}

int main()
{
int n,i,j;
float l,r;
int **AM;
node **AL,*temp;

//srand((unsigned int)time(0));

cout<<"\nEnter n : ";
cin>>n;

cout<<"\nEnter l : ";
cin>>l;

cout<<"\nEnter r : ";
cin>>r;

AM=new int * [n];
for (i=0; i<n; i++)
	AM[i]=new int [n];
	
AL=new node*[n];
for (i=0; i<n; i++)
	AL[i]=NULL;
	
for (i=0; i<n; i++)
	for (j=0; j<n; j++)
		AM[i][j]=0;

vertex *V;
V= new vertex[n];

for (i=0; i<n; i++)
	{
	V[i].x=r+rand()*(l-r)/RAND_MAX;
	V[i].y=r+rand()*(l-r)/RAND_MAX;
	
	for (j=i-1; j>=0; j--)
		{
		if (((V[i].x-V[j].x)*(V[i].x-V[j].x) + (V[i].y-V[j].y)*(V[i].y-V[j].y))<=2*r)
			{
			AM[i][j]=1;
			AM[j][i]=1;
			
			insert(&AL[i],j);
			insert(&AL[j],i);
			}
		}
	}
	
for (i=0; i<n; i++)
	cout<<'\t'<<i;
		
for (i=0; i<n; i++)
	{
	cout<<'\n'<<i<<'\t';
	for (j=0; j<n; j++)
		cout<<AM[i][j]<<'\t';
	cout<<'\n';
	}	
	
for (i=0; i<n; i++)
	{
	if (AL[i]!=NULL)
		{
		cout<<'\n'<<i;
		for (temp=AL[i]; temp!=NULL; temp=temp->next)
			cout<<"->"<<temp->key;
		}
	}
cout<<endl;
return 0;
}
