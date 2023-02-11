/*
LCA(Lowest Common Ancestor)
트리 속 두 노드의 가장 가까운 조상 노드를 의미한다.

이것을 BFS나 DFS를 이용해 모든 경로를 훑어봄으로써 두 노드 사이의 같은 조상을 찾을 수도 있겠지만
이를 더욱 빠르게 하기 위해 만든 알고리즘이 LCA 알고리즘이다.

LCA 알고리즘
1. 트리를 만들고 각 노드의 조상들을 저장한다.
2. 두 노드의 깊이를 같게 깊이가 깊은 노드를 조상으로 업데이트 시켜준다.
3. 두 노드를 조상으로 올리면서 가장 가까운 공통조상을 찾아준다.

*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define swap(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }
#define MAX_NODE 100001

using namespace std;

int depth[MAX_NODE];
int ac[MAX_NODE][20];

typedef pair<int, int> pii;
vector<int> graph[MAX_NODE];

int max_level;

// DP(ac)배열 만드는 과정
void getTree(int here, int parent)
{
    // here의 깊이는 부모노드깊이 + 1
    depth[here] = depth[parent] + 1;

    // heredml 1번째 조상은 부모노드
    ac[here][0] = parent;

    // MAX_NODE에 log2를 씌어 내림을 해준다.
    max_level = (int)floor(log2(MAX_NODE));

    for (int i = 1; i <= max_level; i++)
    {
        // tmp :: here의 2^(ㅑ-1)번째 조상

        /*
            즉, ac[here][i] = ac[tmp][i-1]은
            here의 2^i번째 조상은 tmp의 2^(i-1)번째 조상의 2^(i-1)번째 조상과 같다는 의미
            예를들어 i = 3일때
            here의 8번째 조상은 tmp(here의 4번째 조상)의 4번째 조상과 같다.
            i = 4일때 here의 16번째 조상은 here의 8번째 조상(tmp)의 8번째와 같다.
        */

        int tmp = ac[here][i - 1];
        ac[here][i] = ac[tmp][i - 1];
    }

    // dfs 알고리즘
    int len = graph[here].size();
    for (int i = 0; i < len; i++)
    {
        int there = graph[here][i];
        if (there != parent)
        {
            getTree(there, here);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m;

    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    depth[0] = -1;

    getTree(1, 0);

    scanf("%d", &m);

    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (depth[a] != depth[b])
        {
            if (depth[a] != depth[b])
                swap(a, b);

            for (int i = max_level; i >= 0; i--)
            {
                if (depth[a] <= depth[ac[b][i]])
                    b = ac[b][i];
            }
        }

        int lca = a;

        if (a != b)
        {
            for (int i = max_level; i >= 0; i--)
            {
                if (ac[a][i] != ac[b][i])
                {
                    a = ac[a][i];
                    b = ac[b][i];
                }
                lca = ac[a][i];
            }
        }
        printf("%d\n", lca);
    }
    return 0;
}
