// Leetcode: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
//Concepts: Math, Digit Manipulation

//Approach: extract each digit by taking modulo 10, compute product and sum of all digits, return product - sum.

//T.C: O(log n) where n is the input number (number of digits)
//S.C: O(1)

class Solution {
public:
    int subtractProductAndSum(int n) {
        int pr=1,s=0;
        while(n>0){
            int a=n%10;
            pr*=a;
            s+=a;
            n/=10;
        }
        return pr-s;
    }
};
