<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> graph(10005);
int L[10005];
int c[10005];
int d[10005];
int S[10005];

int main (){
    cin >> n >> m;

    for(int i=1; i<=n ; i++ ){
        cin >> d[i];
    }

    int node1 , node2;
    for(int i=0; i<m; i++){
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        c[node2]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(c[i]==0){
            q.push(i);
        }
    }

    int index =1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        L[index]=u;
        index++;

        for(int v: graph[u]){
            c[v]--;
            if(c[v]==0){
                q.push(v);
            }
        }
    }

    for (int i=0; i<n; i++){
        for(int v: graph[L[i]]){
            S[v]=max(S[v], S[L[i]]+d[L[i]]);
        }
    }

    int res=0;
    for(int i=0; i<=n; i++){
        res=max(res,S[i]+d[i]);
    }

    cout<<res;



=======
#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> graph(10005);
int L[10005];
int c[10005];
int d[10005];
int S[10005];

int main (){
    cin >> n >> m;

    for(int i=1; i<=n ; i++ ){
        cin >> d[i];
    }

    int node1 , node2;
    for(int i=0; i<m; i++){
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        c[node2]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(c[i]==0){
            q.push(i);
        }
    }

    int index =1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        L[index]=u;
        index++;

        for(int v: graph[u]){
            c[v]--;
            if(c[v]==0){
                q.push(v);
            }
        }
    }

    for (int i=0; i<n; i++){
        for(int v: graph[L[i]]){
            S[v]=max(S[v], S[L[i]]+d[L[i]]);
        }
    }

    int res=0;
    for(int i=0; i<=n; i++){
        res=max(res,S[i]+d[i]);
    }

    cout<<res;



>>>>>>> 2363758 (Initial commit)
}