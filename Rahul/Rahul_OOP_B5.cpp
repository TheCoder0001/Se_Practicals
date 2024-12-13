# include<iostream>
# define size 10
using namespace std;
int n;


template<typename T>T selection(T a[10])
{
	int i, j, min;
	T temp;
	for(i = 0; i<n; i++)
	{
		min = i;
		for(j=i; j<n; j++)
		{
			if(a[j] < a[min])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	
	cout<< endl<< "After sorting: "<< endl;
	for(i = 0; i<n; i++)
	{
		cout<< i+1<< ": "<< a[i]<<endl;
	}
}

void menu()
{
	cout<< "\t\tMENU\t\t\n1. Sort integers\n2. Sort floats\n3. EXIT\n";
}

int main()
{
	int a[size];
	float b[size];
	int ch;
	float ch1;
	
	do
	{
		menu();
		cout<< "Enter your choice: ";
		cin>> ch1;
		if(ch1 == int(ch1))
		{
			ch = int(ch1);
			switch (ch)
			{
				case 1:
					cout<< endl<< "\tSELECTION SORT";
					cout<< endl<< "How many integers?: ";
					cin>> n;
					for(int i = 0; i<n; i++)
					{
						cout<< "Enter integer "<< i+1<< ": ";
						cin>>a[i];
					}
					selection(a);
				break;
				case 2:
					cout<< endl<< "\tSELECTION SORT";
					cout<< endl<< "How many floats?: ";
					cin>> n;
					for(int i = 0; i<n; i++)
					{
						cout<< "Enter float "<< i+1<< ": ";
						cin>>b[i];
					}
					selection(b);
				break;
				case 3:
					cout<< endl<< "You terminated the program.";
				break;
				default:
					cout<< "Invalid choice!!!\n";			
			}
		}
		else
			cout<< "Invalid choice!!!\n";		
	}while(ch!=3);
	return 0;
}
