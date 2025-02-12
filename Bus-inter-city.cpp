<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int node;
    int cost;
};

struct cmp{
    bool operator () (Node a, Node b){
        return a.cost>b.cost;
    }
};

int n, m;
vector<int> graph[5005];
int c[5005];
int d[5005];
vector<pair<int, int> > bus_map[5005];
int dis[5005];
vector<int> D(5005, INT_MAX);
int visitted[5005];

void bfs(int u){
    int visit[5005];
    for(int i=1; i<=n; i++ ){
        dis[i]=-1;
    }

    queue<int> q;
    q.push(u);
    dis[u]=0;
    int tmp=c[u];
    int tmp_d=d[u];
    while(!q.empty()){
        int v=q.front();
        q.pop();
        if(dis[v]>tmp_d) break;
        bus_map[u].push_back({v, tmp});
        if(dis[v]==tmp_d) continue;

        for(int p: graph[v]){
            if(visit[p]!=1){
                q.push(p);
                dis[p]=dis[v]+1;
                visit[p]=1;
            }
        }
    }
}

void dijistra(int u){
    int node1=1;
    priority_queue<Node, vector<Node>, cmp> h;
    D[node1]=0;
    h.push({1, 0});

    while(!h.empty()){
        Node x = h.top();
        h.pop();

        node1=x.node;
        if (node1==u){
            break;
        }
        if(visitted[node1]==1){
            continue;
        }
        
        visitted[node1]=1;
        
        for(auto e:bus_map[node1]){
            int v=e.first;
            int c=e.second;

            if(D[v]>D[node1]+c){
                D[v]=D[node1]+c;
                h.push({v,D[v]});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin >>n >>m;
    for(int i=1; i<=n; i++){
        cin>>c[i]>>d[i];
    }

    int node1, node2;
    for(int i=0; i<m; i++){
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for(int i=1; i<=n; i++){
        bfs(i);
    }

    dijistra(n);
    cout<<D[n];
=======
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int node;
    int cost;
};

struct cmp{
    bool operator () (Node a, Node b){
        return a.cost>b.cost;
    }
};

int n, m;
vector<int> graph[5005];
int c[5005];
int d[5005];
vector<pair<int, int> > bus_map[5005];
int dis[5005];
vector<int> D(5005, INT_MAX);
int visitted[5005];

void bfs(int u){
    int visit[5005];
    for(int i=1; i<=n; i++ ){
        dis[i]=-1;
    }

    queue<int> q;
    q.push(u);
    dis[u]=0;
    int tmp=c[u];
    int tmp_d=d[u];
    while(!q.empty()){
        int v=q.front();
        q.pop();
        if(dis[v]>tmp_d) break;
        bus_map[u].push_back({v, tmp});
        if(dis[v]==tmp_d) continue;

        for(int p: graph[v]){
            if(visit[p]!=1){
                q.push(p);
                dis[p]=dis[v]+1;
                visit[p]=1;
            }
        }
    }
}

void dijistra(int u){
    int node1=1;
    priority_queue<Node, vector<Node>, cmp> h;
    D[node1]=0;
    h.push({1, 0});

    while(!h.empty()){
        Node x = h.top();
        h.pop();

        node1=x.node;
        if (node1==u){
            break;
        }
        if(visitted[node1]==1){
            continue;
        }
        
        visitted[node1]=1;
        
        for(auto e:bus_map[node1]){
            int v=e.first;
            int c=e.second;

            if(D[v]>D[node1]+c){
                D[v]=D[node1]+c;
                h.push({v,D[v]});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin >>n >>m;
    for(int i=1; i<=n; i++){
        cin>>c[i]>>d[i];
    }

    int node1, node2;
    for(int i=0; i<m; i++){
        cin>>node1>>node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for(int i=1; i<=n; i++){
        bfs(i);
    }

    dijistra(n);
    cout<<D[n];
>>>>>>> 2363758 (Initial commit)
}