class SubrectangleQueries {
    private int[][] rect;
    public SubrectangleQueries(int[][] rectangle) {
        this.rect=rectangle;
    }
    public void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                rect[i][j]=newValue;
            }
        }
    }
    
    public int getValue(int row, int col) {
        return rect[row][col];
    }
}

public class P1476 {
}
