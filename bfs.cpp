
// A Quick implementation of BFS using vectors and queue
// Its time complexity is O(v+e).
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

bool v[10]={0};
vector<int> g[20];

void edge(int a, int b)
{
    g[a].pb(b);
   
    g[b].pb(a);   // for undirected graph add this line
}

void bfs(int u)
{
    queue<int> q;

    q.push(u);
    v[u] = true;

    while (!q.empty()) {

        int f = q.front();
        q.pop();

        cout << f << " ";

        // Enqueue all adjacent of f and mark them visited
        for (auto x:g[f]){
            if (!v[x]){
                v[x]=1;
                q.push(x);
            }
        }
    }
}


int main()
{
    

    int n, e;
    cin >> n >> e;

    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edge(a, b);
    }

  bfs(1);

    return 0;
}
