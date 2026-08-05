// LeetCode: https://leetcode.com/problems/count-largest-group/
// Concepts: Math, Hash Map

// Approach 1 (Hash Map):
// Intuition:
// For each integer from 1 to n, we compute its digit sum. We store the frequency of each digit sum in an unordered map. After populating the map, we find the maximum frequency (size of the largest group) and then count how many groups have this maximum frequency.
// TC: O(n * log10(n)) | SC: O(log10(n))

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> sumMap;
        for (int i = 1; i <= n; i++) {
            int num = i;
            int digitSum = 0;
            while (num > 0) {
                int x = num % 10;
                digitSum += x;
                num = num / 10;
            }
            sumMap[digitSum]++;
        }
        int maxSize = 0;
        for (const auto& entry : sumMap) {
            maxSize = max(maxSize, entry.second);
        }
        int cnt = 0;
        for (const auto& entry : sumMap) {
            if (entry.second == maxSize)
                cnt++;
        }
        return cnt;
    }
};

// Approach 2 (Optimal Constant-Size Frequency Array):
// Intuition:
// Since n <= 10000, the maximum possible digit sum is for 9999, which is 9 * 4 = 36. Thus, the digit sums only range from 1 to 36. We can replace the hash map with a fixed-size array of size 37.
// While populating, we can dynamically keep track of the maximum frequency (maxF) and the number of groups with this frequency (totalSize). If a group's frequency reaches maxF, we increment totalSize. If it exceeds maxF, we update maxF and reset totalSize to 1.
// TC: O(n * log10(n)) | SC: O(1)

class Solution {
public:
    int countLargestGroup(int n) {
        int arr[37] = {0};
        int maxF = 0, totalSize = 0;
        for (int i = 1; i <= n; i++) {
            int digitSum = 0;
            for (int x = i; x > 0; x /= 10) {
                digitSum += x % 10;
            }
            int f = ++arr[digitSum];
            if (f == maxF)
                totalSize++;
            else if (f > maxF)
                maxF = f, totalSize = 1;
        }

        return totalSize;
    }
};
