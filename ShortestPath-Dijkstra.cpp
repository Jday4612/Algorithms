#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;

void dijkstra(int n, const vector<vector<int>> W, vector<edge>& F) {
    int i = 0, vnear = 0;
    edge e;
    vector<int> touch(n + 1);
    vector<int> length(n + 1);
    F.clear();

    for (i = 2; i <= n; i++) {
        touch[i] = 1;
        length[i] = W[1][i];
    }

    for (int t = 1; t <= n - 1; t++) {
        int min = INT_MAX;

        for (i = 2; i <= n; i++)
            if (0 <= length[i] && length[i] < min) {
                min = length[i];
                vnear = i;
            }

        e = make_pair(touch[vnear], vnear);
        F.push_back(e);

        for (i = 2; i <= n; i++)
            if (length[vnear] + W[vnear][i] < length[i]) {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }

        length[vnear] = -1;
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
            }
        }

        dijkstra(n, W, F);

        int totalWeight = 0;
        for (const auto& e : F) {
            totalWeight += W[e.first][e.second];
        }

        cout << totalWeight << endl;
    }

    return 0;
}