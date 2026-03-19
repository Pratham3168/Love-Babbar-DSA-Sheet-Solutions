#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Memory is free for the node with data " << data << endl;
    }
};

void insertElement(Node *&tail, int element, int d)
{

    // if empty linked list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int ele)
{

    if (tail == NULL)
    {
        cout << "List is already empty, nothing to delete";
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != ele)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (prev == curr)
        {
            tail = NULL;
        }

        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
//PRINTING THE CIRCULAR LINKED LIST
void print(Node* &tail){
    Node* temp=tail;

    //empty list
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return ;
    }

    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    
    }while(tail!=temp);
    cout<<endl;
}



int main(){
    Node* tail= NULL;
    //INSERTING NODES IN THE CIRCULAR LINKED LIST
    insertElement(tail,5,3);
    print(tail);
    insertElement(tail,3,5);
    print(tail);
    insertElement(tail,5,7);
    print(tail);
    insertElement(tail,7,9);
    print(tail);
    insertElement(tail,5,6);
    print(tail);
    insertElement(tail,9,10);
    print(tail);
    insertElement(tail,3,4);
    print(tail);

    deleteNode(tail,5);
    print(tail);
}