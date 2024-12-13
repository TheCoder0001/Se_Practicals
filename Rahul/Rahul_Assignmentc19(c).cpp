// This code is and fulfills the requiremnets

#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    string name;
    int prn;
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

        void getTotalNumber(){
            Node* temp = head;
            while(temp != NULL){
                temp = temp->link;
                count++;
            }
        }

        void deleteMember(int prn){

            Node* temp = head;
            Node* prev = NULL;

            if(head == NULL){
                cout<<"The list is empty"<<endl;
                return;
            }

            if(temp != NULL && temp->prn == prn){
                head = temp->link;
                delete temp;
                cout<<"President with prn "<< prn<< " is deleted"<<endl;
                return;
            }

            while(temp != NULL && temp->prn != prn){
                prev = temp;
                temp = temp->link;
            }

            if(temp == NULL){
                cout<<"The memeber not found"<<endl;
            }
            prev->link = temp->link;
            delete temp;
            cout<<"Member with"<< prn << " is deleted"<<endl;
            
        }


        void display(){
            Node* temp =  head;
            cout<<"---President---"<<endl;
            cout<<temp->name<<" "<<temp->prn<<endl;
            cout<<endl;
            cout<<"--Members--"<<endl;
            temp = temp->link;
            while(temp->link != NULL){
                cout<<temp->name<< " "<<temp->prn<<endl;
                temp = temp->link;
            }
            cout<<endl;
            cout<<"--Secretary---"<<endl;
            cout<<temp->name<<" "<<temp->prn<<endl;
        }

        void concatenate(LinkedList& otherlist){
            Node* temp = head;  
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = otherlist.head;
			otherlist.head = nullptr;
        }

};


int main(){
    LinkedList l;
    LinkedList l2;
    l.insert("Aj", 10);
    l.insert("Sj", 20);

    l.insertBetween("ssd", 223);
    l.display();
    l.display();

    l2.insert("tj", 19);

    l.concatenate(l2);
    l.display();
    return 0;
}