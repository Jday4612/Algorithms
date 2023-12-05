#include <iostream>
#include <vector>
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

    void findConnectedComponents() {
        vector<bool> visited(V, false); // �湮 ���θ� ��Ÿ���� �迭
        vector<int> cnt;

        int componentCount = 0; // ���� ����� ����

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                ++componentCount;
                vector<int> component;
                DFS(i, visited, component);
                cnt.push_back((int)component.size());
            }
        }

        cout << componentCount << " ";
        sort(cnt.begin(), cnt.end());
        for (int size : cnt) {
            cout << size << " ";
        }
        cout << endl;
    }

private:
    void DFS(int current, vector<bool>& visited, vector<int>& component) {
        component.push_back(current);
        visited[current] = true;

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, component);
            }
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

        for (int j = 0; j < n; ++j) {
            cin >> k >> m;

            for (int l = 0; l < m; ++l) {
                cin >> v;
                g.addEdge(k - 1, v - 1);
            }
        }

        g.findConnectedComponents();
    }

    return 0;
}