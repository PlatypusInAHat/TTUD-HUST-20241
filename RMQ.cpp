<<<<<<< HEAD
#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

#define MAX 1000005
int a[MAX];
int st[22][MAX];

void input(int n){
	for (int i=0; i<n; i++)
		cin>> a[i];
}

void create(int n){
	int lg=log2(n)+1;
	for (int i=0; i<n; i++)
		st[0][i]=a[i];
	for (int j=1; j<lg; j++){
		for (int i=0; i+(1<<j)-1<n; i++){
			st[j][i]=min(st[j-1][i], st[j-1][i+(1<<(j-1))]);
		}
	}
}

int query(int l, int r){
	int k=log2(r-l+1);
	return min(st[k][l], st[k][r-(1<<k)+1]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	input(n);
	create(n);
	
	int k;
	cin >> k;
	int res=0;
	for(int i=0; i<k; i++){
		int l, r;
		cin >> l>> r;
		res=res+query(l,r);
	}
	cout<< res;

=======
#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

#define MAX 1000005
int a[MAX];
int st[22][MAX];

void input(int n){
	for (int i=0; i<n; i++)
		cin>> a[i];
}

void create(int n){
	int lg=log2(n)+1;
	for (int i=0; i<n; i++)
		st[0][i]=a[i];
	for (int j=1; j<lg; j++){
		for (int i=0; i+(1<<j)-1<n; i++){
			st[j][i]=min(st[j-1][i], st[j-1][i+(1<<(j-1))]);
		}
	}
}

int query(int l, int r){
	int k=log2(r-l+1);
	return min(st[k][l], st[k][r-(1<<k)+1]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	input(n);
	create(n);
	
	int k;
	cin >> k;
	int res=0;
	for(int i=0; i<k; i++){
		int l, r;
		cin >> l>> r;
		res=res+query(l,r);
	}
	cout<< res;

>>>>>>> 2363758 (Initial commit)
}