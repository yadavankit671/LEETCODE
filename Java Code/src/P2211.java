class Solution {
    public int countCollisions(String directions) {
        int result = 0;
        int size = directions.length();
        int start = 0;
        int end = size - 1;
        while (start < size && directions.charAt(start) == 'L') start++;
        while (end >= 0 && directions.charAt(end) == 'R') end--;
        while (start <= end) {
            if (directions.charAt(start) != 'S') result++;
            start++;
        }
        return result;
    }
}
public class P2211 {

}
