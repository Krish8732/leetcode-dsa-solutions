// LeetCode: https://leetcode.com/problems/weighted-word-mapping/
// Concepts: Strings, Simulation

// Approach 1 (Reverse Alphabet Vector): Precompute reverse alphabetical mapping in a vector, compute word weight sum modulo 26, and map to character using the vector.
// TC: O(L) | SC: O(1)

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string final = "";
        vector<char> reverseOrder;
        for (int i = 25; i >= 0; i--){
            char c = 'a' + i;
            reverseOrder.push_back(c);
        }
        
        for (string& word : words) {
            int weight = 0;
            for (char& c : word){
                weight += weights[c - 'a'];
            }
            weight = weight % 26;
            final += reverseOrder[weight];
        }

        return final;
    }
};

// Approach 2 (ASCII Math): Compute word weight sum modulo 26, and map to character in reverse alphabetical order using ASCII subtraction (122 - sum, where 122 is 'z').
// TC: O(L) | SC: O(1)

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for (string& s : words) {
            int sum = 0;
            for (char& c : s) {
                sum += weights[c - 'a'];
            }
            sum = sum % 26;
            result += 122 - sum;
        }

        return result;
    }
};
