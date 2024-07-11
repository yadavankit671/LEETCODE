#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        for (string log : logs){
            if (log == "../")
                result -= (result > 0) ? 1 : 0;
            else if (log == "./")
                continue;
            else
                result++;
        }
        return result > 0 ? result : 0;
    }
};
int main()
{
}