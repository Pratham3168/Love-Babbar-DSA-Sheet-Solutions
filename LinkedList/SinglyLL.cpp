#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    //deconstructor
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }

};


void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next=temp;
    tail=temp;

}


void insertAtPosition(Node* & tail,Node* &head,int data, int pos){
    if(pos == 1){
        insertAtHead(head,data);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    if(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(temp,data);
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;    
    temp->next = nodeToInsert;
}

//===================PRINTING THE NODE==================
void print(Node* head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return ;
    }
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


void deleteNode(Node* &head,int pos){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next=NULL;
    }
    else{
        int cnt = 1;
        Node* prev = NULL;
        Node* curr = head;
        while(cnt<pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main(){


    //CREATING AND EXPERIMENTING WITH NEW NODE
    // Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    // Node* node2=new Node(20);
    // cout<<node2->data<<endl;
    // cout<<node1->next<<endl;
    // node1->next = node2;
    // cout<<node1->next->data<<endl;
    // cout<<node1->next<<endl;
    // cout<<node2<<endl;



    //INSERTING NEW NODE AT THE HEAD OF LINKEDLIST
    // Node* node1 = new Node(20);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    // cout<<node1<<endl;
    // insertAtHead(node1,100);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    // cout<<node1->next->data<<endl;
    // cout<<node1->next->next<<endl;



    //INSERTING NEW NODE AT THE TAIL OF LINKED LIST
    // Node* node1 = new Node(20);
    // Node* tail=node1;
    // print(node1);
    // insertAtTail(tail,30);
    // print(node1);
    // insertAtTail(tail,40);
    // print(node1);


    //INSERTING NEW NODE AT THE POSITION IN THE LINKED LIST
    // Node* node1 = new Node(10);
    // Node* head=node1;
    // Node* tail=node1;
    // insertAtTail(tail,20);
    // insertAtTail(tail,30);
    // insertAtTail(tail,40);
    // print(head);
    // insertAtPosition(tail,head,100,1);
    // print(head);
    // insertAtPosition(tail,head,200,3);
    // print(head);



    //DELETING A NODE FROM LINKED LIST
    // Node* node1 = new Node(10);
    // Node* head=node1;
    // Node* tail=node1;
    // insertAtTail(tail,20);
    // insertAtTail(tail,30);
    // insertAtTail(tail,40);
    // insertAtTail(tail,50);
    // insertAtTail(tail,60);

    // print(head);
    // deleteNode(head,4);
    // print(head);
    

    


}