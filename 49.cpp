#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: res = [["bat"],["nat","tan"],["ate","eat","tea"]]
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<bool> flag(len);
        for(int i=0; i<len; i++) flag[i] = false;
        vector<vector<string>> result;
        for(int i=0;i<len;i++){
            if(flag[i]==false){
                vector<string> temp;
                temp.push_back(strs[i]);
                flag[i] = true;
                for(int j=i+1;j<len;j++){
                    if((strs[i].length()==strs[j].length()) && isAnagram(strs[i],strs[j])){
                        flag[j]=true;
                        temp.push_back(strs[j]);
                    }
                }
                result.push_back(temp);
            }
        }
        return result;
    }
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<pair<int,int>> buffer(26,make_pair(0,0));
        for(int i=0;i<s.size();i++){
            buffer[s[i]-'a'].first++;
            buffer[t[i]-'a'].second++;
        }
        for(int i=0;i<buffer.size();i++) if(buffer[i].first!=buffer[i].second) return false;
        return true;
    }
    
};
void print(vector<vector<string>> result){
        if(result.size()==0) return;
        system("Color 07");
        cout<<"Size of the List : "<<result.size()<<endl;
        cout<<"List :{";
        for(auto itr=result.begin();itr!=result.end();itr++){
            cout<<"    [";
            for(auto it=itr->begin();it!=itr->end();it++){
                cout<<*it<<" ";
            }
            cout<<"]    ";
        }
        cout<<"}"<<endl;
    }

int main(){
    vector<string> strs= {"eat","tea","tan","ate","nat","bat"};
    Solution s;
    vector<vector<string>> res=s.groupAnagrams(strs);
    print(res);
}



    // vector<string> func(vector<string>& strs,string s){
    //     vector<string> res;
    //     res.push_back(s);
    //     for(int i=0;i<strs.size();i++){
    //         if(isAnagram(strs[i],s)){
    //             res.push_back(strs[i]);
    //         }
    //     }
    // }

// bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false;
//         vector<pair<int,int>> buffer(256,make_pair(0,0));
//         for(int i=0;i<s.size();i++){
//             buffer[s[i]].first++;
//             buffer[t[i]].second++;
//         }
//         for(int i=0;i<buffer.size();i++) if(buffer[i].first!=buffer[i].second) return false;
//         return true;
//     }