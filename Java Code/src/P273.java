import java.util.*;
class Solution {
    private String zero = "000";
    private void fillNumber(List<String> number, int num) {
        int n = 3;
        while (num > 0) {
            int index = 2;
            while (num > 0 && index >= 0) {
                char[] charArray = number.get(n).toCharArray();
                charArray[index] = (char) ((num % 10) + '0');
                number.set(n, new String(charArray));
                num /= 10;
                index--;
            }
            n--;
        }
    }
    private void getHundred(List<String> lessThan20, List<String> tens, String number, StringBuilder result) {
        String temp = "";
        if (number.charAt(0) != '0') {
            temp += lessThan20.get(number.charAt(0) - '0') + " Hundred";
        }
        if (number.charAt(1) != '0') {
            if (!temp.isEmpty()) temp += " ";
            if (number.charAt(1) == '1') {
                temp += lessThan20.get(10 + (number.charAt(2) - '0'));
                if (result.length() != 0) result.append(" ");
                result.append(temp);
                return;
            } else {
                temp += tens.get(number.charAt(1) - '0');
            }
        }
        if (number.charAt(2) != '0') {
            if (!temp.isEmpty()) temp += " ";
            temp += lessThan20.get(number.charAt(2) - '0');
        }
        if (result.length() != 0) result.append(" ");
        result.append(temp);
    }

    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        List<String> lessThan20 = Arrays.asList("", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen");
        List<String> tens = Arrays.asList("", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety");
        List<String> number = new ArrayList<>(Arrays.asList(zero, zero, zero, zero));
        fillNumber(number, num);
        StringBuilder result = new StringBuilder();
        if (!number.get(0).equals(zero)) {
            result.append(lessThan20.get(number.get(0).charAt(2) - '0'));
            result.append(" Billion");
        }
        if (!number.get(1).equals(zero)) {
            getHundred(lessThan20, tens, number.get(1), result);
            if (result.length() != 0) result.append(" Million");
        }
        if (!number.get(2).equals(zero)) {
            getHundred(lessThan20, tens, number.get(2), result);
            if (result.length() != 0) result.append(" Thousand");
        }
        if (!number.get(3).equals(zero)) {
            getHundred(lessThan20, tens, number.get(3), result);
        }
        return result.toString();
    }
}
public class P273 {

}
