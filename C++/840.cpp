#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &grid){
    if (grid.empty()) return;
    for (auto x : grid){
        for (auto y : x) cout << y << ",";
        cout << endl;
    }
}

class Solution {
    private:
    bool isMagicSquare(vector<vector<int>> &grid, int row, int col){
        vector<int> freq(10, 0);
        freq[0] = 1;
        for (int i = row; i < row + 3; i++){
            for (int j = col; j < col + 3; j++){
                int element = grid[i][j];
                if (element < 1 || element > 9 || freq[element] > 0){
                    return false;
                }
                freq[element]++;
            }
        }
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        for (int i = 0; i < 3; i++){
            int rowSum = 0;
            int colSum = 0;
            for (int j = 0; j < 3; j++){
                rowSum += grid[row + i][col + j];
                colSum += grid[row + j][col + i];
            }
            if (rowSum != sum || colSum != sum){
                return false;
            }
        }
        int diagonalSum1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagonalSum2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        return diagonalSum1 == sum && diagonalSum2 == sum;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.at(0).size();
        if(rows < 3 || cols < 3) return 0;
        int count = 0;
        for(int i = 0; i < rows -2; i++){
            for(int j = 0; j < cols - 2; j++){
                if(isMagicSquare(grid,i,j)) count++;
            }
        }
        return count;
    }
};
int main(){
    // [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
    vector<vector<int>> grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    print(grid);
    Solution obj;
    cout << obj.numMagicSquaresInside(grid);
}