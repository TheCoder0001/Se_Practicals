#include <iostream>

using namespace std;

class Complex                       
{
	public:
		float real;
		float img;
		
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex operator+ (Complex obj)
	{
		Complex temp;
		temp.real = real + obj.real;
		temp.img = img + obj.img;
		return temp; 
	}
	Complex operator* (Complex obj)
	{
		Complex temp;
		temp.real = real*obj.real - img*obj.img;
		temp.img = img*obj.real + real*obj.img;
		return temp;
	}
	friend ostream &operator<<(ostream &, Complex &);
	friend istream &operator>>(istream &, Complex &);
};

istream &operator>>(istream &input, Complex &obj)
{	
	cout<<"Real: ";
	input>>obj.real;
	cout<<"\nImaginary: ";
	input>>obj.img;
}


ostream &operator<<(ostream &out, Complex &obj)
{
	out<<obj.real<<"+"<<obj.img<<"i";
}

int main()
{
	Complex p, q, r, s;
	cout<<"Default value of complex number is "<<p;
	cout<<endl<<"Enter 1st complex number: \n";
	cin>>p;
	cout<<endl<<"Enter 2nd complex number: \n";
	cin>>q;
	r = p + q;
	s = p * q;
	cout<<"\n\n\t\tARITHMETIC OPERATIONS";
	cout<<"\nAddition = "<<r;
	cout<<"\nMultiplication = "<<s;	
	return 0;
	
}
