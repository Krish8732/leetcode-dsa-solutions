// Leetcode: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//Concepts: Trie, Bit Manipulation

//Approach: build Trie storing binary representation of all numbers. For each number, traverse Trie greedily trying to pick opposite bit at each level to maximize XOR. If opposite bit doesn't exist, take same bit. Keep track of maximum XOR found across all numbers.

//T.C: O(n * 32) 
//S.C: O(n * 32) for Trie nodes

class Solution {
public:
    struct trieNode {
        trieNode* left = NULL;
        trieNode* right = NULL;
    };

    void insert(trieNode* root, int num) {
        trieNode* pCrawl = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (pCrawl->left == NULL)
                    pCrawl->left = new trieNode();
                pCrawl = pCrawl->left;
            } else {
                if (pCrawl->right == NULL)
                    pCrawl->right = new trieNode();
                pCrawl = pCrawl->right;
            }
        }
    }

    int findMaxXor(trieNode* root, int num) {
        int maxXor = 0;

        trieNode* pCrawl = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 1) {
                if (pCrawl->left) {
                    maxXor += pow(2, i);
                    pCrawl = pCrawl->left;
                } else {
                    pCrawl = pCrawl->right;
                }
            }

            else {
                if (pCrawl->right) {
                    maxXor += pow(2, i);
                    pCrawl = pCrawl->right;
                } else {
                    pCrawl = pCrawl->left;
                }
            }
        }

        return maxXor;
    }

    int findMaximumXOR(vector<int>& nums) {
        int result = 0;

        trieNode* root = new trieNode();

        for (int& num : nums) {
            insert(root, num);
        }

        for (int& num : nums) {
            int currXor = findMaxXor(root, num);
            result = max(result, currXor);
        }

        return result;
    }
};
