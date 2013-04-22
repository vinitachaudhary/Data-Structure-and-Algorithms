# include <iostream>

using namespace std;

class node
{
public :
int key;
node *left,*right,*p;
};

node* CreateNode(int value)
{
node *temp;

temp= new node;
temp->left=NULL;
temp->right=NULL;
temp->p=NULL;
temp->key=value;

return temp;
}

void InsertBST(node **root)
{
int value;
node *temp,*temp1;

cout<<"\nEnter value : ";
cin>>value;

if (*root==NULL)
	*root=CreateNode(value);	

else
	{
		for(temp=*root; temp!=NULL;)
		{
		temp1=temp;
		if (value<temp->key)
			temp=temp->left;
		else
			temp=temp->right;
		}
		
		temp=CreateNode(value);
		temp->p=temp1;
		
		if (temp->key<temp1->key)
			temp1->left=temp;
		else
			temp1->right=temp;
		
	}
}

void InorderPrint(node *root)
{
if (root!=NULL)
	{	
	InorderPrint(root->left);
	cout<<'\t'<<root->key;
	InorderPrint(root->right);
	}
}

node* Search(node *top, int value)
{
if (top==NULL)
	return NULL;
else
	{
	for (node* temp=top; temp!=NULL;)
		{
		if (temp->key==value)
			return temp;
		else if (value<temp->key)
			temp=temp->left;
		else
			temp=temp->right;
		}
	return NULL;
	}
}

node* Successor(node *temp)
{
node *temp1;

if (temp==NULL)
	return NULL;
else
	{
	if (temp->right!=NULL)
		{
		for (temp1=temp->right; temp1->left!=NULL; temp1=temp1->left);
		return temp1;
		}
	else if (temp->p!=NULL)
		{
		temp1=temp->p; 
		while(temp1!=NULL && temp==temp1->right)
			{
			temp=temp1;
			temp1=temp1->p;
			}
		return temp1;
		}
	return NULL;
	}
}

node* Predecessor(node *temp)
{
node *temp1;

if (temp==NULL)
	return NULL;
else
	{
	if (temp->left!=NULL)
		{
		for (temp1=temp->left; temp1->right!=NULL; temp1=temp1->right);
		return temp1;
		}
	else if (temp->p!=NULL)
		{
		temp1=temp->p; 
		while(temp1!=NULL && temp==temp1->left)
			{
			temp=temp1;
			temp1=temp1->p;
			}
		return temp1;
		}
	return NULL;
	}
}

void Transplant(node ***root, node **u, node **v)
{
if ((*u)->p==NULL)
	**root=*v;
else if (*u==(*u)->p->left)
	(*u)->p->left=*v;
else
	(*u)->p->right=*v;

if (*v!=NULL)
	(*v)->p=(*u)->p;
}

void Delete(node **root,int value)
{
if (*root==NULL)
	cout<<"Tree is empty !!!\n";
else
	{
	node *temp=Search(*root, value);
	
	if (temp==NULL)
		cout<<"\nValue not found !!!\n";
	
	else if (temp->left==NULL)
		Transplant(&root,&temp, &(temp->right));
	
	else if (temp->right==NULL)
		Transplant(&root,&temp, &(temp->left));
	
	else
		{
		node *y;
		
		for (y=temp->right; y->left!=NULL; y=y->left);
		
		if (y->p!=temp)
			{
			Transplant(&root,&y,&(y->right));
			y->right=temp->right;
			y->right->p=y;
			}	
			
		Transplant(&root,&temp,&y);
		y->left=temp->left;
		y->left->p=y;
		}
	}
}

int main()
{
int ch,more,value;
node *root,*temp;
root=NULL;
do
{
cout<<"\nMenu : \n 1. Insert Node \n 2. Inorder Print \n 3. Find Successor \n 4. Find Predecessor \n 5. Delete Node \n 6. Exit \nEnter choice : ";
cin>>ch;

switch(ch)
{
case 1 :do 
		{
		InsertBST(&root);
		cout<<"\nEnter more numbers ?? (1/0) : ";
		cin>>more;
		}while(more!=0);
		break;
		 
case 2 :if (root==NULL)
			cout<<"\nTree is empty !!!\n";
		else
			cout<<"\nTree : ";
			InorderPrint(root);
			cout<<endl;
		break;
		 
case 3 :if (root==NULL)
			cout<<"\nTree is empty !!!\n";
		else
		{
		cout<<"\nEnter value whose successor is to be found : ";
		cin>>value;
		temp=Search(root,value);
		if (temp==NULL)
			cout<<"\nValue not found !!!\n";
		else
			{
			temp=Successor(temp);
			if (temp==NULL)
				cout<<"\nSuccessor does not exist !!!\n";
			else
				cout<<"Successor value : "<<temp->key;
			}
		}
		break;
		
case 4 :if (root==NULL)
			cout<<"\nTree is empty !!!\n";
		else
		{
		cout<<"\nEnter value whose predecessor is to be found : ";
		cin>>value;
		temp=Search(root,value);
		if (temp==NULL)
			cout<<"\nValue not found !!!\n";
		else
			{
			temp=Predecessor(temp);
			if (temp==NULL)
				cout<<"\nPredecessor does not exist !!!\n";
			else
				cout<<"Predecessor value : "<<temp->key;
			}
		}
		break;
		
case 5 :cout<<"\nEnter value which is to be deleted : ";
		cin>>value;
		Delete(&root,value);
}
}while(ch!=6);
return 0;
}
