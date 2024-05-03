import java.util.ArrayList;
import java.util.List;

class Edges{
    int from;
    int to;
    int weight;
  public Edges(int from,int to,int weight){
       this.from=from;this.to=to;this.weight=weight;
    }
}
public class Kurskal {
    public static void main(String[] args) {
        
        int[][] edges = {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4}
            };
     int cost=0;
     int num=4;
     List<Edges> minimumSpanningTree=new ArrayList<>();
     DisjoinSet disjoinSet=new DisjoinSet(num);
     for(int[] edge:edges){
        int from=edge[0];
        int to=edge[1];
       int weight=edge[2];
        if(!disjoinSet.areConnected(from, to)){
            minimumSpanningTree.add(new Edges(from, to, weight));
            disjoinSet.union(from, to);
            cost+=weight;
        }
     }


     for(Edges edge : minimumSpanningTree){
        System.out.print("Edges -> "+edge.from+"=="+edge.to+" "+edge.weight+"\n");
    }
    }


}

class DisjoinSet{
    int parent[];
    DisjoinSet(int n){
        parent=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    public int find(int vertex){
        if(vertex==parent[vertex]) {return vertex;}
        else{
            return find(parent[vertex]);
        }
    }
    public void union(int v1,int v2){
        parent[find(v1)]=find(v2);
    }

    public boolean areConnected(int v1,int v2){
        return find(v2)==find(v1);
    }
}