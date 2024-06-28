#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    long maximumImportance(vector<vector<int> > &roads,int n){
        long result=0;
        /* BRUTEFORCE 
        vector<vector<int> > buffer(n); // Adjacency List
        for(auto &road :roads ){
            int u=road[0];
            int v=road[1];
            buffer[u].push_back(v);
            buffer[v].push_back(u);
        }
        vector<pair<int,int> > b; // {key->index,number of cities connected}
        for(int i=0;i<n;i++){
            b.push_back({i,buffer[i].size()});
        }
        sort(b.begin(),b.end(),[](pair<int,int> a,pair<int,int> b){  // sorting the list based on the no. of cities connected : 
            return a.second>b.second;
        });
        for(int i=0;i<n;i++){
            int key=b[i].first;
            buffer[key].push_back(n-i); // asserting a priority value 
        }
        for(auto & road : roads){
            int u=road[0];
            int v=road[1];
            result+=buffer[u].back()+buffer[v].back();  // adding that priority value
        }
        */

        /*
        USING MAP : 
        int result=0;
        unordered_map <int,vector<int> > buff;
        for(auto road : roads){
            int u=road[0];
            int v=road[1];
            buff[u].push_back(v);
            buff[v].push_back(u);
        }
        vector<pair<int,int>> b;
        for(pair<int,vector<int> > p : buff){
            b.push_back({p.first,p.second.size()});
        }
        cout<<b.size()<<endl;
        sort(b.begin(),b.end(),[](pair<int,int>&a ,pair<int,int>&b){
            return a.second>b.second;
        });
        for(int i=0;i<b.size();i++){
            int key=b[i].first;
            buff[key].push_back(n-i);
        }
        for(pair<int,vector<int> > x : buff){
            cout<<x.first<<"\t";
            for(int y : x.second){
                cout<<y<<",";
            }
            cout<<"\n";
        }
        for(auto road : roads){
            int u=road[0];
            int v=road[1];
            result+=buff[u].at(buff.at(u).size()-1)+buff[v].at(buff.at(v).size()-1);
        }
        return result;
        */

        // Optimal Solution : 
        vector<int> buffer(n);
        for(vector<int> &road : roads){
            int u=road[0];
            int v=road[1];
            buffer[u]++;
            buffer[v]++;
        }
        sort(buffer.begin(), buffer.end(),greater<int>());
        for(int i=0;i<n && buffer[i]!=0;i++){
            result+=buffer[i]*(n-i); // multiplying the priority value with the remaining cities
        }
        return result;
    }
};
int main(){
    vector<vector<int> > roads={{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};//
    int n=5;
    Solution obj;
    cout<<obj.maximumImportance(roads,n);
}