import java.util.*;
class Solution40 {
    private void BackTracking(int[] candidates,int index,int target,List<List<Integer> > result,List<Integer> temp,int currSum){
        if(currSum==target){
            result.add(new ArrayList<>(temp));
            return;
        }
        for(int i=index;i<candidates.length;i++){
            if(currSum+candidates[i]>target) break;
            if(i>index && candidates[i]==candidates[i-1]) continue;
            temp.add(candidates[i]);
            BackTracking(candidates,i+1,target,result,temp,currSum+candidates[i]);
            temp.removeLast();
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer> > result=new ArrayList<List<Integer> >();
        List<Integer> temp=new ArrayList<Integer>();
        Arrays.sort(candidates);
        BackTracking(candidates,0,target,result,temp,0);
        return result;
    }
}
public class P40 {
    public static void main(String[] args) {
        int[] candidates={10,1,2,7,6,1,5};
        int target=8;
        Solution40 obj=new Solution40();
        List<List<Integer>> result=obj.combinationSum2(candidates, target);
        for(List<Integer> arr : result){
            System.out.println(Arrays.toString(arr.toArray()));
        }
    }
}
