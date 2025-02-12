// #include <bits/stdc++.h>
// using namespace std;

// int n, c, k;
// int number[100005];
// int max_dis[1005][100005];

// int main(){
    
    // ios_base:: sync_with_stdio;
    // cin.tie(0);
    // cout.tie(0);
//     cin>>k;
//     for(int test = 0; test<k; test++){

//         cin >> n >> c;
//         for (int i=0; i<n; i++){
//             cin >> number[i];
//         }

//         sort(number, number+n);

//         for(int i=0; i<n; i++){
//             max_dis[2][i] = number[i]-number[0];
//         }

//         for(int i=3; i<=c; i++){
//             for(int j=i; j<n; j++){
//                 max_dis[i][j]= 0;
//                 for (int k=0; k<j; k++){
//                     int tmp = min(number[j]-number[k], max_dis[i-1][k]);
//                     max_dis[i][j] = max(max_dis[i][j], tmp);
//                 }
//             }
//         }
//         cout<<max_dis[c][n-1]<<"\n";
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int n , c, k;
int num[1000005];

int check(int d){
    int tmp = num[0];
    int count = 0;
    for(int i=0; i<n; i++){
        if (num[i]>=tmp){
            tmp=num[i]+d;
            count++;
        }
        if (count>=c){
            return true;
        }
    }
    return false;
};

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    for(int test = 0; test<k; test++){
        cin >> n >> c;
        for(int i=0; i<n; i++){
            cin >> num[i];
        }

        sort(num, num+n);
        int l=0;
        int r=(num[n-1]-num[0])/(c-1);
        int d;
        while(l<=r){
            d = (r+l)/2;
            if (check(d)){
                l=d+1;
            }
            else{
                r=d-1;
            }
        }
        cout<<r<<"\n";
    }
    
}