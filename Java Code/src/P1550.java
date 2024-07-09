class Solution{
    public boolean threeConsecutiveOdds(int[] arr){
        int count=0;
        for(int x: arr){
            if(x%2!=0) count++;
            else count=0;
            if(count==0) return true;
        }
        return false;
    }
}
