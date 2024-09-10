#include <iostream>
using namespace std;

template <typename T>
class Node{
private:
    T data;
    Node *next;

public:

    Node () {
        data=T();
        next=nullptr;
    }
    Node (T d){
        data=d;
        next=nullptr;
    }

    template <typename U>
    friend class singlylinkedlist;
};

template <typename T>
class singlylinkedlist{
private:
    Node<T> *head;

public:

    singlylinkedlist(){
        head=nullptr;
    }

    void insertAtStart(T d){                    //O(1)
        Node<T> *newnode=new Node<T>(d);
        
        if (!head){
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
        cout<<"Value added."<<endl;
    }

    void insertAtEnd(T d){                      //O(n)
        Node<T> *newnode=new Node<T>(d);

        if (!head){
            head=newnode;
        }
        else{
            Node<T> *temp=head;
            while (temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
            cout<<"Value added."<<endl;
        }
    }

    void print(){                               //O(n)
        if (head){
            Node<T> *temp=head;
            while (temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        else{
            cout<<"List empty"<<endl;
        }
    }

    bool search (T d){                          //O(n)
        if (head){
            Node <T> *temp=head;
            while (temp){
                if (temp->data==d){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }
        else{
            return false;
        }
    }

    bool isEmpty(){                             //O(1)
        if (!head){
            return true;
        }
        else{
            return false;
        }
    }

    bool insertBefore (T v1, T v2){             //O(n)
        Node<T> *newnode=new Node<T>(v1);
        Node <T> *temp=head;
        if (temp){
            while (temp){
                if (temp->data==v2){
                    newnode->next=temp;
                    head=newnode;
                    return true;
                }
                else if (temp->next->data==v2){
                    newnode->next=temp->next;
                    temp->next=newnode;
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }
        else{
            return false;
        }
    }

    void deleteAll(T d){                        //O(n)

        while (head !=nullptr && head->data==d){
            Node<T> *toDelete =head;
            head=head->next;
            delete toDelete;
        }

        Node <T> *temp=head;

        while (temp != nullptr && temp->next != nullptr){
            if (temp->next->data==d){
                Node <T> *toDelete =temp->next;
                temp->next=temp->next->next;
                delete toDelete;
            }
            else{
                temp=temp->next;
            }
        }
    }

    void deleteAtStart(){                       //O(1)
        if (head){
            head=head->next;
        }
    }
    
};

int main(){
    singlylinkedlist<int> sll;
    
    int x=1, val=0, val1=0;
    
    while (x!=0){
        cout<<"Press 1 to insert at start."<<endl;
        cout<<"Press 2 to insert at end."<<endl;
        cout<<"Press 3 to print."<<endl;
        cout<<"Press 4 to search value."<<endl;
        cout<<"Press 5 to check if empty."<<endl;
        cout<<"Press 6 to insert value before."<<endl;
        cout<<"Press 7 to delete all occurrences."<<endl;
        cout<<"Press 8 to delete from start."<<endl;

        cin>>x;

        switch (x)
        {
        case 1:
            cout<<"Enter value= "<<endl;
            cin>>val;
            sll.insertAtStart(val);
            break;

        case 2:
            cout<<"Enter value= "<<endl;
            cin>>val;
            sll.insertAtEnd(val);
            break;

        case 3:
            sll.print();
            break;

        case 4:
            cout<<"Enter value= "<<endl;
            cin>>val;
            if (sll.search(val)){
                cout<<"Value found."<<endl;
            }
            else{
                cout<<"Value not found."<<endl;
            }

            break;

        case 5:
            if (sll.isEmpty()){
                cout<<"List empty."<<endl;
            }
            else{
                cout<<"List not empty."<<endl;
            }

            break;

        case 6:
            cout<<"Insert value to add= "<<endl;
            cin>>val;
            cout<<"Insert value before= "<<endl;
            cin>>val1;

            if (sll.insertBefore(val,val1)){
                cout<<"Added."<<endl;
            }
            else{
                cout<<"Not added."<<endl;
            }

            break;

        case 7:
            cout<<"Enter value= "<<endl;
            cin>>val;
            sll.deleteAll(val);
            cout<<"Successful."<<endl;
            break;

        case 8:
            sll.deleteAtStart();
            cout<<"Successful."<<endl;
            break;
        
        default:
            break;
        }

        cout<<"Press 0 to end."<<endl;
        cin>>x;
    }

}