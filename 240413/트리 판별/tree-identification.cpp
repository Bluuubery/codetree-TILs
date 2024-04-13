#include <iostream>
#include <vector>

#define MAX_N 10000

using namespace std;

int m;
int root;
int degree[MAX_N + 1];
vector<int> tree[MAX_N + 1];
bool used[MAX_N + 1];
bool visited[MAX_N + 1];
bool is_tree = true;


void DFS(int x) {

    for(int i=0; i < tree[x].size(); i++) {
        int y = tree[x][i];

        if(visited[y]) continue;

        visited[y] = true;
        DFS(y);
    }

    return;
}


int main() {
    cin >> m;

    for(int i=0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        
        tree[x].push_back(y);

        used[x] = used[y] = true;

        degree[y] ++;
    }

    for(int i=0; i< MAX_N; i++) {
        if(used[i] && degree[i] == 0) {
            if(root != 0) is_tree = false;
            root = i;
        }
    }

    if(root == 0) is_tree = false;

    for(int i=1; i<= MAX_N; i++) {
        if(used[i] && i!= root && degree[i] != 1) {
            is_tree = false;
        }
    }

    if(is_tree && root != 0){
        visited[root] = true;
        DFS(root);
    }

    for(int i=1; i <= MAX_N; i++){
        if(used[i] && !visited[i]) {
            is_tree = false;
        }
    }

    if(is_tree) cout << 1;
    else cout << 0;

    return 0;
}