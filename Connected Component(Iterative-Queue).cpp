#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V; // ����� ��
    vector<vector<int>> adjList; // ���� ����Ʈ

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void findConnectedComponents(vector<int>& componentSizes) {
        vector<bool> visited(V, false); // �湮 ���θ� ��Ÿ���� �迭

        int componentCount = 0; // ���� ����� ����

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                componentCount++;
                BFS(i, visited, componentSizes);
            }
        }

        cout << componentCount << " ";
        sort(componentSizes.begin(), componentSizes.end());
        for (int size : componentSizes) {
            cout << size << " ";
        }
        cout << endl;
    }

private:
    void BFS(int start, vector<bool>& visited, vector<int>& componentSizes) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int componentSize = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            ++componentSize;

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        if (componentSize > 0) {
            componentSizes.push_back(componentSize);
        }
    }
};

int main() {
    int t, k, m, v;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        Graph g(n);
        vector<int> componentSizes;

        for (int j = 0; j < n; ++j) {
            cin >> k >> m;

            for (int l = 0; l < m; ++l) {
                cin >> v;
                g.addEdge(k - 1, v - 1);
            }
        }

        g.findConnectedComponents(componentSizes);
    }

    return 0;
}