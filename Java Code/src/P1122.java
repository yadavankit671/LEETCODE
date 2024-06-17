import java.util.*;

class Solution1122 {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashMap<Integer,Integer> mp= new HashMap<>();
        for(int i=0;i<arr2.length;i++){
            mp.put(arr2[i],i);
        }
        Integer[] temp= Arrays.stream(arr1).boxed().toArray(Integer[]::new);
        Arrays.sort(temp,(a,b)->{
            if(a==b) return 1;
            if(mp.containsKey(a) && mp.containsKey(b)) return (mp.get(a)-mp.get(b)) ;
            else if(mp.containsKey(a)) return -1;
            else if(mp.containsKey(b)) return 1;
            else return a-b;
        });
        for(int i=0;i<temp.length;i++){
            arr1[i]=temp[i];
        }
        return arr1;
    }
}
public class P1122 {
    public static void main(String[] args) {
        /*
         * arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
         */
        int[] arr1={2,3,1,3,2,4,6,7,9,2,19};
        int[] arr2={2,1,4,3,9,6};
        Solution1122 obj= new Solution1122();
        int[] res= obj.relativeSortArray(arr1, arr2);
        System.out.println(Arrays.toString(res));
    }
}
