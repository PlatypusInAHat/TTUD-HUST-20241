<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
int n, m ,q;
int d[15];
vector<int> a[15];
int c[15][15];
int path[15][15];
int workload[15];
int curr[15];
int visited[15];
int res=INT_MAX;
int res_x[15];

bool check_x(int x){
    if (visited[x]==1){
        return false;
    }
    else{
        return true;
    }
}

void Try_x(int x, int k){
    for(int i : a[x]){
        if(check_x(i)){
            path[x][k]=i;
            curr[x]+=c[path[x][k-1]][i];
            visited[i]=1;

            if (k==a[x].size()){
                res_x[x]=min(res_x[x], curr[x]+c[i][0]);
            }

            else{
                Try_x(x, k+1);
            }

            visited[i]=0;
            curr[x]-=c[path[x][k-1]][i];
        }
    }
}



bool check(int i, int x){
    if (workload[x]+d[i]>q){
        return false;
    }
    return true;
}

void Try(int k){
    for(int i=0; i<m; i++){
        if(check(k, i)){
            a[i].push_back(k);
            workload[i]+=d[k];

            if(k==n){
                int curr=0;
                for(int i=0; i<m; i++){
                    if (a[i].size()>0){
                        res_x[i]=INT_MAX;
                        path[i][0]=0;
                        Try_x(i, 1);
                        curr+=res_x[i];
                    }
                }
                res=min(res, curr);
            }
            else Try(k+1);

            a[i].pop_back();
            workload[i]-=d[k];
        }
    }
}

int main(){
    cin >> n >>m >>q;
    for(int i=1; i<=n; i++){
        cin >>d[i];
    }
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin >> c[i][j];
        }
    }

    Try(1);

    cout<<res;

=======
#include<bits/stdc++.h>
using namespace std;
int n, m ,q;
int d[15];
vector<int> a[15];
int c[15][15];
int path[15][15];
int workload[15];
int curr[15];
int visited[15];
int res=INT_MAX;
int res_x[15];

bool check_x(int x){
    if (visited[x]==1){
        return false;
    }
    else{
        return true;
    }
}

void Try_x(int x, int k){
    for(int i : a[x]){
        if(check_x(i)){
            path[x][k]=i;
            curr[x]+=c[path[x][k-1]][i];
            visited[i]=1;

            if (k==a[x].size()){
                res_x[x]=min(res_x[x], curr[x]+c[i][0]);
            }

            else{
                Try_x(x, k+1);
            }

            visited[i]=0;
            curr[x]-=c[path[x][k-1]][i];
        }
    }
}



bool check(int i, int x){
    if (workload[x]+d[i]>q){
        return false;
    }
    return true;
}

void Try(int k){
    for(int i=0; i<m; i++){
        if(check(k, i)){
            a[i].push_back(k);
            workload[i]+=d[k];

            if(k==n){
                int curr=0;
                for(int i=0; i<m; i++){
                    if (a[i].size()>0){
                        res_x[i]=INT_MAX;
                        path[i][0]=0;
                        Try_x(i, 1);
                        curr+=res_x[i];
                    }
                }
                res=min(res, curr);
            }
            else Try(k+1);

            a[i].pop_back();
            workload[i]-=d[k];
        }
    }
}

int main(){
    cin >> n >>m >>q;
    for(int i=1; i<=n; i++){
        cin >>d[i];
    }
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin >> c[i][j];
        }
    }

    Try(1);

    cout<<res;

>>>>>>> 2363758 (Initial commit)
}