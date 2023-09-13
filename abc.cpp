#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void inserthead(node*&head,int d)
{
    node*temp=new node(d);
    temp->next=head;
    head=temp;
}
void inserttail(node*&tail,int d)
{
    node*temp=new node(d);
    tail->next=temp;
    tail=tail->next;//tail=temp
}
void insertmid(node*&tail,node*&head,int position,int d)
{
    if(position==1)
    {
        inserthead(head,d);
        return;
    }

    node*temp=head;
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL)
    {
        inserttail(tail,d);
        return;
    }
    
    node*ans=new node(d);
    ans->next=temp->next;
    temp->next=ans;
}
void print(node *&head)//traversing a linked list
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;    
}
void deletenode(node*&head,int position)
{
    node*temp=head;
    int count=1;
    if(position==1)
    {
        node*
        head=head->next;
        return;
    }
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    node*del=temp->next;
    delete del;
    temp->next=(temp->next)->next;
}
int main()
{
    node* node1= new node(10);
    //cout<<node1->data<<endl ;
    //cout<<node1->next;
    node*head=node1;
    node*tail=node1;
    print(head);
    inserthead(head,5);
    print(head);
    inserthead(head,6); 
    print(head);
    inserttail(tail,7);
    print(head);
    insertmid(tail,head,1,23);
    print(head);
    //deletenode(head,2);
    //print(head);
    deletenode(head,1);
    print(head);
}