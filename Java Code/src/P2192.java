import java.util.*;
public class P2192 {
    private void DFS(List<List<Integer>> result,List<List<Integer>> adList,int child,int parent){
        for(Integer x : adList.get(child)){
            if(result.get(x).isEmpty() || result.get(x).getLast()!=parent){
                result.get(x).add(parent);
                DFS(result,adList,x,parent);
            }
        }
    }
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> result= new ArrayList<>(n);
        List<List<Integer>> adjList= new ArrayList<>();
        for(int i=0;i<n;i++){
            result.add(new ArrayList<>());
            adjList.add(new ArrayList<>());
        }
        for(int[] node : edges){
            adjList.get(node[0]).add(node[1]);
        }
        for(int i=0;i<n;i++){
            DFS(result,adjList,i,i);
        }
        return result;
    }
    private void print(List<List<Integer> > ans){
        for(List<Integer> v:ans){
            if(v.isEmpty()) {
                System.out.println("[]");
                continue;
            }
            System.out.print("["+v.get(0));
            for(int i=1;i<v.size();i++) System.out.print(","+v.get(i));
            System.out.println("]");
        }
    }
    public static void main(String[] args) {
        P2192 obj= new P2192();
        int[][]edges={{0,3},{5,0},{2,3},{4,3},{5,3},{1,3},{2,5},{0,1},{4,5},{4,2},{4,0},{2,1},{5,1}};
        int n=6;
        obj.print(obj.getAncestors(n,edges));
    }
}
