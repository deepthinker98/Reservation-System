#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    node* next=NULL;
};
node* head=NULL;

void create()
{

    node* temp=new node();
    char n;
    node* ptr;
    temp->data=n;
    temp->next=NULL;
    if(head!=NULL)
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    else
        head=temp;
}

void Book(int index)
{
    int i,c=0;
    char f;
    node* ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        c++;
        if(c==index-1)
            break;
    }
    if(ptr->data=='f')
        cout<<"\n***** Alert: Seat is already booked *****\n";
    else
        ptr->data='f';
}

void available_seats(int number)
{
    int c=0;
    char f;
    node* ptr;
    ptr=head;
    cout<<"Number of available seats are \n";
    while(ptr!=NULL)
    {
        if(ptr->data=='f')
            c++;
        ptr=ptr->next;
    }
    cout<<number-c;
    cout<<"\n";
    cout<<"Number of booked seats are \n";
    cout<<c;
    cout<<"\n";
}

void cancel(int number)
{
    int i;
    char f,n;
    node* ptr;
    ptr=head;
    for(i=0;i<number-1;i++)
    {
        ptr=ptr->next;
    }
    if(ptr->data!='f')
        cout<<"\n***** Error: Seat is not booked *****\n";
    else
    {
        ptr->data='n';
        cout<<"\n-------- Seat cancellation successful --------\n";
    }
}

void display()
{
    node* ptr;
    char f;
    ptr=head;
    cout<<"Entered elements are \n";
    while(ptr!=NULL)
    {
        if(ptr->data=='f')
            cout<<"X"<<" ";
        else
            cout<<"-"<<" ";
        ptr=ptr->next;
    }
    cout<<"\n";
}

int main()
{
    int i,number,index,n;
    char ch;
    cout<<"-----Enter the number of seats in the bus----- \n";
    cin>>n;
    for(i=1;i<=n;i++)
        create();

    ch='y';
    while(ch=='y')
    {
        cout<<"\n-----1.Book a seat-----\n";
        cout<<"\n-----2.Available seats or Booked seats-----\n";
        cout<<"\n-----3.Cancellation of booked seats-----\n";
        cout<<"\n-----4.Display the status of seats-----\n";

        int x;
        cout<<"\n====Enter your choice==== \n";
        cin>>x;

        if(x==1)
        {
            cout<<"---- Enter the seat number you want to book ---- \n";
            cin>>index;
            Book(index);
        }
        if(x==2)
        {
            available_seats(n);
        }
        if(x==3)
        {
            cout<<"Enter the seat number you want to cancel \n";
            cin>>number;
            cancel(number);
        }
        if(x==4)
        {
            display();
            cout<<"\n";
        }

        cout<<"Do you want to continue or not?(y/n) \n";
        cin>>ch;
    }
    cout<<"\n";
    return 0;
}
