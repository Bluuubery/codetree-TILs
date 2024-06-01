#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 1000

using namespace std;

int N, M;
vector<pair<int, int> > edges[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1][MAX_N + 1];


void DFS(int node, int x) {
    for(int i=0; i< edges[x].size(); i++) {
        int y, d;
        tie(y, d) = edges[x][i];

        if (visited[y]) continue;

        visited[y] = true;

        dist[node][y] = dist[node][x] + d;

        DFS(node, y);
    }

}

int main() {

    // 입력
    cin >> N >> M;

    // 간선 정보 저장
    for (int i=1; i<=N-1; i++) {
        int x, y, d;
        cin >> x >> y >> d;

        edges[x].push_back({y, d});
        edges[y].push_back({x, d});
         
    }

    // 노드 간 거리 계산
    for(int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            visited[j] = false;            
        }
        visited[i] = true;
        DFS(i, i);
    }


    for(int i=1; i<=M; i++) {
        int x, y;

        cin >> x >> y;

        cout << dist[x][y]<< endl;
    }

    return 0;
}