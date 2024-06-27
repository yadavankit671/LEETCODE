import java.util.*;
public class P77 {
    private void BackTracking(List<List<Integer> > list,int start,int end,int k,List<Integer> temp){
        if(temp.size()==k) {
            list.add(new ArrayList<>(temp));
            return;
        }
        for(int i=start;i<=end;i++){
            temp.add(i);
            BackTracking(list, i+1, end, k,temp);
            temp.removeLast();
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer> > result= new ArrayList<>();
        BackTracking(result, 1, n, k, new ArrayList<>());
        return result;
    }
    public static void main(String[] args) {
        int k=1;
        int n=10;
        P77 obj=new P77();
        List<List<Integer> > result= obj.combine(n,k);
        for(List<Integer> list : result){
            System.out.println(list.toString());
        }
    }
}
