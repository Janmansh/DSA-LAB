#include<bits/stdc++.h>
using namespace std;

int main(){
    
	int n,m,i,j;
	
	cout<<"Enter size of array: ";
	
	cin>>n;
	int a[n];

	cout<<"Enter elements of the array: \n";
	for(i=0;i<n;i++){
	    cin>>a[i];
	}
	
	m=a[0];
	int *ptr=a;
	
	cout<<"Minimum Element is : ";
	
	for(;ptr<(a+n);++ptr){
	    if(*ptr<m){
	        m=(*ptr);
	    }
	}
	
	cout<<m<<"\n";
	
	return 0;
}

