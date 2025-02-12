<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[1000005];
long long odd[1000005];
long long even[10000005];

int main(){
    cin >> n;
    long long res = 0;
    long long p = 0;
    for (long long i=0; i<n; i++){
        cin >> a[i];
    }
    if(a[0]%2==0){
        even[0]=a[0];
    }
    else{
        odd[0]=a[0];
    }

    for (long long i=1; i<n; i++){
        if (a[i]%2==0){
    
            even[i] = max(even[i-1], p) + a[i];

            if (odd[i-1]==0){
                odd[i] = 0;
            }
            else{
                odd[i] = odd[i-1]+a[i];
            }
        }
        
        else{
            if(odd[i-1]==0){
                even[i]=0;
            }
            else{
                even[i] = odd[i-1]+a[i];
            }

            odd[i]=max(even[i-1],p)+a[i];
        }
        res = max(res, odd[i]);
    }
    cout<<res;
=======
#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[1000005];
long long odd[1000005];
long long even[10000005];

int main(){
    cin >> n;
    long long res = 0;
    long long p = 0;
    for (long long i=0; i<n; i++){
        cin >> a[i];
    }
    if(a[0]%2==0){
        even[0]=a[0];
    }
    else{
        odd[0]=a[0];
    }

    for (long long i=1; i<n; i++){
        if (a[i]%2==0){
    
            even[i] = max(even[i-1], p) + a[i];

            if (odd[i-1]==0){
                odd[i] = 0;
            }
            else{
                odd[i] = odd[i-1]+a[i];
            }
        }
        
        else{
            if(odd[i-1]==0){
                even[i]=0;
            }
            else{
                even[i] = odd[i-1]+a[i];
            }

            odd[i]=max(even[i-1],p)+a[i];
        }
        res = max(res, odd[i]);
    }
    cout<<res;
>>>>>>> 2363758 (Initial commit)
}