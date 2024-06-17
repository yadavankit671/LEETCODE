#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    map<string,string> urlDatabase;
    string getrandomString(){
        string str="";
        srand(time(0));
        for(int i=0;i<2;i++){
            str+=char(rand()%10+'0');
            str+=char(rand()%26+'a');
            str+=char(rand()%26+'A');
        }
        return str;
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        //http://tinyurl.com/4e9iAk
        string shortUrl="http://tinyurl.com/";
        shortUrl.append(getrandomString());
        if(urlDatabase.find(shortUrl)==urlDatabase.end())
        urlDatabase[shortUrl]=longUrl;
        else encode(longUrl);
        return shortUrl;
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlDatabase[shortUrl];
    }
};
int main(){
    string longUrl="https://leetcode.com/problems/design-tinyurl";
    Solution obj;
    string shortUrl=obj.encode(longUrl);
    cout<<shortUrl<<endl;
    cout<<obj.decode(shortUrl);
}