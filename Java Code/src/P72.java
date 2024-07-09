class Solution {
    private void print(int[][]mat){
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[i].length;j++){
                System.out.print(mat[i][j]+"  ");
            }
            System.out.println();
        }
    }
    public int minDistance(String word1, String word2) {
        int len1=word1.length()+1;
        int len2=word2.length()+1;
        int [][] matrix=new int[len1][len2];
        for(int i=0;i<len2;i++) matrix[0][i]=i;
        for(int i=1;i<len1;i++) matrix[i][0]=i;
        for(int i=1;i<len1;i++){
            for(int j=1;j<len2;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    matrix[i][j]= matrix[i-1][j-1];
                }
                else{
                    int x=matrix[i-1][j];
                    int y=matrix[i][j-1];
                    int z=matrix[i-1][j-1];
                    matrix[i][j]=Math.min(x+1, Math.min(y+1, z+1));
                }
            }
        }
        print(matrix);
        return matrix[len1-1][len2-1];
    }
}
public class P72 {
    public static void main(String[] args) {
        Solution obj=new Solution();
        String word1="horse";
        String word2="ros";
        System.out.println("\n"+obj.minDistance(word1, word2));
    }
}
