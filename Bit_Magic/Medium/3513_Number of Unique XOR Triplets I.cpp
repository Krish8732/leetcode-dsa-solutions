// Leetcode: https://leetcode.com/problems/number-of-unique-xor-triplets-i/
// Concepts: Bit Manipulation, Math

/*
Intuition:
For n >= 3, XORing triplets from 1 to n generates all values from 0 up to 2^(k+1) - 1, 
where 2^k is the largest power of 2 less than or equal to n.

- Numbers below 2^k form values 0 to 2^k - 1.
- Including 2^k (or n) shifts the XOR range by 2^k, forming values 2^k to 2^(k+1) - 1.
- Together, they form 2^(k+1) total unique XOR values.

So the answer is the smallest power of 2 strictly greater than n (hence ans <= n in while loop).
*/

// T.C: O(log n)
// S.C: O(1)

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2 ) return n;

        int ans = 1; // 2^0
        while (ans <= n){
            ans *= 2;
        }

        return ans;
    }
};
