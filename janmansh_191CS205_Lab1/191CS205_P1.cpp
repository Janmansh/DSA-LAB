#include<bits/stdc++.h>
using namespace std;

int main(){
    
	int i,j;
	char *a,c;
	
	a = (char*) malloc(sizeof(char));
	
	cout<<"Enter elements of the string: \n";
	i=0;
	
	while(c!='\n'){
	    
	    c=getchar();
	    void *x = realloc(a, (sizeof(char)));
	    
	    if(c==' ')continue;
        a[i++] = c;
	}
	
	char *ptr=a;
	cout<<"Alternate Elements are : \n";
	
	for(;ptr<(a+i);++ptr){
	    cout<<*ptr<<" ";
	    ++ptr;
	}
	
	cout<<"\n";
	return 0;
}

