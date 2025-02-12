<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
int m, n;
vector<vector<int>> graph(100005);
int num[100005];
int low[100005];
int curr=0;
int onStack[100005];
stack<int> s;
int res=0;

void dfs(int u, int pre){
    num[u] = low[u]=++curr;
    s.push(u);
    onStack[u]=1;

    for(int v: graph[u]){
        if(v == pre) continue;
        
        if(num[v]==0){
            dfs(v, u);
            low[u]=min(low[u], low[v]);
        }
        else if (onStack[v]==1){
            low[u]=min(low[u],num[v]);
        }
    }

    int v;
    if(low[u]==num[u]){
        while(1){
            v=s.top();
            s.pop();
            onStack[v]=0;
            if(v==u){
                break;
            }
        }
        res++;
    }


}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        if(num[i]==0){
            dfs(i,i);
        }
    }
    cout<<res;
=======
#include<bits/stdc++.h>
using namespace std;
int m, n;
vector<vector<int>> graph(100005);
int num[100005];
int low[100005];
int curr=0;
int onStack[100005];
stack<int> s;
int res=0;

void dfs(int u, int pre){
    num[u] = low[u]=++curr;
    s.push(u);
    onStack[u]=1;

    for(int v: graph[u]){
        if(v == pre) continue;
        
        if(num[v]==0){
            dfs(v, u);
            low[u]=min(low[u], low[v]);
        }
        else if (onStack[v]==1){
            low[u]=min(low[u],num[v]);
        }
    }

    int v;
    if(low[u]==num[u]){
        while(1){
            v=s.top();
            s.pop();
            onStack[v]=0;
            if(v==u){
                break;
            }
        }
        res++;
    }


}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        if(num[i]==0){
            dfs(i,i);
        }
    }
    cout<<res;
>>>>>>> 2363758 (Initial commit)
}