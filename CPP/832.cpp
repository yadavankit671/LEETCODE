#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> image){
    if(image.empty()){
        cout<<"Empty !!"<<endl;
        return;
    }
    cout<<"Image : \n";
    for(auto x: image){
        for(auto y:x) cout<<" "<<y;
        cout<<endl;
    }
}
class Solution {
    public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int> >& image) {
        for(int i=0; i<image.size();i++){
            reverse(image.at(i).begin(), image.at(i).end());
            for(auto &x: image.at(i)) {
                x=(x)?0:1;
            }
        }
        return image;
    }
};

int main(){
    vector<vector<int>> image={{1,1,0},{1,0,1},{0,0,0}};
    cout<<"Initial ";
    print(image);
    cout<<"Resultant ";
    Solution obj;
    print(obj.flipAndInvertImage(image));
}