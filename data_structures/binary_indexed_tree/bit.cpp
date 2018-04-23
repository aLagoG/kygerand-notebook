#include <vector>

using namespace std;

class FenwickTree {
   private:
    vector<int> tree;

   public:
    FenwickTree(int n) {
        tree.resize(n + 1);
    }
    FenwickTree(vector<int> &v) {
        int n = v.size();
        tree.resize(n + 1);
        for (int i = 0; i < n; i++) {
            update(i, v[i]);
        }
    }

    void update(int index, int delta) {
        index++;
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & (-index);
        }
    }

    int query(int index) {
        index++;
        int sum = 0;
        while (index) {
            sum += tree[index];
            index &= index - 1;
        }
        return sum;
    }
};