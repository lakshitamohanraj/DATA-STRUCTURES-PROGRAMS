
// import java.util.*;
// public class OBST
// {
// static int optCost(int freq[], int i, int j)
// {
// if (i>j) return 0;
// if (j == i) return freq[i];
// int fsum = sum(freq, i, j);
// int min = Integer.MAX_VALUE;

// for (int r = i; r <= j; ++r)
// {
// int cost = optCost(freq, i, r-1) + optCost(freq, r+1, j);
// if (cost <min)
// min = cost;
// }
// return min + fsum;
// }
//    static int optimalSearchTree(int keys[], int freq[], int n)
//      {
//      return optCost(freq, 0, n-1);
//     }

// static int sum(int freq[], int i, int j)
// {
// int s = 0;
// for (int k = i; k <=j; k++)
// s += freq[k];
// return s;
// }
// public static void main(String[] args) {
// Scanner sc=new Scanner(System.in);
// int a=sc.nextInt();
// int keys[] = new int[a];
// int freq[] = new int[a];
// for(int i=0;i<a;i++)
// {
// keys[i]=sc.nextInt();
// }
// for(int i=0;i<a;i++)
// {
// freq[i]=sc.nextInt();
// }
// int n = keys.length;
// System.out.println("Cost of Optimal BST is " +optimalSearchTree(keys, freq, n));

// sc.close();
// }
// } 



import java.util.Scanner;
public class OBST{

    public static int optCost(int[]freq,int i,int j){
        if(i==j){return freq[i];}
        if(i>j){return 0;} //  why 0 doubt ????
        int fsum=sum(freq, i, j);
       int min=Integer.MAX_VALUE;
       int cost=0;
        for(int r=i;r<=j;r++){
           cost=optCost(freq, i, r-1)+optCost(freq, r+1, j);
           if(cost<min){
            min=cost;
           }
        }
        return min+fsum;
    }
    public static int optimalSearchTree(int[]key,int[]freq,int i,int n){
               return optCost(freq,0,n-1);
    }
    public static int sum(int[]freq,int i,int j){
        int sum=0;
        for(int k=i;k<=j;k++){
            sum=sum+freq[k];
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int key[]=new int[n];
        int freq[]=new int[n];

        for(int i=0;i<n;i++){
            key[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++){
            freq[i]=sc.nextInt();
        }

        System.out.println("Optimal binary search tree cost :"+optimalSearchTree(key,freq,0,n));
    }
}

