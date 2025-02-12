#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// Định nghĩa một đồ thị dưới dạng danh sách cạnh
using Graph = vector<vector<int>>;

// Hàm kiểm tra xem đồ thị có chính quy hay không
bool isRegularGraph(const Graph& graph) {
    int degree = graph[1].size();
    for (int i = 2; i < graph.size(); ++i) {
        if (graph[i].size() != degree) {
            return false;
        }
    }
    return true;
}

// Hàm tô màu đồ thị
void colorGraph(const Graph& graph, int k) {
    vector<int> colors(graph.size(), -1); // Mảng lưu màu cho từng đỉnh

    // Hàm kiểm tra xem một màu có thể sử dụng cho đỉnh hay không
    auto isColorAvailable = [&](int vertex, int color) {
        for (int neighbor : graph[vertex]) {
            if (colors[neighbor] == color) {
                return false;
            }
        }
        return true;
    };

    queue<int> q;
    q.push(1); // Bắt đầu từ đỉnh 1

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        unordered_set<int> usedColors; // Các màu đã được sử dụng bởi các đỉnh kề

        for (int neighbor : graph[vertex]) {
            if (colors[neighbor] != -1) {
                usedColors.insert(colors[neighbor]);
            }
        }

        for (int color = 1; color <= k; ++color) {
            if (!usedColors.count(color)) {
                colors[vertex] = color;
                break;
            }
        }

        for (int neighbor : graph[vertex]) {
            if (colors[neighbor] == -1) {
                q.push(neighbor);
            }
        }
    }

    // Hiển thị đồ thị đã tô màu
    cout << "graph {" << endl;
    for (int vertex = 1; vertex < graph.size(); ++vertex) {
        cout << vertex << " [fillcolor=";
        if (colors[vertex] != -1) {
            cout << "\"" << colors[vertex] << "\", ";
        }
        else {
            cout << "white, ";
        }
        cout << "style=filled];" << endl;
    }

    for (int vertex = 1; vertex < graph.size(); ++vertex) {
        for (int neighbor : graph[vertex]) {
            if (vertex < neighbor) { // Tránh hiển thị cạnh trùng lặp
                cout << vertex << " -- " << neighbor << ";" << endl;
            }
        }
    }

    cout << "}" << endl;
}

int main() {
    int n, m;
    cout << "Nhap so dinh va so canh cua do thi: ";
    cin >> n >> m;

    Graph graph(n + 1); // Đánh số đỉnh từ 1 đến n

    cout << "Nhap cac canh cua do thi:" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int k;
    if (isRegularGraph(graph)) {
        k = graph[1].size() + 1; // Số màu không vượt quá số lượng đỉnh kề lớn nhất + 1
    }
    else {
        k = graph.size() - 1; // Số màu không vượt quá số lượng đỉnh
    }

    colorGraph(graph, k);

    return 0;
}

