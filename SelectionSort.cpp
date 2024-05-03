#include<iostream>
using namespace std;

int main()
{
int a[10], n, min, temp, i, j;
cout<<"Enter the number of elements";
cin>>n;
cout<<"Enter the elements ";
for(i=0; i<n; i++) cin>>a[i];

for(i=0; i<n-1; i++)
{
min = i;
    for(j=i+1; j<n; j++)
    {
     if( a[j] < a[min]){ min=j;}
    }
if(min!=i){    
temp = a[i];
a[i] = a[min];
a[min] = temp;
}

}
cout<<"Sorted array";

for(i=0; i<n; i++) cout<<a[i]<<" ";
}