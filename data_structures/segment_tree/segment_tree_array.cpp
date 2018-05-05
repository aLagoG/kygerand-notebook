#include <cmath>
#include <vector>

#define left(x) (x << 1) + 1
#define right(x) (x << 1) + 2

using namespace std;

class ArraySegmentTree {
   private:
    vector<int> tree;
    vector<int> lazy;
    // values is only needed when using only point upates
    vector<int> values;

    int getMid(int start, int end) {
        return (start + end) >> 1;
    }

    int construct(int start, int end, int idx) {
        if (start == end) {
            tree[idx] = values[start];
            return values[start];
        }
        int mid = getMid(start, end);
        tree[idx] = construct(start, mid, left(idx)) +
                    construct(mid + 1, end, right(idx));
        return tree[idx];
    }

    int queryUtil(int ss, int se, int qs, int qe, int idx) {
        if (lazy[idx]) {
            tree[idx] += (se - ss + 1) * lazy[idx];
            if (ss != se) {
                lazy[left(idx)] += lazy[idx];
                lazy[right(idx)] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (qs <= ss && qe >= se) {
            return tree[idx];
        }
        if (se < qs || ss > qe) {
            return 0;
        }
        int mid = getMid(ss, se);
        return queryUtil(ss, mid, qs, qe, left(idx)) +
               queryUtil(mid + 1, se, qs, qe, right(idx));
    }

    void updateUtil(int start, int end, int ui, int diff, int idx) {
        if (ui < start || ui > end) {
            return;
        }
        tree[idx] = tree[idx] + diff;
        if (end != start) {
            int mid = getMid(start, end);
            updateUtil(start, mid, ui, diff, left(idx));
            updateUtil(mid + 1, end, ui, diff, right(idx));
        }
    }

    void updateRangeUtil(int ss, int se, int us, int ue, int diff, int idx) {
        if (lazy[idx]) {
            tree[idx] += (se - ss + 1) * lazy[idx];
            if (ss != se) {
                lazy[left(idx)] += lazy[idx];
                lazy[right(idx)] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (ss > se || ss > ue || se < us) {
            return;
        }
        if (ss >= us && se <= ue) {
            tree[idx] += (se - ss + 1) * diff;
            if (ss != se) {
                lazy[left(idx)] += diff;
                lazy[right(idx)] += diff;
            }
            return;
        }
        int mid = getMid(ss, se);
        updateRangeUtil(ss, mid, us, ue, diff, left(idx));
        updateRangeUtil(mid + 1, se, us, ue, diff, right(idx));
        tree[idx] = tree[left(idx)] + tree[right(idx)];
    }

   public:
    ArraySegmentTree(vector<int>& v) {
        values = v;
        int height = (int)(ceil(log2(v.size())));
        int max_size = 2 * (int)pow(2, height) - 1;

        tree.resize(max_size);
        lazy.resize(max_size);

        construct(0, v.size() - 1, 0);
    }

    int query(int start, int end) {
        return queryUtil(0, values.size() - 1, start, end, 0);
    }

    void update(int new_val, int idx) {
        // if using both range and point updates you have to get the diff
        // through the tree because values is not updated
        int diff = new_val - values[idx];
        values[idx] = new_val;
        updateUtil(0, values.size(), idx, diff, 0);
    }

    void updateRange(int us, int ue, int diff) {
        updateRangeUtil(0, values.size() - 1, us, ue, diff, 0);
    }
};