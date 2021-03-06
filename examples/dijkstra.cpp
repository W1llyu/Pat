/**
 * Dijkstra求两点最短距离或最优路径问题
 * A1072
 * A1111
 * A1131
 */
#include <iostream>
#include <vector>
#include <limits.h>
#define MAXN 1010
using namespace std;

int n, m, x, y, d, distmap[MAXN][MAXN];
vector<int> edges[MAXN];

void dijkstra(int src, int dst) {
    vector<bool> visits(n, false);
    vector<int> dist(n, INT_MAX), routes[MAXN];
    dist[src] = 0;
    for (int i=0; i<n; i++) {
        int cur = -1;
        for (int j=0; j<n; j++) {
            if (!visits[j] && (cur == -1 || dist[cur] > dist[j]))
                cur = j;
        }
        if (cur == -1 || dist[cur] == INT_MAX) break;
        visits[cur] = true;
        routes[cur].push_back(cur);
        if (cur == dst) break;
        for (int j=0; j<edges[cur].size(); j++) {
            int to = edges[cur][j];
            if (!visits[to] && dist[to] > dist[cur] + distmap[cur][to]) {
                dist[to] = dist[cur] + distmap[cur][to];
                routes[to] = routes[cur];
            }
        }
    }
    printf("%d\n", dist[dst]);
    for (int i=0; i<routes[dst].size(); i++) {
        printf("%d%s", routes[dst][i], i == routes[dst].size()-1 ? "\n" : "->");
    }
}

/*
10 15
0 1 1
8 0 1
4 8 1
3 4 3
3 9 4
0 6 1
7 5 2
8 5 2
2 3 2
2 1 1
1 3 3
1 4 1
9 7 3
5 1 5
6 5 1
3 5
 */
int main () {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &x, &y, &d);
        edges[x].push_back(y);
        edges[y].push_back(x);
        distmap[x][y] = distmap[y][x] = d;
    }
    scanf("%d %d", &x, &y);
    dijkstra(x, y);
    return 0;
}