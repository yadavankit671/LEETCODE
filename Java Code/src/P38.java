
public class P38 {
    private StringBuilder helper(StringBuilder str){
        StringBuilder ret= new StringBuilder();
        int [] last = {-1,0};
        for(int i=0;i<str.length();i++){
            if(last[0]!=str.charAt(i)-'0'){
                if(last[1]>0){
                    ret.append(last[1]);
                    ret.append(last[0]);
                }
                last[0]=str.charAt(i)-'0';
                last[1]=1;
            }
            else last[1]++;
        }
        ret.append(last[1]);
        ret.append(last[0]);
        return ret;
    }
    public String countAndSay(int n) {
        StringBuilder res=new StringBuilder();
        res.append("1");
        for(int i=1;i<n;i++){
            res=helper(res);
        }
        return res.toString();
    }
    public static void main(String[] args) {
        P38 obj = new P38();
        System.out.println(obj.countAndSay(4)); // "1211"
    }
}
