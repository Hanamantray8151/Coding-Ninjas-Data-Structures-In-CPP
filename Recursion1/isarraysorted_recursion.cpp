#include<iostream>
using namespace std;

bool issorted(int a[],int size){
    if(size==0 || size==1){
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }
    bool issmallersorted = issorted(a+1,size-1);
    return issmallersorted;
}
int main(){
    int n,i;
    cout<<"Enter Size of array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter array elements"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl<<issorted(a,n)<<endl;
    return 0;
} 