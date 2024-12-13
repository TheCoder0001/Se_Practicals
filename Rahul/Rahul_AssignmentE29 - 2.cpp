           
#include <iostream>

using namespace std;

class Queue
{    
    public:
        int front, rear, entries, prev_entries;
        int data[15];
        
        Queue()
        {
            front = -1;
            rear = 14;
            entries = 0;
        }
        
        int isempty()
        {
            if (front == -1)
	            return 1;
	        else
	            return 0;
        }

        int isfull(int entry)
        {   
            prev_entries = entries;
            entries += entry;
            if (entries > 15)
            {
                entries = prev_entries;
                return 1;
            }
            else
                return 0;
        }
        
        void enqueue(int x)
        {
            cout<<" You entered data "<<x<<" to the queue.";
            data[++front] = x;
        }

        int delqueue()
        {   
            int temp;
            temp = data[0];
            for(int i = 0; i <= front - 1; i++)
            {
                data[i] = data[i + 1];
            }
            --front;
            --entries;
            return temp;
        }
        
        void display()
        {
            int i;
            cout<<"\n";
            for(i = 0; i <= front; i++)
	        {
	            cout<<" "<<data[i];
	        }
	        cout<<"\n";
        }
};



int main()
{      
    Queue obj;
	int ch, x, n;
	int entry;
	do
	{
	    cout<<"\n_________________MENU_________________\n";
	    cout<<" 1.Insert Job\n 2.Delete Job\n 3.Display\n 4.Exit\n Enter your choice : ";
	    cin>>ch;
	    switch(ch)
        {
	        case 1: 
	            
	                cout<< "\n How many entries do u want to enter? : ";
	                cin>> entry;
	                if (obj.isfull(entry))
		            {   
		                cout<<" Queue can't contain these many entries!!!\n\n";
			        }
	                else
	                {
	                    for (int j = 0; j < entry; j++)
       		            {    
       		                cout<<"\n Enter data : ";
			                cin>>x;
			                obj.enqueue(x);
			                cout<<endl;
			            }
	                }
	
		                
	                break;
	                
	        case 2: if(!obj.isempty())
	                {
			            cout<<"\n Deleted Element = "<<obj.delqueue()<<endl;
			        }
		            else
			        {   
			            cout<<"\n Queue is already empty!!!\n\n";  
			        }
		            cout<<"\n Remaining Jobs : ";
		            obj.display();
	                break;
	        
	        case 3: if (!obj.isempty())
	                {
	                    cout<<"\n Queue contains : ";
		                obj.display();
	                }
	                else
		                cout<<"\n Queue is empty!!!\n\n";
	                break;
	                
	        case 4: cout<<"\n You terminated the program";
        }
    }while(ch!=4);
return 0;
}