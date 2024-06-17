#include<bits/stdc++.h>
using namespace std;
class Solution {
    void solve(vector<double> & temp,int k,double sum){
        sort(temp.begin(), temp.end());
        int count = 1;
        for(double x: temp){
            if(x==DBL_MAX) {
                temp.push_back(DBL_MAX);
                return;
            }
            count++;
            sum+=x;
            if(count==k) break;
        }
        temp.push_back(sum);
    }
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        if(k==1) return *min_element(wage.begin(),wage.end());
        double result=DBL_MAX;
        for(int i=0;i<quality.size();i++){
            vector<double> temp;
            double base_w=wage[i];
            double base_q=quality[i];
            for(int j=0;j<quality.size();j++){
                if(i==j)    continue;
                double x=quality[j];
                double expected=base_w * (x/base_q);
                if(expected>=wage[j]) temp.push_back(expected);
            }
            if(temp.size()>=k-1){
                solve(temp,k,base_w);
                result=min(result,temp.at(temp.size()-1));
            }
            i++;
        }
        if(result==DBL_MAX) return -1;
        return result;
    }
};
int main(){
    //quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
    vector<int> quality={32,43,66,9,94,57,25,44,99,19};
    vector<int> wage={187,366,117,363,121,494,348,382,385,262};
    int k=4;
    Solution obj;
    cout<<endl<<obj.mincostToHireWorkers(quality,wage,k);
}