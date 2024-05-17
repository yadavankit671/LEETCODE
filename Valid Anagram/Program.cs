using System.Text;

public class Solution {
    public bool IsAnagram(string s, string t) {
        if(s.Length!=t.Length) return false;
        List<Tuple<int,int>> buffer=new(256);
        for(int i=0;i<256;i++) buffer.Add(Tuple.Create(0,0));
        for(int i=0;i<s.Length;i++){
            buffer[s[i]]=Tuple.Create(buffer[s[i]].Item1+1,buffer[s[i]].Item2);
            buffer[t[i]]=Tuple.Create(buffer[t[i]].Item1,buffer[t[i]].Item2+1);
        }
        for(int i=0;i<256;i++) if(buffer[i].Item1!=buffer[i].Item2) return false;
        return true;
    }
}
class Program{
    public static void Main(string[] args)
    {
        Solution s=new();
        if (s.IsAnagram("Hello","lHelo")) Console.WriteLine("Valid");
        else Console.WriteLine("Invalid");
    }
}
