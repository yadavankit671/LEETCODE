#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int leastInterval(vector<char>& tasks, int n) {
        int result=0;
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks.at(i)-'A']++;
        }
        sort(freq.begin(),freq.end());
        int maxf=freq.at(25)-1;
        int maxspot=maxf*n;
        for(int i=freq.size()-2;i>=0 && freq.at(i)>0;i--){
            maxspot-=min<int>(maxf,freq.at(i));
        }
        return (maxspot>0)?maxspot+tasks.size(): tasks.size();
    }
};
int main(){
    vector<char> tasks={'A','A','A','B','B','B'};
    int n=3;
    Solution obj;
    cout<<obj.leastInterval(tasks,n);
}