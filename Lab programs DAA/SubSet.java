
import java.util.*;

public class SubSet {

    public void findSubset(int[] x,int target){
        List<Integer> subset=new ArrayList<Integer>() ;
        List<List<Integer>> result =new ArrayList<List<Integer>>() ;
        
        subsetSumHelper(x,target,0,subset,result);

        for(List<Integer> s:result){
            System.out.print(s+" ");
        }
    }
        public static void subsetSumHelper(int[] X,int targetValue,int index,List<Integer> subSet , List<List<Integer>> Result){
                
               if(targetValue==0){
                Result.add(subSet);
                return;
               }
               if(targetValue<0 || index==X.length){return ;}
                subSet.add(X[index]);
               subsetSumHelper(X,targetValue-X[index],index+1,subSet,Result);
                subSet.remove(subSet.size()-1);
                subsetSumHelper(X,targetValue,index+1,subSet,Result);
        }
        
    
    public static void main(String[] args) {
        
    }
}
