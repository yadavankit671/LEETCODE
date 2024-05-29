#include<bits/stdc++.h>
using namespace std;




struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        ios_base::sync_with_stdio(false);
        unordered_map<vector<int>, int, VectorHash> memo;
        vector<int> letterFreq(26, 0);
        for (char c : letters) letterFreq[c - 'a']++;

        vector<pair<string, int>> wordsWithScores;
        for (string& word : words) {
            wordsWithScores.push_back({word, calculateScore(word, score)});
        }

        sort(wordsWithScores.begin(), wordsWithScores.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; });

        return backtrack(wordsWithScores, letterFreq, 0, memo);
    }

private:
    int backtrack(const vector<pair<string, int>>& words, vector<int> freq, int startIdx, 
                  unordered_map<vector<int>, int, VectorHash>& memo) {

        if (memo.count(freq)) {
            return memo[freq];
        }

        int maxScore = 0;
        for (int i = startIdx; i < words.size(); ++i) {
            auto [word, wordScore] = words[i];
            if (canFormWord(word, freq)) {
                updateFrequency(freq, word, -1);
                maxScore = max(maxScore, wordScore + backtrack(words, freq, i + 1, memo));
                updateFrequency(freq, word, 1);  
            }
        }

        memo[freq] = maxScore;
        return maxScore;
    }

    int calculateScore(const string& word, const vector<int>& score) {
        int totalScore = 0;
        for (char c : word) {
            totalScore += score[c - 'a'];
        }
        return totalScore;
    }

    bool canFormWord(const string& word, const vector<int>& freq) {
    vector<int> tempFreq = freq;
        for (char c : word) {
            if (--tempFreq[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }


    void updateFrequency(vector<int>& freq, const string& word, int change) {
        for (char c : word) {
            freq[c - 'a'] += change;
        }
    }
};



int main(){
    vector<string> words={"dog","cat","dad","good"};
    vector<char> letters={'a','a','c','d','d','d','g','o','o'};
    vector<int> score={1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    Solution obj;
    cout<<"\nResult : "<<obj.maxScoreWords(words,letters,score)<<endl;
    
}