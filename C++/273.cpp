#include<bits/stdc++.h>
using namespace std;
class Solution {
    private :
    string zero = "000";
    void fillNumber(vector<string> &number,int num){
        int n = 3;
        while(num > 0){
            int index = 2;
            while(num > 0 && index >= 0){
                number.at(n).at(index) = char((num%10) + '0');
                num /= 10;
                index--;
            }
            n--;
        }
    }
    void getHundred(vector<string> lessThan20,vector<string> tens,string &number,string &result){
        string temp = "";
        if(number.at(0) != '0'){
            temp += lessThan20[number.at(0) - '0'] + " Hundred";
        }
        if(number.at(1) != '0'){
            if(temp != "") temp += " ";
            if(number.at(1) == '1'){
                temp += lessThan20[10 + (number.at(2) - '0')];
                if(result != "") result += " ";
                result += temp;
                return;
            }
            else
            temp += tens[number.at(1) - '0'];
        }
        if(number.at(2) != '0'){
            if(temp != "") temp += " ";
            temp += lessThan20[number.at(2) - '0'];
        }
        if(result != "") result += " ";
        result += temp;
    }
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> lessThan20 = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> tens = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        vector<string> number (4,zero);
        fillNumber(number,num);
        string result = "";
        if(number[0] != zero){
            result += lessThan20[number[0][2] - '0'];
            result += " Billion";
        }
        if(number[1] != zero){
            getHundred(lessThan20,tens,number[1],result);
            if(result != "") result += " Million";
        }
        if(number[2] != zero){
            getHundred(lessThan20,tens,number[2],result);
            if(result != "") result += " Thousand";
        }
        if(number[3] != zero){
            getHundred(lessThan20,tens,number[3],result);
        }
        return result;
    }
};
//2,147,483,647
int main(){
    int num = 1010;
    Solution obj;
    string result = obj.numberToWords(num);
    cout<<result<<endl;
    for(char c : result){
        if(c == ' ') cout<<"-";
        else cout<<c;
    }
}