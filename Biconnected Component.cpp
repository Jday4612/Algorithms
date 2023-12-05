#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> discovery;
    vector<int> low;
    vector<int> parent;
    vector<bool> isArticulationPoint;
    stack<pair<int, int>> edges;
    vector<vector<int>> biconnectedComponents;

    Graph(int nodes) : V(nodes), adjList(nodes + 1), visited(nodes + 1, false), discovery(nodes + 1, 0), low(nodes + 1, 0), parent(nodes + 1, -1), isArticulationPoint(nodes + 1, false) {}

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void findBiconnectedComponents() {
        int time = 0;

        for (int i = 1; i <= V; ++i) {
            if (!visited[i]) {
                dfs(i, time);
            }
        }

        cout << biconnectedComponents.size() << endl;

        vector<int> articulationPoints;
        for (int i = 1; i <= V; ++i) {
            if (isArticulationPoint[i]) {
                articulationPoints.push_back(i);
            }
        }

        cout << articulationPoints.size() << " ";
        for (int node : articulationPoints) {
            cout << node << " ";
        }
        cout << endl;
    }

private:
    void dfs(int u, int& time) {
        visited[u] = true;
        discovery[u] = low[u] = ++time;
        int children = 0;

        for (int v : adjList[u]) {
            if (!visited[v]) {
                children++;
                edges.push({ u, v });
                parent[v] = u;
                dfs(v, time);

                low[u] = min(low[u], low[v]);

                if (low[v] >= discovery[u]) {
                    vector<int> component;
                    while (!edges.empty() && edges.top() != make_pair(u, v)) {
                        component.push_back(edges.top().first);
                        component.push_back(edges.top().second);
                        edges.pop();
                    }
                    component.push_back(u);
                    component.push_back(v);
                    edges.pop();

                    sort(component.begin(), component.end());
                    biconnectedComponents.push_back(component);
                }

                if (low[v] >= discovery[u] && parent[u] != -1) {
                    isArticulationPoint[u] = true;
                }
            }
            else if (v != parent[u] && discovery[v] < low[u]) {
                low[u] = discovery[v];
                edges.push({ u, v });
            }
        }

        if (parent[u] == -1 && children > 1) {
            isArticulationPoint[u] = true;
        }
    }
};

int main() {
    int t, n, k, m, v;
    cin >> t;

    while (t--) {
        cin >> n;

        Graph g(n);

        for (int i = 0; i < n; i++) {
            cin >> k >> m;

            for (int j = 0; j < m; ++j) {
                cin >> v;
                g.addEdge(k, v);
            }
        }

        g.findBiconnectedComponents();
    }

    return 0;
}
