// LeetCode: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Concepts: Math, Simulation

// Approach 1 (Simulation):
// Intuition:
// We simulate the daily deposit process using a loop. We keep track of the current day's deposit value and reset/increment appropriately every Monday.
// TC: O(n) | SC: O(1)

class Solution {
public:
    int totalMoney(int n) {
        int cnt = 0;
        int mondayCnt = 0;
        int money = 0;
        int uniCnt = 0;
        while (uniCnt < n) {
            if (uniCnt % 7 == 0) {
                mondayCnt++;
                cnt = mondayCnt;
                money += mondayCnt;
            } else {
                cnt++;
                money += cnt;
            }
            uniCnt++;
        }
        return money;
    }
};

// Approach 2 (Week-by-Week Summation):
// Intuition:
// Instead of simulating day-by-day, we can sum week-by-week. The first week sum is 28 (1+2+3+4+5+6+7). Each subsequent week's sum is 7 more than the previous week (28 + 7 * i). Finally, we add the remaining days of the last incomplete week.
// TC: O(n / 7) | SC: O(1)

class Solution {
public:
    int totalMoney(int n) {
        int remainingDays = n % 7;
        int totalWeeks = n / 7;
        int totalMoney = 0;
        int i = 0;

        for (i = 0; i < totalWeeks; i++){
            totalMoney += (28) + 7 * i;
        }

        if (remainingDays > 0){
            int j = 0;
            while (remainingDays > 0){
                totalMoney += (i + j + 1);
                j++;
                remainingDays--;
            }
        }

        return totalMoney;
    }
};

// Approach 3 (Optimal Math via Arithmetic Progression):
// Intuition:
// The sums of the complete weeks form an Arithmetic Progression (AP) with first term a = 28, common difference d = 7, and number of terms equal to weeks. The sum of this AP is: (weeks * (2 * 28 + (weeks - 1) * 7)) / 2. We can then add the remaining days' deposits in O(remainingDays) time.
// TC: O(1) | SC: O(1)

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int remainingDays = n % 7;
        int totalMoney = 0;

        totalMoney += (weeks * (56 + (weeks - 1) * 7)) / 2;

        for (int i = 0; i < remainingDays; i++) {
            totalMoney += weeks + 1 + i;
        }

        return totalMoney;
    }
};
