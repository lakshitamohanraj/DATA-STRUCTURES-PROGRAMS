#include <iostream>
using namespace std;
int main()
{
int a[20], n, temp, i, j;
cout<<"Enter the number of elements";
cin>>n;

cout<<"Enter the elements"<<endl;

for(i=0; i<n; i++) cin>>a[i];

bool swapped=false;
for(int i=1;i<=(n-1);i++){
    for(int j=1;j<=(n-i);j++){
        if(a[j-1] > a[j]){
           swapped=true;
        temp=a[j];
        a[j]=a[j-1];
        a[j-1]=temp;
        }
    for(int k=0;k<n;k++){
        cout<<a[k]<<" ";
    }     
    cout<<endl;   
    }
}
cout<<"sorted array is: "<<endl;
for(int i=0;i<n;i++) cout<<a[i]<<" ";
}