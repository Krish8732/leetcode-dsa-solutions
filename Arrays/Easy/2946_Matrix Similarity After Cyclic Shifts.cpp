// LeetCode: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
// Concepts: Array, Matrix, Simulation

/*
Intuition:
We are given an m x n matrix `mat` and an integer `k`.
- Even-indexed rows are shifted to the left by `k` steps.
- Odd-indexed rows are shifted to the right by `k` steps.
We need to determine if the matrix remains identical to the original matrix after the cyclic shifts.

Approach 1: Brute Force (Simulation using std::rotate)
Copy the matrix, perform `std::rotate` left for even rows and right for odd rows by `k % n` steps, then check if `temp == mat`.
T.C: O(M * N)
S.C: O(M * N) space for matrix copy.

Approach 2: Optimal (Direct Index Comparison using Modulo Arithmetic)
To ensure indices remain in bound during cyclic shifts, use `% n` for addition and `+ n % n` for subtraction modulo properties.
Since cyclic shifting by `k` means the element at position `j` must equal the element `k` positions away, we directly check `mat[i][j] == mat[i][newJ]`.
T.C: O(M * N)
S.C: O(1) auxiliary space.
*/

// Approach 1: Brute Force (Simulation)
class SolutionBruteForce {
public:
    void checkIdentical(vector<int>& row, int k, int i) {
        if (i % 2 == 1) {
            rotate(rbegin(row), rbegin(row) + k, rend(row));
        } else {
            rotate(begin(row), begin(row) + k, end(row));
        }
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> temp = mat;

        k = k % n;
        if (k == 0) return true;

        for (int i = 0; i < m; i++) {
            checkIdentical(mat[i], k, i);
        }

        return temp == mat;
    }
};

// Approach 2: Optimal (Direct Modulo Index Checking - O(1) Space)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k % n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    int newJ = (j + k) % n;
                    if (mat[i][j] != mat[i][newJ]) return false;
                } else {
                    int newJ = (j + k + n) % n;
                    if (mat[i][j] != mat[i][newJ]) return false;
                }
            }
        }

        return true;
    }
};
