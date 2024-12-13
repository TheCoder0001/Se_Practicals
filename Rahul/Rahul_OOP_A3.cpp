#include <iostream>
using namespace std;

class Publication
{
		
	public:
	char title[20];
	float price;
	void put_data()
	{
		cout<<endl<<"Enter name : "<<endl;
		cin>>title;
		cout<<endl<<"Enter price : "<<endl;
		cin>>price;	
	}
	
	void get_data()
	{
		cout<<endl<<"Book name is "<<title<<endl;
		cout<<endl<<"Book's price is "<<price<<endl;
	}

};

class Book:public Publication
{
	private:
	float pagecount;
	int b;
	
	public:
	void page_count()
	{
		cout<<endl<<"Enter number of pages: "<<endl;
		cin>>pagecount;
		b = int(pagecount);
	}
	
	void put_data()
	{
		cout<<endl<<"------------------ENTER INFO------------------"<<endl;
		cout<<endl;
		try
 		{	
 			Publication::put_data();
 			page_count();
			if (pagecount != b)
 			{
 				throw pagecount;
 			}
 			else
 				get_data();
 		}
 		catch(...)
 		{
 			cout << "\nInvalid Page Count!!!"<<endl;
			pagecount = 0;
			cout<<"------------------INFORMATION------------------"<<endl;
			cout<<endl<<"Book name is "<<"-"<<endl;
			cout<<endl<<"Book's price is "<<0<<endl;
			cout<<endl<<"Number of pages in book are "<<pagecount<<endl;
 		}
 		
	}
	
	
	void get_data()
	{
		cout<<"------------------INFORMATION------------------"<<endl;
		Publication::get_data();
		cout<<endl<<"Number of pages in book are "<<pagecount<<endl;		
	}



};


class Tape:public Publication
{
	private:
	float playtime;
	int x;
	
	public:
	void play_time()
	{
		cout<<endl<<"Enter play time of tape: "<<endl;
		cin>>playtime;
		x = int(playtime);
	}
	
	void put_data()
	{
		cout<<endl<<"------------------ENTER INFO------------------"<<endl;
		cout<<endl;
		try
 		{	
 			Publication::put_data();
 			play_time();
			if (playtime - x > 0.6)
 			{
 				throw playtime;
 			}
 			else
 				get_data();		
 		}
 		catch(...)
 		{
 			cout << "\nInvalid Play time!!!"<<endl;
			playtime = 0;
			cout<<"------------------INFORMATION------------------"<<endl;
			cout<<endl<<"Book name is "<<"-"<<endl;
			cout<<endl<<"Book's price is "<<0<<endl;
			cout<<endl<<"Play time of tape is "<<playtime<<endl;
 		}	
	}
	
	void get_data()
	{
		cout<<"------------------INFORMATION------------------"<<endl;
		Publication::get_data();
		cout<<endl<<"Play time of tape is "<<playtime<<endl;		
	}
};

void menu()
	{
		cout<<endl<<"------------------MENU------------------"<<endl;
		cout<<"1. BOOK"<<endl<<"2. TAPE"<<endl<<"3. EXIT"<<endl;
	}

int main()
{	
	int choice;
	
	do
	{
		menu();
		cout<<"Enter your choice: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				Book b1;
				b1.put_data();
				break;
			case 2:
				Tape t1;
				t1.put_data();
				break;
			case 3:
				cout<<endl<<"You have terminated the program."<<endl;
				break;
			default:cout<<endl<<"Good Bye!!!";	
		}
	}while(choice!=3);
	return 0;



}
/*
------------------MENU------------------
1. BOOK
2. TAPE
3. EXIT
Enter your choice: 
1
------------------ENTER INFO------------------

Enter name of the book: 
CONCEPTS_of_OOP
Enter price of book: 
573
Enter number of pages: 
612
------------------INFORMATION------------------

Book name is CONCEPTS_of_OOP

Book's price is 573

Number of pages in book are 612

------------------MENU------------------
1. BOOK
2. TAPE
3. EXIT
Enter your choice: 
2
------------------ENTER INFO------------------

Enter name of the book: 
ADVANCED_C++_AND_OOP
Enter price of book: 
312
Enter play time of tape: 
118.48
------------------INFORMATION------------------

Book name is ADVANCED_C++_AND_OOP

Book's price is 312

Play time of tape is 118.48

------------------MENU------------------
1. BOOK
2. TAPE
3. EXIT
Enter your choice: 
1
------------------ENTER INFO------------------


Enter name of the book: 
C++_Programming
Enter price of book: 
213
Enter number of pages: 
314.6
Invalid Page Count!!!
------------------INFORMATION------------------

Book name is -

Book's price is 0

Number of pages in book are 0

------------------MENU------------------
1. BOOK
2. TAPE
3. EXIT
Enter your choice: 
2
------------------ENTER INFO------------------


Enter name of the book: 
Advanced_OOP
Enter price of book: 
178
Enter play time of tape: 
100
Invalid Play time!!!
------------------INFORMATION------------------

Book name is -

Book's price is 0

Play time of tape is 0

------------------MENU------------------
1. BOOK
2. TAPE
3. EXIT
Enter your choice: 
3
You have terminated the program.

*/
