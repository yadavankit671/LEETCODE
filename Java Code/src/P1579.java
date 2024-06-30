import java.util.*;

public class P1579 {
    static class DSU{
        private int[] parent;
        private int[] rank;
        private int components;
        public DSU(int n){
            parent= new int[n+1];
            rank=new int[n+1];
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
            components=n;
        }
        public void Union(int u,int v){
            int x_parent=find(u);
            int y_parent=find(v);
            if(x_parent==y_parent) return;
            if(rank[x_parent]>rank[y_parent]){
                parent[y_parent]=x_parent;
            } else if(rank[y_parent]>rank[x_parent]){
                parent[x_parent]=y_parent;
            }
            else{
                parent[x_parent]=y_parent;
                rank[y_parent]++;
            }
            components--;
        }
        public int find(int x){
            if(x==parent[x]) return x;
            return parent[x]=find(parent[x]);
        }
        public boolean isSingleComponent(){
            return components==1;
        }
    }
    public int maxNumEdgesToRemove(int n, int[][] edges){
        DSU Alice = new DSU(n);
        DSU Bob = new DSU(n);
        Comparator<int[]> cmp = (int[] a , int[] b) ->{
            return b[0]-a[0];
        };
        Arrays.sort(edges,cmp);
        int edgeCount=0;
        for(int[] edge : edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            if(type==3){
                boolean flag=false;
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u, v);
                    flag=true;
                }
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u, v);
                    flag=true;
                }
                if(flag) edgeCount++;
            } else if(type==2){
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u, v);
                    edgeCount++;
                }
            }
            else{
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.Union(u, v);
                    edgeCount++;
                }
            }
        }
        if(Alice.isSingleComponent() && Bob.isSingleComponent()){
            return edges.length-edgeCount;
        }
        return -1;
    }
}
