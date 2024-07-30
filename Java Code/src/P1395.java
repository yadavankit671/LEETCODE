class Solution{
    public int numTeams(int[] ratings){
        int n = ratings.length;
        int result = 0;
        for(int j = 1; j < n-1; j++){
            int leftSmaller = 0;
            int leftLarger = 0;
            int rightSmaller = 0;
            int rightLarger = 0;
            for(int i = 0; i < j; ++i){
                if(ratings[i] < ratings[j]) leftSmaller++;
                else leftLarger++;
            }
            for(int k = j + 1; k < n; ++k){
                if(ratings[k] < ratings[j]) rightSmaller++;
                else rightLarger++;
            }
            result += leftSmaller * rightLarger + leftLarger * rightSmaller;
        }
        return result;
    }
}
public class P1395 {

}
