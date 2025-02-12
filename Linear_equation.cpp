<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

vector<int> sol(100000,0);
vector<int> sum(1000,0);
vector<int> a(100000,0);
int n,target;
int res;


void Try(int k){
    for(int i=1; i<=(target-sum[k-1])/a[k]; i++){
        sol[k]=i;
        sum[k]=sum[k-1]+i*a[k];
        if (k==n){
            if(sum[k]==target)
                res++;
        }
        else{
            Try(k+1);
        }
    }
}
int main(){

    cin >>n>> target;
    res=0;
    for(int i=1; i<=n; i++){
        cin>> a[i];
    }
    Try(1);
    cout<< res;
}
=======
#include<bits/stdc++.h>
using namespace std;

vector<int> sol(100000,0);
vector<int> sum(1000,0);
vector<int> a(100000,0);
int n,target;
int res;


void Try(int k){
    for(int i=1; i<=(target-sum[k-1])/a[k]; i++){
        sol[k]=i;
        sum[k]=sum[k-1]+i*a[k];
        if (k==n){
            if(sum[k]==target)
                res++;
        }
        else{
            Try(k+1);
        }
    }
}
int main(){

    cin >>n>> target;
    res=0;
    for(int i=1; i<=n; i++){
        cin>> a[i];
    }
    Try(1);
    cout<< res;
}
>>>>>>> 2363758 (Initial commit)
