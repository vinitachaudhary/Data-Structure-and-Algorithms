# include <iostream>
# include <cstring>
# include <cstdio>

using namespace std;

class Master
{
protected :
		char name[20],DoB[11],DoJ[11];
};

class Account:public Master
{
protected :
		int pay;
};

class Admin : public Master
{
protected :
		int exp;
		void setvalues();
		void printvalues();
		//int chkname();
};

void Admin::setvalues()
{
cout<<"\nEnter Name of Person : ";
getchar();
gets(name);

cout<<"\nEnter Date of Birth : ";
gets(DoB);

cout<<"\nEnter Date of Joining : ";
gets(DoJ);

cout<<"\nEnter Experience : ";
cin>>exp;
}

void Admin::printvalues()
{
cout<<'\n'<<name<<'\t'<<DoB<<'\t'<<DoJ<<'\t'<<exp;
}

/*int Admin::chkname()
{
char searchname[20];

cout<<"\nEnter name of Person whose record is to be updated : ";
getchar();
gets(searchname);

/*for (char p=0; searchname[p]!='\0'; p++)
	searchname[p]=tolower(searchname[p]);

char namelow[20];

for (char p=0; name[p+1]!='\0'; p++)
	namelow[p]=tolower(name[p]);

if (strcmp(searchname,name)==0)
	return 1;
else
	return 0;
}
*/


class Person : public Account, public Admin
{
private:
	Person *next;
public :
	void create(Person **Start);
	void update(Person **Start);
	void display(Person *Start);
};

void Person::create(Person **Start)
{
Person *temp,*temp1;
temp=new Person;

temp->setvalues();

cout<<"\nEnter Pay : ";
cin>>temp->pay;

temp->next=NULL;

if (*Start==NULL)
	*Start=temp;

else
	{
	for (temp1=*Start; temp1->next!=NULL; temp1=temp1->next);
	temp1->next=temp;
	}
}

void Person::display(Person *Start)
{
if (Start==NULL)
 	cout<<"\nNo entries";
else
{
cout<<"\nName\tDoB\tDoJ\tExperience\tPay";

for (Person *temp=Start; temp!=NULL; temp=temp->next)
	{
	temp->printvalues();
	cout<<"\t\t"<<temp->pay<<endl;
	}
}	
}

void Person::update(Person **Start)
{
if (*Start==NULL)
	cout<<"\nNo entries to update";

else
	{
	char searchname[20];

	cout<<"\nEnter name of Person whose record is to be updated : ";
	getchar();
	gets(searchname);
	
	Person *temp;

	for (temp=(*Start); temp!=NULL && (strcmp(searchname,temp->Admin::name)!=0); temp=temp->next);
	
	if (temp==NULL)
		cout<<"\nNo matching entry found !!!";
	else
		{
		cout<<"\nName\tDoB\tDoJ\tExperience\tPay";
		temp->printvalues();
		cout<<"\t\t"<<temp->pay<<endl;
	
		int choice;
		cout<<"\nUpdate : \n1. Name \n2. Date of Birth \n3. Date of Joining \n4. Experience \n5. Pay \n\n Enter Choice : ";
		cin>>choice;

		switch(choice)
		{
		case 1 : cout<<"\nEnter new Name : ";
				getchar();
				gets(temp->Admin::name);
				break;

		case 2 : cout<<"\nEnter new Date of Birth : ";
				getchar();
				gets(temp->Admin::DoB);
				break;

		case 3 : cout<<"\nEnter new Date of Joining : ";
				getchar();
				gets(temp->Admin::DoJ);
				break;

		case 4 : cout<<"\nEnter new Experience : ";
				cin>>temp->exp;
				break;

		case 5 : cout<<"\nEnter new Pay : ";
				cin>>temp->pay;
				break;

		}
		cout<<"\nRecord successfully updated !!!";
	
		cout<<"\nName\tDoB\tDoJ\tExperience\tPay";
		temp->printvalues();
		cout<<"\t\t"<<temp->pay<<endl;
		}
	}
}

int main()
{
int choice;
Person *Start;
Start=NULL;

do
{
cout<<"\n\nOptions : \n1. Create a new entry \n2. Update an entry \n3. Display all the entries \n4. Exit \n\n Enter Choice : ";
cin>>choice;

switch(choice)
{
case 1 : Start->create(&Start);
		break;
case 2 : Start->update(&Start);
		break;
case 3 : Start->display(Start);
		break;
}

}while(choice!=4);
		
return 0;
}
