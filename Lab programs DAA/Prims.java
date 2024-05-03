import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.*;
import java.lang.*;
class Edges{
    int from;
    int to;
    int weight;
  public Edges(int from,int to,int weight){
       this.from=from;this.to=to;this.weight=weight;
    }
}
class EdgesComparator implements Comparator<Edges>{
    public int compare(Edges e1,Edges e2){
         return Integer.compare(e1.weight,e2.weight);
    }
}
public class Prims {
     
    public static void main(String[] args){
        int[][] edges = {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4}
            };
            int numVertices=4;
            findMinimumSpanningTree(edges,numVertices);
    }



    public static void findMinimumSpanningTree(int[][]edges,int numVertices){
        PriorityQueue<Edges> minHeap=new PriorityQueue<>(new EdgesComparator());

        List <Edges> minimumSpanningTree = new ArrayList<>();
        int mincost=0;
        Boolean []visited=new Boolean[numVertices];
        for(int i=0;i<numVertices;i++){visited[i]=false;}
        int startVertex=0;
        visited[startVertex]=true;

        for(int []edge:edges){
            if(edge[0]==startVertex){
                minHeap.offer(new Edges(edge[0],edge[1] ,edge[2]));
            }
        }

        while(!minHeap.isEmpty() && minimumSpanningTree.size()<numVertices-1){
            Edges edges1=minHeap.poll();
            int fromVertex=edges1.from;
            int toVertex=edges1.to;
            int weight=edges1.weight;
            minimumSpanningTree.add(edges1);
            if(!visited[toVertex] && visited[fromVertex]){
                   
                visited[toVertex]=true;
                for(int[]nextEdge:edges){
                    if(nextEdge[0]==toVertex && !visited[nextEdge[1]])
                    minHeap.offer(new Edges(nextEdge[0], nextEdge[1], nextEdge[2]));
                }

                mincost+=weight;
            }
        }
    
        for(Edges edge : minimumSpanningTree){
            System.out.print("Edges -> "+edge.from+"=="+edge.to+" "+edge.weight+"\n");
        }


    }
    
}
