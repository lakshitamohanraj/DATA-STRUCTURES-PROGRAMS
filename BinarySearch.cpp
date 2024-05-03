#include<iostream>
using namespace std;
int main()

{
int a[100], n, low, high , middle, i, key;
cout<<"Enter the number of elements";
cin>>n;
cout<<"Enter the elements in sorted order";
for(i=0; i<n; i++)
{

cin>>a[i];

}
cout<<"Enter the value to be searched";
cin>>key;
low = 0;
high = n-1;
middle = (low + high) / 2;

while (low <= high)
{
  
  if( key == a[middle]){
  cout<<key<<"found at location"<< middle;
    break;
  }

  else if( key < a[middle]) high = middle - 1;

  else if(key > a[middle] )low = middle + 1;
   
middle = (low + high) / 2;
}

if( low > high)
{
cout<<"Search key is not found";
}
}