// LeetCode: https://leetcode.com/problems/weighted-word-mapping/
// Concepts: Strings, Simulation

/*
Intuition:
For each word in `words`, compute the sum of weights of its characters based on the given `weights` array.
Take `sum % 26` to determine the offset from the end of the alphabet (reverse alphabetical order: 0 -> 'z', 1 -> 'y', ..., 25 -> 'a').

- Approach 1 uses a precomputed reverse alphabetical order array/vector.
- Approach 2 uses direct ASCII arithmetic (`'z' - sum` or `122 - sum`).

T.C: O(N * L) where N is number of words and L is average length of words.
S.C: O(1) auxiliary space (excluding result string).
*/

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

// Approach 2 (ASCII Math): Compute word weight sum modulo 26, and map to character in reverse alphabetical order using ASCII subtraction ('z' - sum).
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
            result += 'z' - sum;
        }

        return result;
    }
};
