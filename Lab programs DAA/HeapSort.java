import java.util.Scanner;

public class HeapSort {


    public static void display(int[]arr){
        System.out.println("Display arr");
       for(int i=0;i<arr.length;i++){
        System.out.print(arr[i]+" ");
       }
       System.out.println();
    }
    public static void heapSort(int[]arr,int n){
   //max heap formation
   for(int i=(n/2)-1;i>=0;i--){
    Heapify(arr,n,i);

   }
   //System.out.println("After max heap:");
  // display(arr);
   //deleteion
   for(int i=n-1;i>=0;i--){
    swap(arr,0,i);
    //display(arr);
    Heapify(arr, i,0);
   }
    }
    public static void swap(int []arr,int i,int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    public static void Heapify(int[]arr,int n,int i){
          int largest=i;
          int l=2*i+1;
          int r=2*i+2;
          if(l<n && arr[largest]<arr[l]){
            largest=l;
          }
          if(r<n && arr[largest]<arr[r]){
            largest=r;
          }
          if(largest!=i){
            swap(arr, i, largest);
            Heapify(arr, n, largest);
          }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        heapSort(arr, arr.length);
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
