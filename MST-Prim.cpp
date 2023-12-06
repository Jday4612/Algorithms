#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;

void prim(int n, const vector<vector<int>> W, vector<edge>& F) {
    int i = 0, vnear = 0;
    int min;
    edge e;
    vector<int> nearest(n + 1);
    vector<int> distance(n + 1);
    F.clear();

    for (i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    for (int t = 1; t <= n - 1; t++) {
        min = INT_MAX;

        for (i = 2; i <= n; i++)
            if (0 <= distance[i] && distance[i] < min) {
                min = distance[i];
                vnear = i;
            }

        e = make_pair(nearest[vnear], vnear);
        F.push_back(e);
        distance[vnear] = -1;

        for (i = 2; i <= n; i++)
            if (W[i][vnear] < distance[i]) {
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }
    }
}

int main() {
    int t, n, k, m, v, w;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<vector<int>> W(n + 1, vector<int>(n + 1, 10000));
        vector<edge> F;

        for (int i = 0; i < n; ++i) {
            cin >> k >> m;

            for (int j = 0; j < m; ++j) {
                cin >> v >> w;
                W[k][v] = w;
                W[v][k] = w;
            }
        }

        prim(n, W, F);

        int totalWeight = 0;
        for (const auto& e : F) {
            totalWeight += W[e.first][e.second];
        }

        cout << totalWeight << endl;
    }

    return 0;
}