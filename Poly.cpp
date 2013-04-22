# include <iostream>
# include <cmath>
using namespace std;

class Shape
{
public :
	virtual void set_value()=0;
	virtual void print()=0;
	virtual void area()=0;
};

class TwoD : public Shape
{
public :
	virtual void perimeter()=0;
};

class ThreeD : public Shape
{
public :
	virtual void volume()=0;
};

class Triangle : public TwoD
{
int a,b,c;

public : 
	void set_value();
	void perimeter() {cout<<"\nPerimeter : "<<(a+b+c)<<endl;}
	void area();
	void print() {cout<<"\nSides of triangle are : "<<a<<'\t'<<b<<'\t'<<c<<endl;}
};

void Triangle::set_value()
{
cout<<"\nEnter the length of 3 sides : ";
cin>>a>>b>>c;
}

void Triangle::area()
{
float s;
s=(a+b+c)/2;
cout<<"\nArea : "<<sqrt(s*(s-a)*(s-b)*(s-c));
}

class Rectangle : public TwoD
{
int l,b;

public : 
	void set_value();
	void perimeter() {cout<<"\nPerimeter : "<<(2*(l+b))<<endl;}
	void area() {cout<<"\nArea : "<<l*b<<endl;}
	void print() {cout<<"\nSides of Rectangle are : "<<l<<'\t'<<b<<endl;}
};

void Rectangle::set_value()
{
cout<<"\nEnter length of rectangle : ";
cin>>l;
cout<<"\nEnter breadth of rectangle : ";
cin>>b;
}

class Circle : public TwoD
{
int r;

public : 
	void set_value();
	void perimeter() {cout<<"\nPerimeter : "<<(2*3.14*r)<<endl;}
	void area() {cout<<"\nArea : "<<3.14*r*r<<endl;}
	void print() {cout<<"\nRadius of Circle : "<<r<<endl;}
};

void Circle::set_value()
{
cout<<"\nEnter radius of circle : ";
cin>>r;
}

class Box : public ThreeD
{
int l,b,h;

public : 
	void set_value();
	void area() {cout<<"\nArea : "<<2*(l*b+b*h+h*l)<<endl;}
	void volume() {cout<<"\nVolume : "<<(l*b*h)<<endl;}
	void print() {cout<<"\nSides of Box are : "<<l<<'\t'<<b<<'\t'<<h<<endl;}
};

void Box::set_value()
{
cout<<"\nEnter length of Box : ";
cin>>l;
cout<<"\nEnter breadth of Box : ";
cin>>b;
cout<<"\nEnter height of Box : ";
cin>>h;
}

class Cone : public ThreeD
{
int h,r;

public : 
	void set_value();
	void area() {cout<<"\nArea : "<<(3.14*r*(r+(sqrt(r*r+h*h))))<<endl;}
	void volume() {cout<<"\nVolume : "<<(3.14*r*r*h/3)<<endl;}
	void print() {cout<<"\nHeight and Radius of Cone are : "<<h<<'\t'<<r<<endl;}
};

void Cone::set_value()
{
cout<<"\nEnter height of Cone : ";
cin>>h;
cout<<"\nEnter radius of base : ";
cin>>r;
}

class Cylinder : public ThreeD
{
int h,r;

public : 
	void set_value();
	void area() {cout<<"\nArea : "<<(2*3.14*r*(r+h))<<endl;}
	void volume() {cout<<"\nVolume : "<<(3.14*r*r*h)<<endl;}
	void print() {cout<<"\nHeight and Radius of Cylinder are : "<<h<<'\t'<<r<<endl;}
};

void Cylinder::set_value()
{
cout<<"\nEnter height of Cylinder : ";
cin>>h;
cout<<"\nEnter radius of base : ";
cin>>r;
}

class Sphere : public ThreeD
{
public : 
	int r;	
	void set_value();
	void area() {cout<<"\nArea : "<<(4*3.14*r*r)<<endl;}
	void volume() {cout<<"\nVolume : "<<(4*3.14*r*r*r/3)<<endl;}
	void print() {cout<<"\nRadius of Sphere : "<<r<<endl;}
};

void Sphere::set_value()
{
cout<<"\nEnter radius of Sphere : ";
cin>>r;
}

int main()
{TwoD *X;
ThreeD *Y;
int ch;
do
	{
	cout<<"\nMenu : \n 1. Circle \n 2. Rectangle \n 3. Triangle \n 4. Box \n 5. Cone \n 6. Cylinder \n 7. Sphere \n 8. Exit \nEnter Choice : ";
	cin>>ch;

	switch(ch)
	{
	case 1 :X=new Circle;
			X->set_value();
			X->area();
			X->perimeter();
			delete X;
			break;

	case 2 :X=new Rectangle;
			X->set_value();
			X->area();
			X->perimeter();
			delete X;
			break;

	case 3 :X=new Triangle;
			X->set_value();
			X->area();
			X->perimeter();
			delete X;
			break;

	case 4 :Y=new Box;
			Y->set_value();
			Y->area();
			Y->volume();
			delete Y;
			break;

	case 5 :Y=new Cone;
			Y->set_value();
			Y->area();
			Y->volume();
			delete Y;
			break;

	case 6 :Y=new Cylinder;
			Y->set_value();
			Y->area();
			Y->volume();
			delete Y;
			break;

	case 7 :Y=new Sphere;
			Y->set_value();
			Y->area();
			Y->volume();
			delete Y;
			break;
	}

	}while(ch!=8);
return 0;
}
