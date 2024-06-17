class Solution633{
    public boolean judgeSquareSum(int c) {
        if(c==0 || c==1) return true;
        int start=0;
        int limit=(int) Math.sqrt(c);
        while(start<=limit){
            int temp=(int)Math.pow(start,2);
            int diff=c-temp;
            diff=(int)Math.sqrt(diff);
            if((int) Math.pow(diff,2)+temp==c) return true;
            start++;
        }
        return false;
    }
}
public class P633 {

}
