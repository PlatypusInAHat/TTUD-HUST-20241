#include<bits/stdc++.h>
#include<vector>
using namespace std;

int m,n;
int p;
int res=INT_MAX;
int X[35];
vector<vector<int>> conflict(35);
vector<vector<int>> coures(35);
vector<vector<int>> teacher(35);

bool check(int x, int k){
    if (teacher[x].size()+1>=res) return false;
    for(int i : teacher[x]){
        for(int sub: conflict[k])
            if(i==sub) return false;
    }
    return true;
}

int Try(int k){
    for(int x: coures[k]){
        if(check(x,k)){
            X[k]=x;
            teacher[x].push_back(k);

            if(k==n){
                int maxCV=0;
                for (int i=1; i<=m;i++){
                    int tmp=teacher[i].size();
                    maxCV=max(maxCV,tmp);
                }
                res=min(res,maxCV);
            }
            else{
                Try(k+1);
            }
            teacher[x].pop_back();
        }
    }
}

int main(){
    cin>> m>>n;
    int numsubject;
    int course;
    for (int i=1; i<=m; i++){
        cin>>numsubject;;
        for (int j=1; j<=numsubject; j++){
            cin>>course;
            coures[course].push_back(i);
        }
    }
    cin>>p;
    int subject1, subject2;
    for (int i=1; i<=p;i++){
        cin>> subject1>> subject2;
        conflict[subject1].push_back(subject2);
        conflict[subject2].push_back(subject1);
    }
   
    Try(1);
    cout<< res;
}

