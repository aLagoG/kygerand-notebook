#include <vector>

using namespace std;

class NodeSegmentTree {
   private:
    struct Node {
        int value = 0;
        int lazy = 0;
        Node* left = NULL;
        Node* right = NULL;
    };

    Node tree;
    // values is only needed when using only point upates
    vector<int> values;

    int getMid(int start, int end) {
        return (start + end) >> 1;
    }

    int construct(int start, int end, Node& node) {
        if (start == end) {
            node.value = values[start];
            return node.value;
        }
        node.left = new Node;
        node.right = new Node;
        int mid = getMid(start, end);
        node.value = construct(start, mid, *node.left) +
                     construct(mid + 1, end, *node.right);
        return node.value;
    }

    int queryUtil(int ss, int se, int qs, int qe, Node& node) {
        if (node.lazy) {
            node.value += (se - ss + 1) * node.lazy;
            if (ss != se) {
                node.left->lazy += node.lazy;
                node.right->lazy += node.lazy;
            }
            node.lazy = 0;
        }
        if (qs <= ss && qe >= se) {
            return node.value;
        }
        if (se < qs || ss > qe) {
            return 0;
        }
        int mid = getMid(ss, se);
        return queryUtil(ss, mid, qs, qe, *node.left) +
               queryUtil(mid + 1, se, qs, qe, *node.right);
    }

    void updateUtil(int start, int end, int idx, int diff, Node& node) {
        if (idx < start || idx > end) {
            return;
        }
        node.value += diff;
        if (end != start) {
            int mid = getMid(start, end);
            updateUtil(start, mid, idx, diff, *node.left);
            updateUtil(mid + 1, end, idx, diff, *node.right);
        }
    }

    void updateRangeUtil(int ss, int se, int us, int ue, int diff, Node& node) {
        if (node.lazy) {
            node.value += (se - ss + 1) * node.lazy;
            if (ss != se) {
                node.left->lazy += node.lazy;
                node.right->lazy += node.lazy;
            }
            node.lazy = 0;
        }
        if (ss > se || ss > ue || se < us) {
            return;
        }
        if (ss >= us && se <= ue) {
            node.value += (se - ss + 1) * diff;
            if (ss != se) {
                node.left->lazy += diff;
                node.right->lazy += diff;
            }
            return;
        }
        int mid = getMid(ss, se);
        updateRangeUtil(ss, mid, us, ue, diff, *node.left);
        updateRangeUtil(mid + 1, se, us, ue, diff, *node.right);
        node.value = node.left->value + node.right->value;
    }

   public:
    NodeSegmentTree(vector<int>& v) {
        values = v;
        construct(0, values.size() - 1, tree);
    }

    int query(int start, int end) {
        return queryUtil(0, values.size() - 1, start, end, tree);
    }

    void update(int new_val, int index) {
        // if using both range and point updates you have to get the diff
        // through the tree because values is not updated
        int diff = new_val - values[index];
        values[index] = new_val;
        updateUtil(0, values.size() - 1, index, diff, tree);
    }

    void updateRange(int us, int ue, int diff) {
        updateRangeUtil(0, values.size() - 1, us, ue, diff, tree);
    }
};