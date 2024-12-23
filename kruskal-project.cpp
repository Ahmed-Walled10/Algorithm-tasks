#include <iostream>
#include<istream>
#include <algorithm>
using namespace std;

const int N = 5e3 + 5, M = 1e5 + 5;
typedef pair<int, pair<int, int>> edge;

int n, m, u, v, c;
int parent[N];

void init()
{
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
}

int getRoot(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = getRoot(parent[u]);
}

bool sameSet(int u, int v)
{
    return getRoot(u) == getRoot(v);
}

void merge(int u, int v)
{
    u = getRoot(u);
    v = getRoot(v);
    if (u == v)
        return;

    parent[u] = v;
}

edge edgeList[M];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        edgeList[i] = { c, { u, v } };
    }
    init();

    sort(edgeList, edgeList + m);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (!sameSet(edgeList[i].second.first, edgeList[i].second.second)) {
            merge(edgeList[i].second.first, edgeList[i].second.second);
            ans += edgeList[i].first;
        }
    }
    cout<<ans;
    return 0;
}

