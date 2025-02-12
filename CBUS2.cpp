#include<bits/stdc++.h
using namespace std;

int c[30][30];
int n, k;
int A[30];
int mark[30]={};
int inTrip[30]={};
int place=0;
int curr =0 ;
int best= INT_MAX;

bool check(int x)
{
    if(curr>best)
        return false;
    if (mark[x]==0)
    {
        if (x>n)
        {
            if (inTrip[x-n]==1)
                return true;
            } else {
            if (inTrip[x]==0 &&place<k)
                return true;
            }
    }
    return false;
}
void check(int k)
{
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
                inTrip[i]=1;
            }
            else{
                place--;
                inBus[i]=0;
            }
        }
    }
}
