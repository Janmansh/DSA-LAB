#include<bits/stdc++.h>
using namespace std;

string postfix;  // postfix expression (can be integers as well as alphabets with underscore as seperator)
int top = -1, current=0;  // current is the current postfix token index and top is the top of the stack
string stac[1000];   // stack to store the operators

// push in the stack
void push(string k){
    if(top==-1){   // if stack is empty
        top=999;
        stac[top]=k;
    }
    else{
        top--;
        stac[top]=k;
    }
}

// pop from the stack
void pop(){
    if(top==999){    // if stack has last element
        top=-1;
    }
    else{
        top++;
    }
}

// get the next token
string getNextToken(){
    string token="";
    
    if(current>=postfix.length()){
        return token;
    }
    
    if(postfix[current] >= 48 && postfix[current] <= 57){
        
        for(; current < postfix.length() ; current++){
            if(postfix[current] >= 48 && postfix[current] <= 57){
                token += postfix[current];
            }
            else{
                break;
            }
        }
        current++;
        return token;
    }
    else{
        
        token += postfix[current];
        current++;
        current++;
    }
    return token;
    
}

//  converting postfix expression to prefix
void PostfixToPrefix(){
    
    string answer="";
    
    while(1){
      
        string next = getNextToken();
        
        if(next=="")break;
        
        if((next[0] >= 48 && next[0] <= 57)||(next[0] >= 'a' && next[0] <= 'z')||(next[0] >= 'A' && next[0] <= 'Z')){
            push(next);
        }
        
        else{
            string op1 = stac[top];
            pop();
            string op2 = stac[top];
            pop();
            
            answer = next + " " + op2 + " " + op1 + " ";
            push(answer);
        }
    }
    
    cout<<"The postfix to prefix expression is: "<<stac[top]<<"\n";
}


int main(){
    cout<<"Enter the postfix expression (seperate tokens by an underscore '_')\n";
    
    // seperate tokens by  an underscore '_'
    cin >> postfix;
    
    PostfixToPrefix();
    
    return 0;
}

