import java.util.Scanner;

public class FloydAlgo{

    public static void FloydShortesPath(int[][]graph,int n){
         for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                   if(graph[i][k]!=999 && graph[k][j]!=999 && graph[i][k]+graph[k][j]<graph[i][j])
                   {
                         graph[i][j]=graph[i][k]+graph[k][j];
                   }
                }
            }
         }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of vertices");
        int n=sc.nextInt();
        int[][]graph=new int[n][n];
        System.out.println("Enter 999 in case of infinity ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            graph[i][j]=sc.nextInt();
            }
        }
        FloydShortesPath(graph,n);
 

        System.out.println("The Shortest path for eachpair of vertices is :");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(graph[i][j]+" ");
            }
            System.out.println();
        }
    }
}