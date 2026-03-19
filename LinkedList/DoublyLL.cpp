#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //CONSTRUCTOR
    Node(int d){
        this->data = d;
        this->next=NULL;
        this->prev=NULL;
    }

    //DESTRUCTOR
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &tail,Node* &head,int data){

    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }

    Node* temp = new Node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;

}

void insertattail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}



void insertatposition(Node* &tail,Node* &head,int position,int data){
    if(position==1){
        insertAtHead(tail,head,data);
        return ;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertattail(tail,head,data);
        return ;
    }
    Node* nodetoinsert=new Node(data);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}


//DELETE A NODE FROM A DESIRED POSITION
void deletenode(Node* &head,int position){
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;

        delete curr;
    }
}

int main(){

    //CREATING A NEW NODE
    // Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->prev<<endl;
    // cout<<node1->next<<endl;
    // node1->prev=new Node(5);
    // cout<<node1->prev->data<<endl;





}


