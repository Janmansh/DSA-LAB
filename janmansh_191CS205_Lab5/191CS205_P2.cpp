#include<bits/stdc++.h>
using namespace std;

string infix;  // infix expression
int top = -1, current=0;  // current is the current infix token index and top is the top of the stack
char stac[1000];   // stack to store the operators

// push in the stack
void push(char k){
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
    
    if(current>=infix.length()){
        return token;
    }
    
    if(infix[current] >= 48 && infix[current] <= 57){
        
        for(; current < infix.length() ; current++){
            if(infix[current] >= 48 && infix[current] <= 57){
                token += infix[current];
            }
            else{
                break;
            }
        }
        
        return token;
    }
    else{
        
        token += infix[current];
        current++;
    }
    return token;
    
}

//  converting infix expression to postfix
void infixToPostfix(){
    
    string answer="";
    
    while(1){
        
        if(top==-1)break;
        string next = getNextToken();
        
        if(next=="")break;
        
        if((next[0] >= 48 && next[0] <= 57)||(next[0] >= 'a' && next[0] <= 'z')||(next[0] >= 'A' && next[0] <= 'Z')){
            answer += next;
            answer += " ";
        }
        
        else{
            
            if(next[0] == '('){
                push('(');
            }
            
            else if(next[0] == ')'){
                while(stac[top] != '('){
                    answer += stac[top];
                    answer += " ";
                    pop();
                }
                pop();
            }
            
            else if(next[0] == '-'){
                while(stac[top] != '('){
                    answer += stac[top];
                    answer += " ";
                    pop();
                }
                push('-');
            }
            
            else if(next[0] == '+'){
                while(stac[top] != '('){
                    answer += stac[top];
                    answer += " ";
                    pop();
                }
                push('+');
            }
            
            else if(next[0] == '*'){
                while(stac[top] != '(' && stac[top] !='+' && stac[top] != '-'){
                    answer += stac[top];
                    answer += " ";
                    pop();
                }
                push('*');
            }
            
            else if(next[0] == '/'){
                while(stac[top] != '(' && stac[top] !='+' && stac[top]!='-'){
                    answer += stac[top];
                    answer += " ";
                    pop();
                }
                push('/');
            }
            
            else if(next[0] == '^'){
                push('^');
            }
        }
    }
    
    cout<<"The postfix expression is: "<<answer<<"\n";
}


int main(){
    cout<<"Enter the infix expression\n";
    cin >> infix;
    
    infix += ')';
    
    push('(');
    infixToPostfix();
    
    return 0;
}
