
import java.util.Scanner;
public class QuickSort {
    public static void quickSort(int[]arr,int l,int r){
        if(l<r){
            int index=partition(arr, l, r);
            quickSort(arr, l, index-1);
            quickSort(arr, index+1, r);
        }

    }
    public static void swap(int[]arr,int i,int j){
       int temp=arr[i];
       arr[i]=arr[j];
       arr[j]=temp;
    }
    public static int partition(int[]arr,int l,int r){
        int pivot=arr[l];
        int i=l;
        int j=r;
        while(i<j){
        while(arr[i]<=pivot)
        {
            i++;
        }
       while(arr[j]>pivot){
        j--;
       }

        if(i<j){
            swap(arr,i,j);
        }
    }
    if (i > j) {
        swap(arr, l, j);
    }
        return j; //partioned position returns 
    }
public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int[]arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=sc.nextInt();
    }
    quickSort(arr,0,arr.length-1);
    for(int i=0;i<n;i++){
        System.out.print(arr[i]+" ");
    }
}    
}
