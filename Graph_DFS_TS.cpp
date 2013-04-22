# include <iostream>
# include <stdlib.h>
using namespace std;

class vertex
{
public:
float x,y;
int status;		// status -1 -> not visited 	0->discovered		(>1)->visited & family
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

int DFS(vertex *V, node **A, int n, int i, int comp)
{
(V[i]).status=0;
for (node *temp=A[i]; temp!=NULL; temp=temp->next)
	{if ((V[temp->key]).status==0)
		return 0;				// Not DAG
	else if ((V[temp->key]).status==-1){
		if (DFS(V,A,n,temp->key,comp)==0)
			return 0;
	}
	}
cout<<i<<'\t';
(V[i]).status=comp;
return 1;
}

int main()
{
int n,i,j,comp,t;
float l,r;
node **AL,*temp;

srand((unsigned int)time(0));

cout<<"\nEnter n : ";
cin>>n;

cout<<"\nEnter l : ";
cin>>l;

cout<<"\nEnter r : ";
cin>>r;

AL=new node*[n];
for (i=0; i<n; i++)
	AL[i]=NULL;
	
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
			t=(float(rand())/float(RAND_MAX))*2;
			cout<<t;
			
			if (t==0)
				insert(&AL[i],j);
			else
				insert(&AL[j],i);
			}
		}
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
	
for (i=0; i<n; i++)
	V[i].status=-1;
	
comp=1;
for (i=0; i<n; i++)
	{
	if (V[i].status==-1)
		{
		//cout<<"\nList "<<comp<<" : ";
		if (DFS(V,AL,n,i,comp)==0)
			break;
		else
			comp++;
		}
	}
	
if (i==n)
	cout<<"\nDAG";
else
	cout<<"\nNot DAG";

	
return 0;
}
