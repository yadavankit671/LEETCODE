#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ios::sync_with_stdio(false);
        sort(people.begin(),people.end());
        int result=0;
        int j=people.size()-1;
        int i=0;
        while(i<=j){
            if( i!=j && people.at(j)+people.at(i)>limit) {
                result++;
                j--;
            }
            else if(i!=j && people.at(j)+people.at(i)<=limit){
                result++;
                i++;
                j--;
            }
            else if(i==j) {
                result++;
                break;
            }
        }
        return result;
    }
};
int main(){
    vector<int> people={1,2};
    int limit=3;
    Solution obj;
    cout<<obj.numRescueBoats(people,limit)<<endl;
}