#include <iostream>
#include <vector>
#include <cstring>
#define max 100
using namespace std;

vector<int> adj[max];
bool visited[max];
int depth[max];
int parents[max];
int V, E;
int maxCount;

void DFS(int node, int dep)
{
    visited[node] = true;
    depth[node] = dep;
    for (int i = 0; i < adj[node].size(); i++)
    {
        int next_node = adj[node][i];
        if (visited[next_node]) // 만약 방문만 정점이면 탐색X
        {
            continue;
        }
        parents[next_node] = node; // 다음노드의 부모는 현재 노드가 된다. (위에서 부터 탐색하므로)
        DFS(next_node, dep + 1);   // 다음노드와 깊이를 +1 해준다.
    }
}

int LCA(int node_a, int node_b)
{
    if (node_a == node_b)
    {
        return node_a;
    }
    if (depth[node_a] == depth[node_b])
    {
        maxCount += 2;
        return LCA(parents[node_a], parents[node_b]);
    }
    else if (depth[node_a] > depth[node_b])
    {
        maxCount += 1;
        return LCA(parents[node_a], node_b);
    }
    else
    {
        maxCount += 1;
        return LCA(node_a, parents[node_b]);
    }
}

int main(int argc, char const *argv[])
{
    cin >> V >> E;

    memset(visited, 0, sizeof(visited));
    maxCount = 0;

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1, 0);

    cout << LCA(4, 9) << maxCount;

    return 0;
}