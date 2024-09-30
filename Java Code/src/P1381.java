import java.util.*;
class CustomStack {
    private List<Integer> st;
    private int maxSize;
    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        st = new ArrayList<>();
    }
    
    public void push(int x) {
        if(st.size() == maxSize) return;
        st.add(x);
    }
    
    public int pop() {
        if(st.size() == 0) return -1;
        return st.removeLast();
    }
    
    public void increment(int k, int val) {
        int n = Math.min(k, st.size());
        for(int i = 0; i < n; i++)
            st.set(i,st.get(i) + val);
    }
}
public class P1381 {

}
