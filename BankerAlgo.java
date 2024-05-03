package demo01;
import java.util.Scanner;

public class BankerAlgo{

    public static void Bankers(int np,int nr,int []avaiable,int[][]need,int[][]allocation){
             int finish[]=new int[np];
             int safe_seq[]=new int[20];
             Boolean flag=false;
             int k=0;
             System.out.println("Inside Bankers function");
             displaymatric(need);
             displaymatric(allocation);
             for(int x:avaiable) {
            	 System.out.print(x);
             }
             for(int i=0;i<np;i++){
                finish[i]=0; //all are not in safe state initial value
             }
             for(int i=0;i<np;i++){
                flag=false;
                if(finish[i]==0) {
                	
                for(int j=0;j<nr;j++){
                            if(need[i][j]>avaiable[j]){
                            	flag=true;
                            	
                            	System.out.println(need[i][j]+" "+avaiable[j]);
                                break;
                            }
                       System.out.println(flag);     
                            
                }
                
                }
                
                if(flag==false){
                	
                     finish[i]=1;
                     safe_seq[k++]=i;
                    
                     for(int j=0;j<nr;j++)
                     {
                    	 avaiable[j]=avaiable[j]+allocation[i][j];
                    	 }
                     i=-1;//again goes from top
                }
             }

             for(int i=0;i<np;i++){
                if(finish[i]==0){
                    System.out.println("The system is in deadlock");
                    flag=true;
                     break;
                }
             }
             if(flag==false){
                System.out.println("The system is in safe state");
                System.out.println("The safe sequence is \n");
                for(int i=0;i<np;i++){
                    System.out.print(safe_seq[i]+" ");
                }
             }

    }
    public static void displaymatric(int max[][]){

        for(int i=0;i<max.length;i++){
            for(int j=0;j<max[i].length;j++){
                System.out.print(max[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        //Read data allocation 2d , max 2d, available 1d, create need 2d
        System.out.println("Enter the Number of Processor:");
          int np=sc.nextInt();
          System.out.println("Enter the Number of Resources Type:");
          int nr=sc.nextInt();
          int allocation[][]=new int[np][nr];
          int max[][]=new int[np][nr];
          int available[]=new int[nr];
          int need[][]=new int[np][nr];
        System.out.println("Enter the Allocation table\n");
          for(int i=0;i<np;i++){
            for(int j=0;j<nr;j++){
                allocation[i][j]=sc.nextInt();
            }
          }
          displaymatric(allocation);
           System.out.println("Enter the Maximum Resource table\n");         
          for(int i=0;i<np;i++){
            for(int j=0;j<nr;j++){
                max[i][j]=sc.nextInt();
            }
          }
           displaymatric(max);
System.out.println("Enter the Available for each Resource Type\n");
          for(int i=0;i<nr;i++){
           available[i]=sc.nextInt();
          }
     //calculating need matrix
          for(int i=0;i<np;i++){
            for(int j=0;j<nr;j++){
                need[i][j]=max[i][j]-allocation[i][j];
            }
          }
          displaymatric(need);
 Bankers(np, nr, available, need, allocation);

    }
}
