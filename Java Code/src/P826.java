import java.util.*;

class Pair{
    public int first,second;
    Pair(int first,int second){
        this.first=first;
        this.second=second;
    }
}

class Solution826 {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int result = 0;
        List<Pair> buff= new ArrayList<>(0);
        for(int i=0;i<profit.length;i++) buff.add(new Pair(difficulty[i],profit[i]));
        Comparator<Pair> cmp= new Comparator<Pair>(){
            public int compare(Pair p1, Pair p2){
                return p1.first - p2.first;
            }
        };
        buff.sort(cmp);
        Arrays.sort(worker);
        int j=0;int best=0;
        for(int i=0;i<worker.length;i++){
            while(j<buff.size() && buff.get(j).first<=worker[i]){
                best=Math.max(best,buff.get(j).second);
                j++;
            }
            result+=best;
        }
        return result;
    }
}

public class P826 {

}
