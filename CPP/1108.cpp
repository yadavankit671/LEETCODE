#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        //string result="";
        for(int i = 0; i <address.length(); i++) {
            if(address[i]=='.'){
                //result+="[.]";
                address.insert(i,"[");
                address.insert(i+2,"]");
                i+=2;
            }
        }
        return address;
    }
};
int main(){
    string adr="0.0.0.0";
    Solution obj;
    adr=obj.defangIPaddr(adr);
    cout<<adr<<endl;
}