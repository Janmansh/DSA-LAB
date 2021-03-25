#include <bits/stdc++.h>
using namespace std;

struct stud{
    int roll;
    float marks;
    string name;
};


void merge(struct stud a[], int low, int mid, int up)
{
    int n1 = mid - low + 1;     // number of elements less than the middle element
    int n2 = up - mid;          // number of elements greater than the middle element
 
    int Left[n1], Right[n2], i, j;
 
    for(i = 0; i < n1; i++)
        Left[i] = a[low + i].roll;
    for(int j = 0; j < n2; j++)
        Right[j] = a[mid + 1 + j].roll;
        
    
    i=0,j=0;
 
    int k = low;
 
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            a[k].roll = Left[i];
            i++;
        }
        else {
            a[k].roll = Right[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        a[k].roll = Left[i];
        i++;
        k++;
    }
 
    
    while (j < n2) {
        a[k].roll = Right[j];
        j++;
        k++;
    }
}


void mergesort(struct stud a[],int low,int up){
    
    if(low >= up){
        return;
    }
    
    int mid = (low + up -1) / 2;    // finding the middle of the given range
    mergesort(a, low, mid);         // sorting from start to middle
    mergesort(a, mid+1, up);        // sorting from middle to friend
    
    merge(a, low, mid, up);         // merging both the sorted parts
}


int partition (struct stud a[], int low, int up)  
{  
    int pivot = a[low].roll;    // taking pivot as the first element
    
    int i = (up + 1), j;
  
    for(j=up;j>low;j--)  
    {  
        if(a[j].roll > pivot){  // swapping element if any element greater than pivot
            i--;
            struct stud temp;     
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }  
    }
    
    struct stud temp;
    temp=a[i-1];
    a[i-1]=a[low];
    a[low]=temp;
    
    return(i-1);  // actual position of the pivot or first element
}

void quicksort(struct stud a[], int low, int up)  
{  
    if(low < up){
        
        int pi = partition(a, low, up);  // position of pivot element
  
        quicksort(a, low, pi - 1);  
        quicksort(a, pi + 1, up);  
    }  
} 


// code starts here

int main() {
    
	int n;  // size of students
	cout<<"Enter the number of students: ";
	cin>>n;
	
	struct stud student[n];
	for(int i=0;i<n;i++){
	    cout << "Enter the student's Roll number(integer), marks(Floating) and Name(string) respectively\n";
	    cin >> student[i].roll >> student[i].marks >> student[i].name;
	}
	
	cout<<"Enter '1' for Quick sort and '2' for Merge sort\n";
	int k;
	cin>>k;
	
	if(k==1){
	    
	    cout << "\nStructure before sorting is: \n";
	    
	    for(int i=0;i<n;i++){
	        cout << "Roll no. :" << student[i].roll << "  Marks: " << student[i].marks << "  Name: " << student[i].name << "\n";
	    }
	    
	    quicksort(student, 0, n-1);
	    
	    cout << "\nStructure after sorting is: \n";
	    
	    for(int i=0;i<n;i++){
	        cout << "Roll no. :" << student[i].roll << "  Marks: " << student[i].marks << "  Name: " << student[i].name << "\n";
	    }
	}
	
	else if(k==2){
	    
	    cout << "\nStructure before sorting is: \n";
	    
	    for(int i=0;i<n;i++){
	        cout << "Roll no. :" << student[i].roll << "  Marks: " << student[i].marks << "  Name: " << student[i].name << "\n";
	    }
	    
	    mergesort(student, 0, n-1);
	    
	    cout << "\nStructure after sorting is: \n";
	    
	    for(int i=0;i<n;i++){
	        cout << "Roll no. :" << student[i].roll << "  Marks: " << student[i].marks << "  Name: " << student[i].name << "\n";
	    }
	}
	
	return 0;
}

