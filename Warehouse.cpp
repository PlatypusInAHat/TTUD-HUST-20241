<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int n, T ,d;
int a[10001];
int t[10001];
int dp[1001][1001];
int res = 0;

int main(){
    cin >> n >> T >> d;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        cin >> t[i];
    }

    for (int i=0; i<n; i++){
        for(int j=1; j<=T; j++){
            for(int k=1; k<=d; k++){
                if (j>=t[i])
                    dp[i][j] = max(dp[i][j], dp[i-k][j-t[i]]+a[i]);
            }
            res = max(res, dp[i][j]);
            
        }
    }
    cout<<res;
=======
#include<bits/stdc++.h>
using namespace std;

int n, T ,d;
int a[10001];
int t[10001];
int dp[1001][1001];
int res = 0;

int main(){
    cin >> n >> T >> d;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        cin >> t[i];
    }

    for (int i=0; i<n; i++){
        for(int j=1; j<=T; j++){
            for(int k=1; k<=d; k++){
                if (j>=t[i])
                    dp[i][j] = max(dp[i][j], dp[i-k][j-t[i]]+a[i]);
            }
            res = max(res, dp[i][j]);
            
        }
    }
    cout<<res;
>>>>>>> 2363758 (Initial commit)
}