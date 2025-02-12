#include <bits/stdc++.h>
using namespace std;

int c[30][30];
int n;
int k;
int A[30];
int mark[30]={};
int inBus[40]={};
int place=0;
int curr=0;
int best=INT_MAX;

bool check(int x){
    if (curr>best)
        return false;
    if (mark[x]==0){
        if(x>n){
            if(inBus[x-n]==1)
                return true;
        } else{
            if(inBus[x]==0 && place<k)
                return true;
        }
    }
    return false;
}

void Try(int k){
    for(int i=1; i<=2*n; i++){
        if (check(i)&&curr+c[A[k-1]][i]+2*n-k<=best){
            A[k]=i;
            curr=curr+c[A[k-1]][A[k]];
            mark[i]=1;
            if(i>n){
                inBus[i]=0;
                place--;
            }
            else{
                place++;
                inBus[i]=1;
            }

            if(k==2*n){
                best=min(best,curr+c[A[k]][0]);
            }
            else
                Try(k+1);

            curr=curr-c[A[k-1]][A[k]];
            mark[i]=0;
            if(i>n){  
                place++;
                inBus[i]=1;
            }
            else{
                place--;
                inBus[i]=0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >>n>>k;
    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin>> c[i][j];
        }
    }
    Try(1);
    cout<< best;
}