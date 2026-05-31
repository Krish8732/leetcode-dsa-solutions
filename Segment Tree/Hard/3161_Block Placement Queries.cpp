// Leetcode:https://leetcode.com/problems/block-placement-queries/
//Concepts: Segment Tree

//Approach: using segment Tree cause we have to update as well as query the values of a specific range, we use set to store the obstacles, for type 1 queries we add that obstacle to set , update segTree both sides if present , for type 2 we find max gap in that range, and also the right side gap choose max from the two. used segTree as usual temp for update and query .

//T.C: O(Q * logN) where Q = number of queries, N = max coordinate (50001)
//S.C: O(N) for the segment tree and ordered set

class Solution {
public:
    void updateSegTree(vector<int>& segmentTree, int idx, int val, int i, int l,
                       int r) {
        if (l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            updateSegTree(segmentTree, idx, val, 2 * i + 1, l, mid);
        } else {
            updateSegTree(segmentTree, idx, val, 2 * i + 2, mid + 1, r);
        }

        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    int querySegTree(vector<int>& segmentTree, int start, int end, int i, int l,
                     int r) {
        if (l > end || r < start)
            return 0; // out of range nodes

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        return max(
            querySegTree(segmentTree, start, end, 2 * i + 1, l, mid),
            querySegTree(segmentTree, start, end, 2 * i + 2, mid + 1, r));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        vector<int> segmentTree(4 * 50001, 0);
        int n = 50001;

        set<int> st;
        st.insert(0);

        vector<bool> result;

        for (auto& query : queries) {
            if (query[0] == 1) {
                int x = query[1];

                auto it = st.upper_bound(x);
                int next = (it != st.end()) ? *it : -1;
                int pre = *prev(it);

                updateSegTree(segmentTree, x, x - pre, 0, 0, n - 1);
                if (next != -1)
                    updateSegTree(segmentTree, next, next - x, 0, 0, n - 1);

                st.insert(x);
            }

            else {
                int x = query[1];
                int sz = query[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);

                int maxGap = querySegTree(segmentTree, 0, pre, 0, 0, n - 1);
                int best = max(maxGap, x - pre);

                result.push_back(best >= sz);
            }
        }

        return result;
    }
};