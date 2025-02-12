<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int rectangle[15][15];
pair<int, int> material[15];
pair<int, int> locate[15];
int H, W, n;
int res = 0;

bool check(int k, int x, int y, int p){
    int h, w;
    if (p==0){
        h=material[k].first;
        w=material[k].second;
    }
    else{
        w=material[k].first;
        h=material[k].second;
    }
    if(x+h>H || y+w>W){
        return false;
    }
    for (int i=x; i<x+h; i++ ){
        for (int j=y; j<y+w; j++){
            if (rectangle[i][j]==1)
                return false;
        }
    }
    return true;
}

void marked(int k, int x, int y, int p){
    int h, w;
    if (p==0){
        h=material[k].first;
        w=material[k].second;
    }
    else{
        w=material[k].first;
        h=material[k].second;
    }
    for (int i=x; i<x+h; i++ ){
        for (int j=y; j<y+w; j++){
            rectangle[i][j]=1;
        }
    }
}

void unmarked(int k, int x, int y, int p){
    int h, w;
    if (p==0){
        h=material[k].first;
        w=material[k].second;
    }
    else{
        w=material[k].first;
        h=material[k].second;
    }
    for (int i=x; i<x+h; i++ ){
        for (int j=y; j<y+w; j++){
            rectangle[i][j]=0;
        }
    }
}

void Try(int k){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            for (int p=0; p<2; p++){
                if (check(k ,i, j, p)){
                    marked(k, i, j, p);
                    locate[k].first=i;
                    locate[k].second=j;
                    
                    if(k==n-1){
                        res = 1;
                        return;
                    }
                    else{
                        Try(k+1);
                    }
                    unmarked(k, i, j, p);
                }
            }
        }
    }
}

int main(){
    cin >> H >> W;
    cin >> n;
    for(int i=0; i<n ; i++){
        cin >> material[i].first >> material[i].second;
    }
    Try(0);
    cout<<res;
=======
#include<bits/stdc++.h>
using namespace std;

int rectangle[15][15];
pair<int, int> material[15];
pair<int, int> locate[15];
int H, W, n;
int res = 0;

bool check(int k, int x, int y, int p){
    int h, w;
    if (p==0){
        h=material[k].first;
        w=material[k].second;
    }
    else{
        w=material[k].first;
        h=material[k].second;
    }
    if(x+h>H || y+w>W){
        return false;
    }
    for (int i=x; i<x+h; i++ ){
        for (int j=y; j<y+w; j++){
            if (rectangle[i][j]==1)
                return false;
        }
    }
    return true;
}

void marked(int k, int x, int y, int p){
    int h, w;
    if (p==0){
        h=material[k].first;
        w=material[k].second;
    }
    else{
        w=material[k].first;
        h=material[k].second;
    }
    for (int i=x; i<x+h; i++ ){
        for (int j=y; j<y+w; j++){
            rectangle[i][j]=1;
        }
    }
}

void unmarked(int k, int x, int y, int p){
    int h, w;
    if (p==0){
        h=material[k].first;
        w=material[k].second;
    }
    else{
        w=material[k].first;
        h=material[k].second;
    }
    for (int i=x; i<x+h; i++ ){
        for (int j=y; j<y+w; j++){
            rectangle[i][j]=0;
        }
    }
}

void Try(int k){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            for (int p=0; p<2; p++){
                if (check(k ,i, j, p)){
                    marked(k, i, j, p);
                    locate[k].first=i;
                    locate[k].second=j;
                    
                    if(k==n-1){
                        res = 1;
                        return;
                    }
                    else{
                        Try(k+1);
                    }
                    unmarked(k, i, j, p);
                }
            }
        }
    }
}

int main(){
    cin >> H >> W;
    cin >> n;
    for(int i=0; i<n ; i++){
        cin >> material[i].first >> material[i].second;
    }
    Try(0);
    cout<<res;
>>>>>>> 2363758 (Initial commit)
}