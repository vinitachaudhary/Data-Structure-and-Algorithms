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

void DFS(vertex **V, node **A, int n, int i, int comp)
{
((*V)[i]).status=0;
for (node *temp=A[i]; temp!=NULL; temp=temp->next)
	{if (((*V)[temp->key]).status==-1){
		DFS(V,A,n,temp->key,comp);
	}
	}
cout<<i<<'\t';
((*V)[i]).status=comp;
}

int main()
{
int n,i,j,comp;
float l,r;
node **AL,*temp;

//srand((unsigned int)time(0));

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
			insert(&AL[i],j);
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
		cout<<"\nList "<<comp<<" : ";
		DFS(&V,AL,n,i,comp);
		comp++;
		}
	}
cout<<endl;
	
return 0;
}
