
public class P980 {
    private static int result;
    private static void BackTracking(int[][] grid,int x,int y,int curr,int totalSum){
        if( x<0 || y<0 || x>=grid.length || y>=grid[0].length || grid[x][y]==-1) return;
        if(grid[x][y]==2){
            if(curr==totalSum+1)  result++;
            return;
        }
        grid[x][y]=-1;
        curr++;
        BackTracking(grid, x-1, y, curr, totalSum);
        BackTracking(grid, x+1, y, curr, totalSum);
        BackTracking(grid, x, y-1, curr, totalSum);
        BackTracking(grid, x, y+1, curr, totalSum);
        grid[x][y]=0;
    }
    public static int uniquePathsIII(int[][] grid) {
        int totalSum=0,x=-1,y=-1;
        result=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==0) totalSum++;
                else if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        BackTracking(grid,x,y,0,totalSum);
        return result;
    }
    public static void main(String[] args) {
        int[][] grid={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
        System.out.println(uniquePathsIII(grid));
    }
}
