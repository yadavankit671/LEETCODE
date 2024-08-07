class Solution{
    private int[][] memo;
    private int recur(int[] houses,int index, int n){
        if(index >= n) return 0;
        if(memo[index][1] == -1) memo[index][1] = recur(houses,index+1,n);
        if(memo[index][0] == -1) memo[index][0] = houses[index] + recur(houses, index + 2, n);
        return Math.max(memo[index][1],memo[index][0]);
    }
    public int rob(int[] houses){
        int n = houses.length;
        memo = new int[n][2];
        for(int i = 0; i < n; i++){
            memo[i][0] = -1;
            memo[i][1] = -1;
        }
        int result = recur(houses, 0, n);
        return result;
    }
}
public class P198 {
    public static void main(String[] args) {
        int[] houses = {1,2,3,1};
        Solution obj = new Solution();
        System.out.println(obj.rob(houses));
    }
}
