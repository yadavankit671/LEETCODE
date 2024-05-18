class Solution43 {
    private String addition(String one, String two) {
        StringBuilder ans = new StringBuilder();
        int carry = 0;
        int i = one.length() - 1, j = two.length() - 1;
        while (i >= 0 || j >= 0) {
            int val = carry;
            if (i >= 0) val += one.charAt(i) - '0';
            if (j >= 0) val += two.charAt(j) - '0';
            ans.insert(0, (char) (val % 10 + '0')); // Prepend the digit
            carry = val / 10;
            i--;
            j--;
        }
        if (carry > 0) ans.insert(0, (char) (carry + '0'));
        return ans.toString();
    }
    private void solve(String chota, String bada, String curr, int index, StringBuilder result) {
        if (index < 0) {
            result.replace(0, result.length(), curr); // Update result
            return;
        }
        long carry = 0;
        StringBuilder now = new StringBuilder();
        for (int i = index; i < chota.length() - 1; i++) now.append('0');
        char mul = chota.charAt(index);
        for (int i = bada.length() - 1; i >= 0; i--) {
            int val = (int) ((bada.charAt(i) - '0') * (mul - '0') + carry);
            now.insert(0, (char) (val % 10 + '0'));
            carry = val / 10;
        }
        while (carry > 0) {
            now.insert(0, (char) (carry % 10 + '0'));
            carry /= 10;
        }
        curr = curr.isEmpty() ? now.toString() : addition(curr, now.toString());
        solve(chota, bada, curr, index - 1, result);
    }
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        String chota = num1.length() < num2.length() ? num1 : num2;
        String bada = num1.length() < num2.length() ? num2 : num1;
        StringBuilder result = new StringBuilder();
        solve(chota, bada, "", chota.length() - 1, result);
        return result.toString();
    }
}
public class P43 {
    public static void main(String[] args) {
        Solution43 obj=new Solution43();
        String num1="1235723495720349570345";
        String num2="45634905723489057234589";
        System.out.println(obj.multiply(num1, num2));
    }
}
