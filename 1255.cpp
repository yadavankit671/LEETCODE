#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool  CanWordForm(vector<int> &freq,string word){
        vector<int> temp=freq;
        for(int i=0;i<word.size();i++){
            if(temp[word[i]-'a'] <= 0) return false;
            temp[word[i]-'a']--;
        }
        freq=temp;
        return true;
    }
    int getScore(string word,vector<int> &score){
        int res = 0;
        for(int i=0;i<word.size();i++){
            res += score[word[i]-'a'];
        }
        return res;
    }
    void popBack(vector<int> &freq,string word){
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
    }
    int BackTrack(vector<string> &words,int index,vector<int> &freq,map<string,int> &scoreBuff,int currScore,int &result){
        if(index>=words.size()) return currScore;
        vector<int> tempFreq=freq;
        for(int i=index;i<words.size();i++){
            if(CanWordForm(tempFreq,words[i])){
                result=max(result,BackTrack(words,i+1,tempFreq,scoreBuff,currScore+scoreBuff[words[i]],result));
                //popBack
                popBack(tempFreq,words[i]);
            }
            result=max(currScore,result);
        }
        return result;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        ios_base::sync_with_stdio(false);
        map<string,int> scoreBuff;
        for(string word: words){
            scoreBuff[word] = getScore(word,score);
        }
        int result=0;
        vector<int> freq(26,0);
        for(char c : letters)   freq[c-'a']++;
        result=max(result,BackTrack(words,0,freq,scoreBuff,0,result));
        return result;
    }
};


int main(){
    vector<string> words={"azb","ax","awb","ayb","bpppp"};
    vector<char> letters={'z','a','w','x','y','b','p','p','p'};
    vector<int> score={10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,3,2,3,3};
    Solution obj;
    cout<<"\nResult : "<<obj.maxScoreWords(words,letters,score)<<endl;
    
}
