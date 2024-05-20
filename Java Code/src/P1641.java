class Solution1641 {
    private int accumulate(int[] arr){
        int result=0;
        for(int x:arr) result+=x;
        return result;
    }
    public int countVowelStrings(int n) {
        int [][] dp=new int[n][5];
        for (int i=0;i<dp.length;i++) dp[i][0]=1;
        for(int i=0;i<5;i++) dp[0][i]=1;
        /*
        Matrix initialized ...
        1           1            1          1           1       
        1    (i,j-1)+(i-1,j)
        1
        1
        1
        
        Final Matrix :
        1   1   1   1   1
        1   2   3   4   5
        1   3   6   10  15
        1   4   10  20  35
        1   5   15  35  70  ==> 70+35+15+5+1 = 126 --> answer
        */
        for(int i=1;i<n;i++){
            for(int j=1;j<5;j++)
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
        return accumulate(dp[n-1]);
    }
}
public class P1641 {
    public static void main(String[] args) {
        int n=3424;
        Solution1641 obj=new Solution1641();
        System.out.println(obj.countVowelStrings(n));
    }
}
