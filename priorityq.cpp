# include <iostream>
# include <cstdlib>

using namespace std;

class node
{
public :
	int service_time, arrival_time,job_no;
	node *next;
	node(int st=0, int at=0, int jn=0, node*p=0):service_time(st), arrival_time(at), job_no(jn), next(p) {};
	
};

void display(node *start)
{
for (node *temp=start; temp; temp=temp->next)
	cout<<"\nJob "<<temp->job_no<<"		Service Time : "<<temp->service_time<<"		Arrival Time : "<<temp->arrival_time;
}

int main()
{
int i,j,k,n,cpu_time,st,y;
node *start,*temp,*end,*temp1,*temp2;
start=new node;
end=new node;
temp1=new node;
temp2=new node;

cout<<"\nEnter no. of nodes in priority queue : ";
cin>>n;
cout<<"\nEnter cpu time : ";
cin>>cpu_time;

for (i=1; i<=n;	i++)
	{
	cout<<"\nEnter service time of job "<<i<<" : ";
	cin>>st;
	temp=new node(st,rand()%100,i);
	
	if (i==1)
		{
		start=temp;
		end=start;
		}
	else
		{
		end->next=temp;
		end=end->next;
		}
	}

cout<<"\nJobs entered : \n";
display(start);
cout<<endl;

for (i=1;i<=n-1;i++)
	{
	temp=start;
	for (j=1;j<=n-i;j++)
		{
		if (temp->arrival_time > (temp->next)->arrival_time)
			{
			y=temp->arrival_time;
			temp->arrival_time=(temp->next)->arrival_time;
			(temp->next)->arrival_time=y;
			
			y=temp->service_time;
			temp->service_time=(temp->next)->service_time;
			(temp->next)->service_time=y;

			y=temp->job_no;
			temp->job_no=(temp->next)->job_no;
			(temp->next)->job_no=y;
			}
		temp=temp->next;
		}
	}

cout<<"\n Job Order : \n\n";

temp=start;
while (temp!=NULL)
{
cout<<"\nJob "<<temp->job_no<<"		Service Time : "<<temp->service_time<<"		Arrival Time : "<<temp->arrival_time;

if (temp->service_time <= cpu_time)
	{
	cout<<"\nJob "<<temp->job_no<<" completed";
	//if (temp->next!=NULL)	
	if (temp==end)
		temp=NULL;
	else
		temp=temp->next;
	}
	
else
	{
	//if (temp->next!=NULL)
	if (temp==end)
		{while (temp->service_time-cpu_time>0)
			{
			cout<<"\nJob "<<temp->job_no<<"		Service Time : "<<temp->service_time<<"		Arrival Time : "<<temp->arrival_time;
			temp->service_time=(temp->service_time)-cpu_time;
			}
		cout<<"\nJob "<<temp->job_no<<" completed";
		temp=NULL;
		cout<<"\ntemp==end\n";
		}
	else
	{
	temp->service_time=(temp->service_time)-cpu_time;
	temp2=temp;
	temp=temp->next;
	end->next=temp2;
	end=temp2;
	end->next=NULL;
	}
	}
}

delete start;
delete end;
delete temp;
delete temp1;
delete temp2;
return 0;
}
