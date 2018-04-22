#include <algorithm>
#include <vector>

using namespace std;

struct suffix {
    int index, rank1, rank2;
    bool operator<(const suffix& b) {
        return rank1 == b.rank1 ? rank2 < b.rank2 : rank1 < b.rank1;
    }
};

vector<int> buildSuffixArray(vector<int>& v) {
    int n = v.size();
    vector<suffix> suffixes(n);
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank1 = v[i];
        suffixes[i].rank2 = (i + 1 < n) ? v[i + 1] : -1;
    }

    sort(suffixes.begin(), suffixes.end());

    vector<int> idx(n);

    for (int k = 4; k < (n << 1); k <<= 1) {
        int rank = 0;
        int prev_rank = suffixes[0].rank1;
        suffixes[0].rank1 = rank;
        idx[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank1 == prev_rank &&
                suffixes[i].rank2 == suffixes[i - 1].rank2) {
                prev_rank = suffixes[i].rank1;
                suffixes[i].rank1 = rank;
            } else {
                prev_rank = suffixes[i].rank1;
                suffixes[i].rank1 = ++rank;
            }
            idx[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++) {
            int nIdx = suffixes[i].index + (k >> 1);
            suffixes[i].rank2 = (nIdx < n) ? suffixes[idx[nIdx]].rank1 : -1;
        }

        sort(suffixes.begin(), suffixes.end());
    }

    vector<int> suffixArray(n);
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].index;
    }

    return suffixArray;
}