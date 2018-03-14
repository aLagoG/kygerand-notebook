/*
reference:
http://www.techiedelight.com/longest-increasing-subsequence/
https://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
*/
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

// returns the length of the LIS
int setLISLength(vector<int> &v) {
    int n = v.size();
    set<int> s;
    for (int i = 0; i < n; i++) {
        auto res = s.insert(v[i]);  // O(log(n))
        if (res.second) {
            auto it = res.first;
            if (++it != s.end()) {
                s.erase(it);  // O(1)
            }
        }
    }
    return s.size();
}

int bsLISLength(vector<int> &v) {
    int n = v.size();
    if (!n) {
        return 0;
    }
    vector<int> tail(n);
    tail[0] = v[0];
    int length = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] < tail[0]) {
            tail[0] = v[i];
        } else if (v[i] > tail[length - 1]) {
            tail[length++] = v[i];
        } else {
            auto it = lower_bound(tail.begin(), tail.begin() + length, v[i]);
            *it = v[i];
        }
    }
    return length;
}

vector<int> LIS(vector<int> &v) {
    int n = v.size();
    if (!n) {
        vector<int> empty{};
        return empty;
    }
    vector<int> value(n);
    vector<int> index(n);
    vector<int> parent(n);

    value[0] = v[0];
    index[0] = 0;
    int length = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] < value[0]) {
            value[0] = v[i];
            index[0] = i;
        } else if (v[i] > value[length - 1]) {
            parent[i] = index[length - 1];
            value[length] = v[i];
            index[length++] = i;
        } else {
            auto it = lower_bound(value.begin(), value.begin() + length, v[i]);
            int idx = it - value.begin();
            parent[i] = index[idx - 1];
            index[idx] = i;
            value[idx] = v[i];
        }
    }

    vector<int> lis(length);
    int last = index[length - 1];
    lis[length - 1] = v[last];
    while (--length) {
        last = parent[last];
        lis[length - 1] = v[last];
    }

    return lis;
}