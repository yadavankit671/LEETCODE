import java.util.*;
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        List<Integer> indices = new ArrayList<>();
        for(int i=0;i<heights.length;i++) indices.add(i);
        indices.sort((a,b)->{
            return heights[b]-heights[a];
        });
        String[] result = new String[heights.length];
        int index = 0;
        for(int x : indices){
            result[index++]=names[x];
        }
        return result;
    }
}
public class P2418 {

}
