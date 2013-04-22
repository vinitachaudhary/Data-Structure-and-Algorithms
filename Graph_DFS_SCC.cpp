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

void DFS(vertex *V, node **A, int n, int i, node **Start)
{
(V[i]).status=0;
for (node *temp=A[i]; temp!=NULL; temp=temp->next)
	{if ((V[temp->key]).status==-1){
		DFS(V,A,n,temp->key,Start);
		}
	}
insert(Start,i);
cout<<i<<'\t';
(V[i]).status=1;
}

int main()
{
int n,i,j,comp,t;
float l,r;
node **AL,**AL1,*temp,*temp1;
node *Start;
Start=NULL;

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
	
AL1=new node*[n];
for (i=0; i<n; i++)
	AL1[i]=NULL;
	
vertex *V,*V1;
V= new vertex[n];
V1= new vertex[n];


for (i=0; i<n; i++)
	{
	V[i].x=r+rand()*(l-r)/RAND_MAX;
	V[i].y=r+rand()*(l-r)/RAND_MAX;
	V1[i].x=V[i].x;
	V1[i].y=V[i].y;
	
	for (j=i-1; j>=0; j--)
		{
		if (((V[i].x-V[j].x)*(V[i].x-V[j].x) + (V[i].y-V[j].y)*(V[i].y-V[j].y))<=2*r)
			{
			t=(float(rand())/float(RAND_MAX))*3;
			//cout<<t;
			
			if (t!=0)
				{
				insert(&AL[i],j);
				insert(&AL1[j],i);
				}
			if (t!=1)
				{
				insert(&AL[j],i);
				insert(&AL1[i],j);
				}
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
	{
	V[i].status=-1;
	V1[i].status=-1;
	}

for (i=0; i<n; i++)
	{
	if (V[i].status==-1)
		{
		DFS(V,AL,n,i,&Start);
		}
	}
	
comp=1;
for (temp=Start; temp!=NULL; temp=temp->next)
	{
	if (V1[temp->key].status==-1)
		{
		cout<<"\nSCC "<<comp<<" : ";
		DFS(V1,AL1,n,temp->key,&temp1);
		comp++;
		}
	}
cout<<endl;
	
return 0;
}
