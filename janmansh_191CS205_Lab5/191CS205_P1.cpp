#include<bits/stdc++.h>
using namespace std;

int stac[1000],top=-1; // declaration of stack and top element index

void push(){
    if(top==-1){
        top=1000;
    }
    if(top==0){
        cout<<"Stack is full\n";return;
    }
    cout<<"Enter the element \n";
    int k;
    cin>>k;
    top--;
    stac[top]=k;
}

void pop(){
    if(top==-1){
        cout<<"Stack is empty\n";return;
    }
    if(top==999){
        top=-1;
    }
    else{
        top++;
    }
}

void display(){
    if(top==-1){
        cout<<"Stack is empty\n";return;
    }
    cout<<"The elements of the stack are: ";
    while(top!=-1){
        cout<<stac[top]<<" ";
        pop();
    }
    cout<<"\n";
}


int main(){
    int k;
    while(1){
        cout<<"Enter '1' to delete an element, '2' to insert an element, '3' to display the elements of the stack and '0' to exit\n";
        cin>>k;
        if(k==1){
            pop();
        }
        else if(k==2){
            push();
        }
        else if(k==3){
            display();
        }
        else if(k==0){
            break;
        }
        else{
            cout<<"Enter a valid input\n";
        }
    }
}
