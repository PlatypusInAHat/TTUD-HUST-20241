#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
struct Edge {
    int node, w;
    Edge(int _node, int _w): node(_node), w(_w) {}
};

int n;
vector<Edge> A[N];
int root;
int d[N];  // d[u]: tổng trọng số của các đoạn đường từ các đỉnh con đến u
int num[N]; // num[u]: số lượng đỉnh con của u, bao gồm cả chính u
int f[N]; // f[u]: tổng trọng số của các đoạn đường từ các đỉnh ngoài cây con của u tới u
int p[N]; // p[u]: cha của đỉnh u

// Hàm nhập dữ liệu
void input() {
    cin >> n;
    for (int k = 1; k <= n - 1; k++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Edge(v, w));
        A[v].push_back(Edge(u, w));
    }
}

// Giai đoạn 1: Tính d[u] và num[u] cho tất cả các đỉnh
void dfs1(int u) {
    for (int i = 0; i < A[u].size(); i++) {
        Edge e = A[u][i];
        int v = e.node;
        int w = e.w;
        if (p[v] == 0) {  // Nếu v chưa được thăm
            p[v] = u;
            dfs1(v);
            d[u] = d[u] + d[v] + num[v] * w; // Cập nhật d[u]
            num[u] += num[v]; // Cập nhật num[u]
        }
    }
}

// Giai đoạn 2: Tính f[u] cho tất cả các đỉnh
void dfs2(int u) {
    for (int i = 0; i < A[u].size(); i++) {
        Edge e = A[u][i];
        int v = e.node;
        int w = e.w;
        if (p[v] == 0) {  // Nếu v chưa được thăm
            int F = f[u] - (d[v] + w * num[v]); // Tính giá trị F
            f[v] = F + d[v] + w * (n - num[v]); // Tính f[v]
            p[v] = u;
            dfs2(v);  // Tiếp tục DFS cho các đỉnh con của u
        }
    }
}

// Giai đoạn 1: Khởi tạo và thực hiện DFS1 từ gốc
void solvePhase1() {
    for (int v = 1; v <= n; v++) {
        p[v] = 0;
        d[v] = 0;
        num[v] = 1;
        f[v] = 0;
    }
    root = 1;
    p[root] = root;
    dfs1(root);
}

// Giai đoạn 2: Tính f[u] và tìm giá trị lớn nhất
void solvePhase2() {
    for (int v = 1; v <= n; v++) {
        p[v] = 0;
    }
    root = 1;
    f[root] = d[root];
    p[root] = root;
    dfs2(root);

    int ans = 0;
    for (int v = 1; v <= n; v++) {
        ans = max(ans, f[v]);  // Tìm giá trị lớn nhất của f[v]
    }

    cout << ans;  // In kết quả
}

int main() {
    input();  // Nhập dữ liệu
    solvePhase1();  // Thực hiện giai đoạn 1
    solvePhase2();  // Thực hiện giai đoạn 2
    return 0;
}
