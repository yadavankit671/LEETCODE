public class P168 {
    public String convertToTitle(int columnNumber) {
        StringBuilder st= new StringBuilder();
        while(columnNumber>0){
            columnNumber--;
            int rem=columnNumber%26;
            st.append((char)('A'+rem));
            columnNumber/=26;
        }
        return st.reverse().toString();
    }
}
