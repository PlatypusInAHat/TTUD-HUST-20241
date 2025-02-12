<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int n;
int k1, k2;
int work[1005];
int rest[1005];

int main(){
    cin>>n>>k1>>k2;
    
    rest[0]=1;
    work[0]=0;

    for(int i=1; i<k1-1; i++){
        work[i]=0;
        rest[i]=0;
    }

    work[k1-1]=1;
    rest[k1-1] = 0;

    for(int i=k1; i<n; i++){
        rest[i]=work[i-1];
        for(int j=k1; j<= k2; j++){
            if(i-j>=0)
                work[i]+=rest[i-j];
            else
            {
                work[i]++;
                break;
            }
        }
    }
    cout<<rest[n-1]+work[n-1];
=======
#include<bits/stdc++.h>
using namespace std;

int n;
int k1, k2;
int work[1005];
int rest[1005];

int main(){
    cin>>n>>k1>>k2;
    
    rest[0]=1;
    work[0]=0;

    for(int i=1; i<k1-1; i++){
        work[i]=0;
        rest[i]=0;
    }

    work[k1-1]=1;
    rest[k1-1] = 0;

    for(int i=k1; i<n; i++){
        rest[i]=work[i-1];
        for(int j=k1; j<= k2; j++){
            if(i-j>=0)
                work[i]+=rest[i-j];
            else
            {
                work[i]++;
                break;
            }
        }
    }
    cout<<rest[n-1]+work[n-1];
>>>>>>> 2363758 (Initial commit)
}