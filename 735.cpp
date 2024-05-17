#include<bits/stdc++.h>
using namespace std;
void print(vector<int> result){
    if(result.empty()){
        cout<<"Empty result"<<endl;
        return;
    }
    cout<<"Result : "<<result.at(0);
    for(int i=1;i<result.size();i++){
        cout<<","<<result.at(i);
    }
    cout<<endl;
}
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        int size=asteroids.size();
        for(int i=0;i<size;i++){
            if(stk.empty()) stk.push_back(asteroids.at(i));
            else if(asteroids.at(i)<0){
                int temp=-1*(asteroids.at(i));
                if(stk.at(stk.size()-1)==temp){
                    stk.pop_back();
                }
                else if(stk.at(stk.size()-1)<temp){
                    while(stk.empty()!=true && stk.at(stk.size()-1)<temp && stk.at(stk.size()-1)>0) {
                        stk.pop_back();
                    }
                    if(!stk.empty() && stk.at(stk.size()-1)==temp) stk.pop_back();
                    else if(stk.empty() || stk.at(stk.size()-1)<0) stk.push_back(asteroids.at(i));
                }
                else if(stk.at(stk.size()-1)<0) stk.push_back(asteroids.at(i));
            }
            else stk.push_back(asteroids.at(i));
        }
        return stk;
    }
}; //[-50,-23,48,34,3,25,20,27]
int main(){
    vector<int> asteroids={46, -36, 3, 39, 20, 10, -33, 35, 4, -26, -37, 27, -50, -23, 48, 5, -1, 29, -34, 34, 11, 22, 8, 41, -20, -10, 17, 35, -14, -9, 3, 12, -13, -47, 23, -39, 25, -43, -2, 26, -26, -42, -5, -4, 34, 3, 25, 20, 27, -6};
    Solution obj;
    vector<int> result=obj.asteroidCollision(asteroids);
    print(result);
}