# include <iostream>
# include <stdlib.h>
using namespace std;

class vertex
{
public:
float x,y;
int status,dist,parent;		// status -1 -> not visited 	0->discovered		1->visited
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

void Enqueue(node **Start,node **End,int k)
{
node *temp;
temp=new node;
temp->key=k;
temp->next=NULL;

if (*Start==NULL)
	{
	*Start=temp;
	*End=temp;
	}
else
	{
	(*End)->next=temp;
	*End=temp;
	}
//cout<<"\nEnqueued "<<k;
}

int Dequeue(node **Start,node **End)
{
node *temp;

if (*End==NULL)
	return -1;
	
else if (*Start==*End)
	{
	temp=*Start;
	*End=NULL;
	*Start=NULL;
	}
else
	{
	temp=*Start;
	*Start=(*Start)->next;
	}
//cout<<"\ndequeue "<<temp->key;
return temp->key;

}

void BFS(vertex **V, node **AL, int n, int s)
{
int i,u,d;
node *Start, *End, *temp;
Start=NULL;
End=NULL;

/*for (i=0;i<n;i++)
{
cout<<((*V)[i]).x<<","<<((*V)[i]).y<<'\n';
}
*/

for (i=0; i<n; i++)
	{
	if (i!=s){
		((*V)[i]).status=-1;
		((*V)[i]).dist=2*n;
		((*V)[i]).parent=-1;
		}
	}

((*V)[s]).status=0;
((*V)[s]).dist=0;
((*V)[s]).parent=-1;

u=s;
d=1;
while(u!=-1)
	{
	for (temp=(AL[u]); temp!=NULL; temp=temp->next)
		{
		if (((*V)[temp->key]).status==-1)
			{
			((*V)[temp->key]).status=0;
			((*V)[temp->key]).dist=((*V)[u]).dist + 1;
			((*V)[temp->key]).parent=u;
			
			Enqueue(&Start, &End, temp->key);
			}
		((*V)[u]).status=1;
		
		/*cout<<"\nAfter Enqueue : ";
		for (temp=Start; temp!=NULL; temp=temp->next)
			cout<<temp->key<<'\t';*/
		}
	u=Dequeue(&Start,&End);	
	d++;
	}
}

int main()
{
int n,i,j,s,d;
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
	
cout<<"\nEnter source (0-("<<n-1<<")) : ";
cin>>s;

BFS(&V,AL,n,s);

for (i=0;i<n;i++)
	cout<<V[i].dist<<endl;

cout<<"\nEnter destination : ";
cin>>d;

int u;
u=d;
if (V[u].dist!=2*n)
{
while (u!=-1)
	{
	cout<<u<<'\t';
	u=V[u].parent;
	}

cout<<endl;
}
else
	cout<<"\nNo Path"<<endl;
return 0;
}
