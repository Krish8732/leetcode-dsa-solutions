// Leetcode: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
//Concepts: Trie, Bit Manipulation, Offline Queries

//Approach: use Trie to store binary representation of numbers. Process queries offline by sorting them by their limit m parameter. Insert numbers in sorted order (only insert nums <= m for each query). For each query, traverse Trie greedily trying to pick opposite bit at each level to maximize XOR. If opposite bit doesn't exist, take same bit. Return -1 if Trie is empty. used lamda for custom sorting, a flag for trie created as there can be situation where no number is inserted in trie yet.

//T.C: O((n+q) * logn) for sorting + O((n+q) * 30) for Trie traversal where n = size of nums, q = number of queries, 30 = number of bits
//S.C: O(n * 30) for Trie nodes

struct trieNode {
    trieNode* left = NULL;
    trieNode* right = NULL;
};

trieNode* getNode() {
    trieNode* temp = new trieNode();
    return temp;
}

void insert(trieNode* root, int val) {
    trieNode* bot = root;
    for (int i = 30; i >= 0; i--) {
        int bit = (val >> i) & 1;
        if (bit == 1) {
            if (!bot->right)
                bot->right = getNode();
            bot = bot->right;
        } else {
            if (!bot->left)
                bot->left = getNode();
            bot = bot->left;
        }
    }
}

int find(trieNode* root, int qry) {
    trieNode* bot = root;
    int maxVal = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = (qry >> i) & 1;
        if (bit == 0) {
            if (bot->right) {
                bot = bot->right;
                maxVal += pow(2, i);
            } else {
                if (!bot->left)
                    break;
                bot = bot->left;
            }
        } else {
            if (bot->left) {
                bot = bot->left;
                maxVal += pow(2, i);
            } else {
                if (!bot->right)
                    break;
                bot = bot->right;
            }
        }
    }
    return maxVal;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
        vector<int> result(n, -1);

        auto comp = [](const vector<int>& vec1, const vector<int>& vec2) {
            return vec1[1] < vec2[1];
        };

        sort(begin(nums), end(nums));
        for (int i = 0; i < n; i++) {
            queries[i].push_back(i);
        }

        sort(begin(queries), end(queries), comp);

        int i = 0, j = 0;

        trieNode* root = getNode();
        bool trieMade = false;

        while (j < n) {
            int val = queries[j][0];
            int m_ = queries[j][1];
            int num = i < m ? nums[i] : INT_MAX;
            int idx = queries[j][2];

            int ans = -1;

            if (num <= m_) {
                insert(root, num);
                trieMade = true;
                i++;
                continue;
            }

            ans = (trieMade) ? find(root, val) : ans;
            result[idx] = ans;
            j++;
        }

        return result;
    }
};
