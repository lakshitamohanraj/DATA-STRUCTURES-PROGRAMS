

import java.util.Scanner;
public class MergSort{

    public static void merge(int [] data,int start,int mid,int end){
        int[]temp=new int[end-start+1];
        int i=start;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=end){
            if(data[i]<=data[j]){
                temp[k++]=data[i++];
            }
            else{
                temp[k++]=data[j++];
            }
        }
        while(i<=mid){
            temp[k++]=data[i++];
        }
        while(j<=end){
            temp[k++]=data[j++];
        }
        for(i=start;i<=end;i++){
            data[i]=temp[i-start];
        }

        
    }
    public static void sort(int []data,int l,int r){
        if(l<r){
          int m=(l+r)/2;
          sort(data,l,m);
          sort(data,m+1,r);
          merge(data,l,m,r);
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.print("Enter the Array");
        int[]arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        } 
        sort(arr,0,arr.length-1); 
        System.out.println("The sorted list is :");
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }     
    }
}