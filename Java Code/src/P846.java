import java.util.*;

class Solution846 {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if(hand.length%groupSize!=0) return false;
        Map<Integer,Integer> mp= new HashMap<>(); // beacause it is sorted 
        for(int x : hand)   mp.put(x,mp.getOrDefault(x, 0)+1);
        while(!mp.isEmpty()){
            int num=mp.keySet().iterator().next();
            for(int i=0;i<groupSize;i++){
                if(!mp.containsKey(num+i)) return false;
                mp.put(num+i,mp.get(num+i)-1);
                if(mp.get(num+i)==0) mp.remove(num+i);
            }
        }
        return true;
    }
}
public class P846 {
    public static void main(String[] args) {
        int[] hand={1,2,3,6,2,3,4,7,8};
        Solution846 obj= new Solution846();
        int groupSize=3;
        System.out.println(obj.isNStraightHand(hand, groupSize));
    }
}
