
import java.util.*;

public class MaxFlow {
    boolean bfs(int[][]graph,int source,int des,int p[],int Vertices){
             
     Boolean []visited=new Boolean[Vertices];
     for(int i=0;i<Vertices;i++){visited[i]=false;}
     LinkedList<Integer> queue=new LinkedList<>();
     
      queue.add(source);
      p[source]=-1;
      visited[source]=true;

      while(queue.size()!=0){
        int u=queue.poll();
        for(int v=0;v<Vertices;v++){
            if(!visited[v] && graph[u][v]>0){
                queue.add(v);
                p[v]=u;
                visited[v]=true;
            }
        }
      }
      return (visited[des]==true);



    }
    public int fordfulkerson(int[][]graph,int source,int des,int Vertices){
  int u,v;
      int max_flow=0;
      int [][]Graph=new int[Vertices][Vertices];
int path_flow=0;
int[]p=new int[Vertices];
      for(int i=0;i<Vertices;i++){
        for(int j=0;j<Vertices;j++){
            Graph[i][j]=graph[i][j];
        }
      }

      while(bfs(Graph, source, des,p, Vertices)){
           path_flow=Integer.MAX_VALUE;
           for( v=des;v!=source;v=p[v]){
                 u=p[v];
                 path_flow=Math.min(path_flow,Graph[u][v]);
           }


           for(v=des;v!=source;v=p[v]){
            u=p[v];
            Graph[u][v]-=path_flow;
            Graph[v][u]+=path_flow;
           }
           max_flow += path_flow;
      }
  return max_flow;

    }
    public static void main(String[] args) {
int n;
 int graph[][] = {{ 0, 8, 0, 0, 3, 0 },
 { 0, 0, 9, 0, 0, 0 },
 { 0, 0, 0, 0, 7, 2 },
 { 0, 0, 0, 0, 0, 5 },
 { 0, 0, 7, 4, 0, 0 },
 { 0, 0, 0, 0, 0, 0 }};

n=6;
 MaxFlow m = new MaxFlow();
 System.out.println("Maximum Flow: " + m.fordfulkerson(graph, 0, 5 , n));
//  sc.close();
 }
    }














