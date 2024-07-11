class Solution {
    public int minOperations(String[] logs) {
        String back="../";
        String same="./";
        int result =0;
        for(String str : logs){
            if(str.equals(back)) result-=(result>0)?1:0;
            else if (str.equals(same)) continue;
            else result++;
        }
        return (result<0) ? 0 : result;
    }
}
public class P1598 {
    public static void main(String[] args) {
        Solution obj= new Solution();
        String[] logs={"d1/","d2/","./","d1/","./"};
        System.out.println(obj.minOperations(logs));
    }
}
