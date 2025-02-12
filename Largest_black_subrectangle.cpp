<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int m,n;
int matrix[1005][1005];

int find_max_of_row(int x){

    int max_s = 0;
    int left_most[10005];
    int right_most[10005];

    stack<int> l;
    stack<int> r;
    for(int i=0; i<n; i++){
        left_most[i]=i;
        right_most[i]=i;
    }

    l.push(0);
    for(int i=0; i<n; i++){
        int u=l.top();
        while(!l.empty() && matrix[x][i]<=matrix[x][u]){
            left_most[i]=left_most[u];
            l.pop();
            if(!l.empty()){
                u=l.top();
            }
        }
        l.push(i);
    }

    r.push(n-1);
    for(int i=n-1; i>-1; i--){
        int u=r.top();
        while(!r.empty() && matrix[x][i]<=matrix[x][u]){
            right_most[i]=right_most[u];
            r.pop();
            if(!r.empty()){
                u=r.top();
            }
        }
        r.push(i);
    }

    for(int i=0; i<n; i++){
        max_s = max(max_s, matrix[x][i]*(right_most[i]-left_most[i]+1));
    }

    return max_s;
}

int main(){

    cin>> m>> n;
    int res=0;

    for(int i=0; i<m;i++){
        for (int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=1; i<m; i++){
        for(int j=0; j<n;j++){
            if(matrix[i][j]!=0){
                matrix[i][j]+=matrix[i-1][j];
            }
        }
    }

    for(int i=0; i<=m; i++){
        res=max(res, find_max_of_row(i));
    }
    cout<< res;   
=======
#include <bits/stdc++.h>
using namespace std;

int m,n;
int matrix[1005][1005];

int find_max_of_row(int x){

    int max_s = 0;
    int left_most[10005];
    int right_most[10005];

    stack<int> l;
    stack<int> r;
    for(int i=0; i<n; i++){
        left_most[i]=i;
        right_most[i]=i;
    }

    l.push(0);
    for(int i=0; i<n; i++){
        int u=l.top();
        while(!l.empty() && matrix[x][i]<=matrix[x][u]){
            left_most[i]=left_most[u];
            l.pop();
            if(!l.empty()){
                u=l.top();
            }
        }
        l.push(i);
    }

    r.push(n-1);
    for(int i=n-1; i>-1; i--){
        int u=r.top();
        while(!r.empty() && matrix[x][i]<=matrix[x][u]){
            right_most[i]=right_most[u];
            r.pop();
            if(!r.empty()){
                u=r.top();
            }
        }
        r.push(i);
    }

    for(int i=0; i<n; i++){
        max_s = max(max_s, matrix[x][i]*(right_most[i]-left_most[i]+1));
    }

    return max_s;
}

int main(){

    cin>> m>> n;
    int res=0;

    for(int i=0; i<m;i++){
        for (int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=1; i<m; i++){
        for(int j=0; j<n;j++){
            if(matrix[i][j]!=0){
                matrix[i][j]+=matrix[i-1][j];
            }
        }
    }

    for(int i=0; i<=m; i++){
        res=max(res, find_max_of_row(i));
    }
    cout<< res;   
>>>>>>> 2363758 (Initial commit)
}