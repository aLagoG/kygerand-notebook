#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

#pragma region wgraph

struct Edge {
    int a, b, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    };
    Edge() {
        a = 0;
        b = 0;
        weight = 0;
    };
    Edge(int _a, int _b, int _weight) {
        a = _a;
        b = _b;
        weight = _weight;
    };
};

struct Graph {
    int V, E;
    vector<Edge> edges;
    Graph(int v, int e) {
        V = v;
        E = e;
        edges = vector<Edge>(E);
    }
};

#pragma endregion wgraph

#pragma region unionfind

struct Subset {
    int parent, rank;
};

int find(vector<Subset>& subsets, int i) {
    // if i is not parent, compress path to the
    // actual parent by pointing straight to it
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void _union(vector<Subset>& subsets, int x, int y) {
    int root_x = find(subsets, x), root_y = find(subsets, y);

    // smaller 'tree' becomes child
    // of biger 'tree'
    if (subsets[root_x].rank > subsets[root_y].rank) {
        subsets[root_y].parent = root_x;
    } else if (subsets[root_x].rank < subsets[root_y].rank) {
        subsets[root_x].parent = root_y;
    } else {
        subsets[root_y].parent = root_x;
        subsets[root_x].rank++;
    }
}

#pragma endregion unionfind

vector<Edge> k_mst(Graph& g) {
    int V = g.V, E = g.E;
    vector<Edge> res(V - 1);

    sort(g.edges.begin(), g.edges.end());

    vector<Subset> subsets(E);
    for (int i = 0; i < E; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    Edge cur;

    int e = 0,  // count of edges in result MST
        i = 0;  // for traversal of sorted edges
    int seta, setb;
    while (e < (V - 1)) {
        cur = g.edges[i++];

        seta = find(subsets, cur.a);
        setb = find(subsets, cur.b);

        if (seta != setb) {  // sides of cur are not together
            res[e++] = cur;
            _union(subsets, seta, setb);
        }
    }

    return res;
}

int main() {
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph

    Graph g(V, E);

    g.edges[0].a = 0;
    g.edges[0].b = 1;
    g.edges[0].weight = 10;

    g.edges[1].a = 0;
    g.edges[1].b = 2;
    g.edges[1].weight = 6;

    g.edges[2].a = 0;
    g.edges[2].b = 3;
    g.edges[2].weight = 5;

    g.edges[3].a = 1;
    g.edges[3].b = 3;
    g.edges[3].weight = 2;

    g.edges[4].a = 2;
    g.edges[4].b = 3;
    g.edges[4].weight = 4;

    vector<Edge> result = k_mst(g);

    for (int i = 0; i < (V - 1); i++) {
        printf("from %d  to %d w: %d\n", result[i].a, result[i].b,
               result[i].weight);
    }

    return 0;
}
