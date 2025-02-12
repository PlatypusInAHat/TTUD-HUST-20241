<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int m, n;
vector<int> graph[20005];
bool visited[20005];
int mathching[20005];

bool augmentingPath(int u){
    for(int v: graph[u]){
        if(!visited[v]){
            visited[v]=true;

            if(mathching[v]==0 || augmentingPath(mathching[v])){
                mathching[v]=u;
                return true;
            }
        }
    }
    return false;
}

int maxMatching(){
    int res=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            visited[j]=false;
        }
        if (augmentingPath(i)) {
            res++;
        }
    }
    return res;
}

int main(){
    cin >> n >>m;

    int k, u;
    for(int i=1; i<=n; i++){
        cin >>k;
        for(int j=0; j<k; j++){
            cin >>u;
            graph[i].push_back(u);
        }
    }
    cout<<maxMatching();
=======
#include<bits/stdc++.h>
using namespace std;

int m, n;
vector<int> graph[20005];
bool visited[20005];
int mathching[20005];

bool augmentingPath(int u){
    for(int v: graph[u]){
        if(!visited[v]){
            visited[v]=true;

            if(mathching[v]==0 || augmentingPath(mathching[v])){
                mathching[v]=u;
                return true;
            }
        }
    }
    return false;
}

int maxMatching(){
    int res=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            visited[j]=false;
        }
        if (augmentingPath(i)) {
            res++;
        }
    }
    return res;
}

int main(){
    cin >> n >>m;

    int k, u;
    for(int i=1; i<=n; i++){
        cin >>k;
        for(int j=0; j<k; j++){
            cin >>u;
            graph[i].push_back(u);
        }
    }
    cout<<maxMatching();
>>>>>>> 2363758 (Initial commit)
}