# include <iostream>

using namespace std;

class node
{
public :
int key;
node *next;
};

int main()
{
int ch,n,k,turn=0;
node *start,*temp,*end,*prev;
start=NULL;
prev=NULL;

do
{
	turn=0;
	cout<<"\nMenu : \n 1. Create Linked List \n 2. Search \n 3. Print \n 4. Exit \nEnter Choice : ";
	cin>>ch;
	
	switch(ch)
	{
	case 1 : cout<<"\nEnter number of elements in the list : ";
			 cin>>n;
			 for (int i=0; i<n; i++)
				{
				cout<<"\nEnter element : ";
				cin>>k;
				if (start==NULL)
					{
					start= new node;
					start->key=k;
					start->next=NULL;
					end=start;
					}
				else
					{
					temp=new node;
					temp->key=k;
					temp->next=NULL;
					end->next=temp;
					end=temp;
					}
				}
			 break;

	case 2 : cout<<"\nEnter the value to be searched : ";
			 cin>>k;

			 if (prev!=NULL && start!=NULL)
				turn=1;
			
			 if (start==NULL && prev!=NULL)
				start=prev;

			 for(temp=start; temp!=NULL;)
				{
				cout<<temp->key<<"\t";

				start=temp->next;

				if (prev!=NULL && temp!=prev)
					temp->next=prev;
					
				else
					temp->next=NULL;

				prev=temp;	

				if (start!=NULL or turn==0)
					temp=start;
				else
					{
					start=temp;
					prev=NULL;
					turn=0;
					}

				if (prev!=NULL && prev->key==k)
					break;

				//cout<<"\n prev : "<<prev->key<<"\n temp : "<<temp->key<<"\n start : "<<start->key;
				}
			 if (temp==NULL)
					cout<<"\nValue not found !!!";

			 break;

	case 3 : cout<<"\n Starting List : "<<endl;

			 for (temp=start; temp!=NULL; temp=temp->next)
					cout<<temp->key<<"\t";
			 
			 if (prev!=NULL)
				{
				cout<<"\n Second List : "<<endl;

			 	for (temp=prev; temp!=NULL; temp=temp->next)
					cout<<temp->key<<"\t";
				}
			 break;
	}

}while(ch!=4);
return 0;
}
