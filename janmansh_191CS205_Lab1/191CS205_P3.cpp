#include<bits/stdc++.h>
using namespace std;

struct document{
    int roll;
    float marks;
    string name;
}student[1000];

void insertion(int i){
    int r;
    float m;
    string n;
    cout<<"Enter roll number(integer) marks(floating point) and name respectively:  ";
    cin>>r>>m>>n;
    student[i].roll=r;
    student[i].marks=m;
    student[i].name=n;
    cout<<"\n";
    return;
}

void deletion(int n){
    int i;
    cout<<"Enter the index to be deleted: ";
    cin>>i;
    if(i>n){
        cout<<"You did not enter a valid index. Maximum elements = "<<n<<"\n\n";
    }
    for(;i<1000;i++){
        student[i]=student[i+1];
    }
    cout<<"\n";
    return;
}

void display(int n){
    int i;
    cout<<"Enter the index to be displayed: ";
    cin>>i;
    if(i>n){
        cout<<"You did not enter a valid index. Maximum elements = "<<n<<"\n\n";
    }
    cout<<"Roll no: "<<student[i].roll<<"\nMarks: "<<student[i].marks<<"\nName: "<<student[i].name<<"\n\n";
    return;
}

int main(){
    int i,j;
    i=1;
    while(true){
        cout<<"Enter '1': for inserting\nEnter '2': for deleting\nEnter '3': for displaying\nEnter '0': to exit\n";
        cin>>j;
        cout<<"\n";
        if(j==0)break;
        if(j==1){
            insertion(i);
            i++;
        }
        if(j==2){
            deletion(i);
            i--;
        }
        if(j==3){
            display(i);
        }
    }
	
	return 0;
}

