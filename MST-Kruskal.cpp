#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, weight;
};

typedef vector<edge> set_of_edges;

struct disjoint_set {
    vector<int> parent, depth;

    disjoint_set(int n) {
        parent.resize(n + 1);
        depth.resize(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            depth[i] = 0;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        if (x != y) {
            if (depth[x] > depth[y]) {
                parent[y] = x;
            }
            else {
                parent[x] = y;

                if (depth[x] == depth[y]) {
                    depth[y]++;
                }
            }
        }
    }
};

bool compare_edges(const edge& a, const edge& b) {
    return a.weight < b.weight;
}

void kruskal(int n, int m, set_of_edges E, set_of_edges& F) {
    int i, j;
    int p, q;
    edge e;

    sort(E.begin(), E.end(), compare_edges);
    F.clear();
    disjoint_set ds(n);

    int idx = 0;
    while (F.size() < n - 1) {
        e = E[idx++];
        i = e.u;
        j = e.v;
        p = ds.find(i);
        q = ds.find(j);

        if (p != q) {
            ds.merge(p, q);
            F.push_back(e);
        }
    }
}

int main() {
    int t, n, k, m;
    cin >> t;

    while (t--) {
        cin >> n;

        set_of_edges E;
        for (int i = 0; i < n; ++i) {
            cin >> k >> m;

            for (int j = 0; j < m; ++j) {
                edge e;
                e.u = k;
                cin >> e.v >> e.weight;
                E.push_back(e);
            }
        }

        set_of_edges F;
        kruskal(n, E.size(), E, F);

        int result = 0;
        for (const edge& e : F) {
            result += e.weight;
        }

        cout << result << endl;
    }

    return 0;
}