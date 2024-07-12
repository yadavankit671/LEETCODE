class Solution {
    public int maximumGain(String str, int x, int y) {
        int score = 0;
        char high = 'a';
        char low = 'b';
        if (x < y){
            x = x + y;
            y = x - y;
            x = x - y;
            char tmp2 = high;
            high = low;
            low = tmp2;
        }
        int highCount = 0, lowCount = 0;
        for (char ch : str.toCharArray()){
            if (ch == high) highCount++;
            else if (ch == low){
                if (highCount > 0){
                    highCount--;
                    score += x;
                }
                else lowCount++;
            }
            else{
                score += Math.min(highCount, lowCount) * y;
                highCount = lowCount = 0;
            }
        }
        score += Math.min(highCount, lowCount) * y;
        return score;
    }
}
public class P1717 {
    public static void main(String[] args) {
        Solution obj = new Solution();
        String str = "cdbcbbaaabab";
        int x = 4;
        int y = 5;
        System.out.println(obj.maximumGain(str, x, y));
    }
}
