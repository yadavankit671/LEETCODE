import java.util.Arrays;

class Solution{
    public int minMovesToSeat(int[] seats,int[] students){
        int result=0;
        Arrays.sort(seats);
        Arrays.sort(students);
        for(int i=0;i<seats.length;i++){
            result+=Math.abs(seats[i] - students[i]);
        }
        return result;
    }
}
public class P2037 {

}
