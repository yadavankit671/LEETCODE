import java.util.*;
class Pair{
    String atom;
    int count;
    Pair(String atom, int count){
        this.atom=atom;
        this.count=count;
    }
}
class Solution {
    public String countOfAtoms(String formula) {
        StringBuilder result= new StringBuilder();
        int key = 0;
        Map<Integer,Pair >  atoms = new HashMap<>();
        Stack<Integer> st = new Stack<>();
        int index = 0;
        while(index < formula.length()){
            char currChar = formula.charAt(index++);
            if(currChar =='('){
                st.push(key);
            }
            else if(Character.isUpperCase(currChar)){
                StringBuilder atomName = new StringBuilder();
                atomName.append(currChar);
                while(index < formula.length() && Character.isLowerCase(formula.charAt(index))){
                    atomName.append(formula.charAt(index++));
                }
                int atomCount = 0;
                while(index < formula.length() && Character.isDigit(formula.charAt(index))){
                    atomCount = atomCount * 10 + (formula.charAt(index++)-'0');
                }
                atoms.put(key++,new Pair(atomName.toString(),atomCount == 0 ? 1 : atomCount));
            }
            else if(currChar == ')'){
                int multiplier = 0;
                while(index < formula.length() && Character.isDigit(formula.charAt(index))){
                    multiplier = multiplier * 10 + (formula.charAt(index++)-'0');
                }
                int StartKey = st.pop();
                if(multiplier > 0){
                    for(int i= StartKey ; i< key; i++){
                        atoms.get(i).count*= multiplier;
                    }
                }
            }
        }
        SortedMap<String,Integer> sortedAtoms = new TreeMap<>();
        for(Map.Entry<Integer,Pair> itr : atoms.entrySet()){
            sortedAtoms.put(itr.getValue().atom,sortedAtoms.getOrDefault(itr.getValue().atom, 0)+itr.getValue().count);
        }
        for(Map.Entry<String,Integer> itr : sortedAtoms.entrySet()){
            result.append(itr.getKey());
            if(itr.getValue()>1){
                result.append(itr.getValue());
            }
        }
        return result.toString();
    }
}
public class P726 {
    public static void main(String[] args) {
        String formula ="K4(ON(SO3)2)2";
        Solution obj = new Solution();
        System.out.println(obj.countOfAtoms(formula));
    }
}
