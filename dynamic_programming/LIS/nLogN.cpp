/*
reference:
http://www.techiedelight.com/longest-increasing-subsequence/
https://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
*/
#include <set>
#include <vector>

using namespace std;

// returns the length of the LIS
template <class T>
int LISLength(vector<T> &v) {
    int n = v.size();
    set<T> s;
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
