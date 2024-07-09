import java.util.Arrays;
class Solution {
    private boolean Solve(int[] position,int m, int midForce){
        int prevValue=position[0];
        int count=1;
        for(int i=1;i<position.length;i++){
            if(position[i]-prevValue>=midForce){
                prevValue=position[i];
                count++;
            }
            if(count>=m) break;
        }
        return count>=m;
    }
    public int maxDistance(int[] position, int m) {
        int result=0;
        Arrays.sort(position);
        int minForce=1;
        int maxForce=position[position.length-1]-minForce;
        while(minForce<=maxForce){
            int midForce=minForce+(maxForce-minForce)/2;
            if(Solve(position, m, midForce)){
                result=midForce;
                minForce=midForce+1;
            }
            else maxForce=midForce-1;
        }
        return result;
    }
}

public class P1552 {
    public static void main(String[] args) {
        int[] position={79,74,57,22};
        int m=4;
        Solution obj=new Solution();
        System.out.println(obj.maxDistance(position, m));
    }
}
