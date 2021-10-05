#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define REP(i, l, r) for(int i=l;i<r;i++)
#define RREP(i, r, l) for(int i=r;i>=l;i--)
const int maxn = 100006;
map<ll, int> cnt;
ll pre[maxn], suf[maxn], ans[maxn];

class Solution {
public:
    int count(ll val) {
        if (val % 2 == 0) {
            return 0;
        } else {
            return cnt[val / 2];
        }
    }

    void initAns(const vector<int> &nums, int k) {
        const int n = nums.size();
        REP(i, 1, n) {
            cnt[pre[i - 1]]++;
            ans[i] += count(pre[n - 1] - nums[i] + k);
        }
        ans[n] = count(pre[n - 1]);
        cnt.clear();
        RREP(i, n - 2, 0) {
            cnt[suf[i + 1]]++;
            ans[i] += count(pre[n - 1] - nums[i] + k);
        }
    }

    int waysToPartition(vector<int> &nums, int k) {
        const int n = nums.size();
        ll answer = 0;
        REP(i, 0, n) {
            pre[i] = nums[i] + (i > 0 ? pre[i - 1] : 0);
            suf[n - i - 1] = nums[n - i - 1] + (i > 0 ? suf[n - i] : 0);
        }
        initAns(nums, k);
        REP(i, 0, n + 1) {
            answer = max(answer, ans[i]);
        }
        return answer;
    }
};

#ifdef LOCAL

int main() {
    Solution so = Solution();
    vector<int> v1 = {22, 4, -25, -20, -15, 15, -16, 7, 19, -10, 0, -13, -14};
    cout << so.waysToPartition(v1, -33);
    return 0;
}

#endif