#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(students.begin(), students.end());
        sort(seats.begin(), seats.end());
        int result = 0;
        for(int i=0;i<students.size();i++){
            result+=abs(students[i]-seats[i]);
        }
        return result;
    }
};
int main(){

}