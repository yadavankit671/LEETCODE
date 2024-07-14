#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        string result = ""; // Final result string
        int key = 0; // Unique key for each atom
        unordered_map<int, pair<string, int>> atoms; // Map to store atom counts: key -> (name, count)
        stack<int> st; // Stack to track nested parentheses levels
        int index = 0; // Current index in the formula string
        while (index < formula.length()) {
            char currentChar = formula[index++]; // Get the current character and increment the index
            // Opening parenthesis: Push the current key to mark the start of a nested formula
            if (currentChar == '(') {
                st.push(key);
            } 
            // Uppercase letter: Start of a new atom
            else if (isupper(currentChar)) {
                string atomName = ""; // Build the atom name
                atomName += currentChar;
                // Append lowercase letters if any
                while (index < formula.length() && islower(formula[index])) {
                    atomName += formula[index++];
                }
                int atomCount = 0; // Extract the atom count (default to 1)
                while (index < formula.length() && isdigit(formula[index])) {
                    atomCount = atomCount * 10 + (formula[index++] - '0');
                }
                // Insert atom with name and count into the map
                atoms.insert({key++, {atomName, atomCount == 0 ? 1 : atomCount}});
            } 
            // Closing parenthesis: End of a nested formula
            else if (currentChar == ')') {
                int multiplier = 0; // Extract the multiplier for the nested formula
                while (index < formula.length() && isdigit(formula[index])) {
                    multiplier = multiplier * 10 + (formula[index++] - '0');
                }
                // Multiply atom counts within the nested formula by the multiplier
                int startKey = st.top(); st.pop();
                if (multiplier > 0) {
                    for (int i = startKey; i < key; ++i) {
                        atoms[i].second *= multiplier;
                    }
                }
            }
        }
        // Sort atoms by name and build the result string
        map<string, int> sortedAtoms; // Sorted map for output
        for (auto& entry : atoms) {  // Combine atom counts with the same name
            sortedAtoms[entry.second.first] += entry.second.second;
        }
        // Create the final result string with atom names and counts
        for (const auto& itr : sortedAtoms) {
            result += itr.first;
            if (itr.second > 1) {
                result += to_string(itr.second);
            }
        }
        return result;
    }
};
int main(){
    Solution obj;
    //string formula="((((H2SO4)50(NaCl)30)10(Cu(NO3)2)40)20(Mg(OH)2)60)5";
    string formula ="K4(ON(SO3)2)2";
    cout<<obj.countOfAtoms(formula);
}