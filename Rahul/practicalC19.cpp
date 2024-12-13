// This code is also good

#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    int prn;
    string name;
    Node* link;
};

class LinkedList{
    private:
        Node* head = NULL;
        int count = 1;
    
    public:
        void insert(string name, int prn){
            Node* temp = new Node();
            temp->name = name;
            temp->prn = prn;

            if(head == NULL){
                head = temp;
            }else{
                Node* last = head;
                while(last->link != NULL){
                    last = last->link;
                }
                last->link = temp;
            }
        }

        void display(){
            if(head == NULL){
                cout<<"The list is empty"<<endl;
                return;
            }

            Node* temp = head;
            cout<<"-----President----"<<endl;
            cout<<"Name:"<<temp->name<<" PRN:"<<temp->prn<<endl;

            temp = temp->link;
            cout<<"------Memebers-----"<<endl;
            int i = 1;
            while(temp->link != NULL){
                cout<<i<<":"<<temp->name<<" "<<temp->prn<<endl;
                i++;
                temp = temp->link;
            }
            cout<<"---Secretary----"<<endl;
            cout<<"Name:"<<temp->name<<" PRN:"<<temp->prn<<endl;
        }


        int getTotalMember(){
            Node* temp = new Node();
            while(temp != NULL){
                temp = temp->link;
                count++;
            }  
            return count;
        }

        void insertBetween(string name, int prn){
            Node* temp = new Node();
            temp->name = name;
            temp->prn = prn;
            if(head == NULL){
                head = temp;
            }else{
                Node* secondNode = head->link;
                head->link = temp;
                temp->link = secondNode;
            }
        }

        void deleteMemeber(int prn){
            if(head == NULL){
                cout<<"The list is empty"<<endl;
                return;
            }
            Node* temp = head;
            Node* prev = NULL;

            if(temp != NULL && temp->prn == prn){
                head = temp->link;
                delete temp;
                cout<<"President with PRN "<< prn<<" deleted"<<endl;
                return;
            }

            while(temp != NULL && temp->prn != prn){
                prev = temp;
                temp = temp->link;
            }

            if(temp == NULL){
                cout<<"Memeber with PRN "<< prn << " Not found"<<endl;
                return;
            }
            prev->link = temp->link;
            delete temp;
            cout<<"Memeber with PRN " << prn << " deleted"<<endl;
        }

        void concatenate(LinkedList& otherlist){
            Node* temp = head;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = otherlist.head;
            otherlist.head = NULL;
        }


};

void data(string& name, int& prn){
    cout<<"Enter a name:";
    cin>>name;
    cout<<"Enter a PRN:";
    cin>>prn;
}

void subMenu(int choice, LinkedList& list){
    string name;
    int prn, members;
    cout<<"1.Add president"<<endl;
    cout<<"2.Add secratary"<<endl;
    cout<<"3.Add Memebers"<<endl;
    cout<<"4.Delete Memeber"<<endl;
    cout<<"5.Get total Members"<<endl;
    cout<<"6.Display"<<endl;
    cout<<"Enter a choice:";
    cin>>choice;

    switch (choice){
        case 1:
            data(name, prn);
            list.insert(name, prn);
            break;
        case 2:
            data(name, prn);
            list.insert(name, prn);
            break;
        case 3:
            cout<<"how many members do you want to add:";
            cin>>members;
            for(int i = 0; i < members; i++){
                data(name, prn);
                list.insertBetween(name, prn);
            }
            
            break;
        
        case 4:
            cout<<"Enter a prn:";
            cin>>prn;
            list.deleteMemeber(prn);
            break;
        
        case 5:
            cout<<"Total Members:"<<list.getTotalMember()<<endl;
            break;
        
        case 6:
            cout<<"----Displaying-----"<<endl;
            list.display();
            break;
        
        default:
            cout<<"----Exit---"<<endl;
            break;
    }
}

int main(){
    int choice, ch;
    LinkedList list1, list2;

    do{
        cout<<endl;
        cout<<"-----MENU-----"<<endl;
        cout<<"1.List 1"<<endl;
        cout<<"2.List 2"<<endl;
        cout<<"3.Concatenate"<<endl;
        cout<<"Enter a choice:";
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
                cout<<"---list 1 Menu---"<<endl;
                subMenu(ch, list1);
                // cout<<"Enter a choice:";
                // cin>>ch;
                break;
            
            case 2:
                cout<<"---list 2 Menu----"<<endl;
                subMenu(ch, list2);
                // cout<<"Enter a choice:";
                // cin>>ch;
                break;
            case 3: 
                cout<<"---Concatenate----"<<endl;
                list1.concatenate(list2);
            default:
                cout<<"Exit"<<endl;
            
        }

    }while(choice != 4);
    return 0;

}