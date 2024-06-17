/*
A word is considered valid if:
It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.
 */
class Solution3136 {
    private boolean isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    public boolean isValid(String word) {
        if(word.length()<3) return false;
        boolean hasVowel=false;
        boolean hasConsonant=false;
        //48-57 (0-9)  // 65-90 (A-Z) // 97-122 (a-z)
        for (int i=0;i<word.length();i++) {
            char c = word.charAt(i);
            if(c>=48 && c<=57) {
                continue;
            }
            else if(c>=65 && c<=97) {
                if(isVowel(Character.toLowerCase(c))) hasVowel=true;
                else hasConsonant=true;
                continue;
            }
            else if(c>=97 && c<=122) {
                if(isVowel(c)) hasVowel=true;
                else hasConsonant=true;
                continue;
            }
            else return false;
        }
        if(hasVowel && hasConsonant) return true;
        return false;
    }
}
public class P3136 {

}
