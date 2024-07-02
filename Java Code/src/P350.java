import java.util.*;

public class P350 {
    public int[] intersect(int[] nums1, int[] nums2) {
        // Using Map and counting frequencies
        /*
        Map<Integer,Integer> freq1= new HashMap<>();
        Map<Integer,Integer> freq2= new HashMap<>(); // or do not use this and traverse the nums2 and decrement the freq1 value and add in result
        for(int num: nums1) freq1.put(num, freq1.getOrDefault(num,0)+1);
        for(int num: nums2) freq2.put(num, freq2.getOrDefault(num,0)+1);
        List<Integer> result= new ArrayList<>(); // can take a int[] array of (nums1+nums2).length
        Iterator<Map.Entry<Integer, Integer>> itr = freq1.entrySet().iterator();
        while(itr.hasNext()){
            Map.Entry<Integer, Integer> entry= itr.next();
            int num=entry.getKey();
            int min=Math.min(entry.getValue(), freq2.getOrDefault(num,0));
            for(int i=0;i<min;i++) result.add(num);
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
        */
        // more efficient since array[i] is limited to 1000
        int[] freq= new int[1001];
        for(int num: nums1) freq[num]++;
        int[] result= new int[1001];
        int range=0;
        for(int x : nums2){
            if(freq[x]>0){
                result[range]=x;
                range++;
                freq[x]--;
            }
        }
        return Arrays.copyOfRange(result, 0, range);
    }
}
