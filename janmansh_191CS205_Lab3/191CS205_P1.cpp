#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
    char data;
    struct Node *link;
};

struct Node* InsertAtBeginning(struct Node *head)  //function to insert at beginning;
{
    struct Node *temp;
    char c;
    temp = (struct Node*)malloc(sizeof(struct Node));

    cout << "Enter the character to be inserted: ";
    fflush(stdin);
    cin >> c;
    cout<<endl;

    temp->data = c;
    temp->link = head;
    head = temp;

    return head;
}

struct Node* Search(struct Node *head, char key)   //function to serach given key
{
    struct Node *LOC;
    LOC = head;

    while(LOC!=NULL)
    {
        if(LOC->data == key)
        {
            cout<<"Key found"<<endl;
            cout<<endl;
            return LOC;
        }
        LOC = LOC->link;
    }

    cout<<"Key not found"<<endl;
    cout<<endl;
    return LOC;
}

void PrintList(struct Node *head)   //function to print current list
{
    struct Node *temp;
    temp = head;
    cout<<"List:  ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}

int main(void)
{
    struct Node *head = NULL,*LOC;
    int x=1;
    char c;

    cout<<"Enter:"<<endl;
    cout<<"1 : Insert at beginning"<<endl;
    cout<<"2 : Search element"<<endl;
    cout<<"3 : Print the list"<<endl;

    while(x)
    {
        cout<<"Enter the function number: ";
        cin>>x;
        cout<<endl;

        switch(x)
        {
            case 1: head = InsertAtBeginning(head);
                    break;

            case 2: cout<<"Insert key: ";
                    cin>>c;
                    LOC = Search(head,c); 
                    cout<<LOC->data<<endl;
                    break;

            case 3: PrintList(head);
                    break;

            default: cout<<"Invalid entry"<<endl;
        }

        cout<<"To continue editing list enter 1 else 0 to exit: ";
        cin>>x;
        cout<<endl;
    }
    return 0;
}
