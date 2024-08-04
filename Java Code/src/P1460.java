class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        int[] mp = new int[1001];
        for(int x : arr) mp[x]++;
        for(int x : target) mp[x]--;
        for(int x : mp) if(x != 0) return false;
        return true;
    }
}
public class P1460 {

}
