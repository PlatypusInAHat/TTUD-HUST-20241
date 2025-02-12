<<<<<<< HEAD
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 100010;

int n, m;
bool joint[maxN];
int timeDfs = 0, bridge = 0;
int low[maxN], num[maxN];
vector <int> g[maxN];
 
void dfs(int u, int pre){
    int child=0;
    low[u]=num[u]=++timeDfs;
    for(int v: g[u]){
        if(v==pre) continue;

        if(!num[v]){
            dfs(v,u);
            child++;
            low[u]=min(low[u], low[v]);


            if(u==pre ){
                if(child>1) joint[u]=true;
            }
            else if(low[v]>=num[u]){
                joint[u]=true;
            }
        }
        else{
            low[u]=min(low[u], num[v]);
        }

        if(low[v]>num[u]){
            bridge++;
        }
    }
}
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) 
        if (!num[i]) dfs(i, i);

    int cntJoint = 0;
    for (int i = 1; i <= n; i++) cntJoint += joint[i];

    cout << cntJoint << ' ' << bridge;
} 
=======
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 100010;

int n, m;
bool joint[maxN];
int timeDfs = 0, bridge = 0;
int low[maxN], num[maxN];
vector <int> g[maxN];
 
void dfs(int u, int pre){
    int child=0;
    low[u]=num[u]=++timeDfs;
    for(int v: g[u]){
        if(v==pre) continue;

        if(!num[v]){
            dfs(v,u);
            child++;
            low[u]=min(low[u], low[v]);


            if(u==pre ){
                if(child>1) joint[u]=true;
            }
            else if(low[v]>=num[u]){
                joint[u]=true;
            }
        }
        else{
            low[u]=min(low[u], num[v]);
        }

        if(low[v]>num[u]){
            bridge++;
        }
    }
}
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) 
        if (!num[i]) dfs(i, i);

    int cntJoint = 0;
    for (int i = 1; i <= n; i++) cntJoint += joint[i];

    cout << cntJoint << ' ' << bridge;
} 
>>>>>>> 2363758 (Initial commit)
