<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int m, n, p;
int res = INT_MAX;
int X[35];
vector<vector<int>> conflict(35);
vector<vector<int>> courses(35);
vector<vector<int>> teacher(35);

bool check(int x, int k) {
    if (teacher[x].size() + 1 >= res) return false;
    for (int i : teacher[x]) {
        for (int sub : conflict[k]) {
            if (i == sub) return false;
        }
    }
    return true;
}

void thu(int k) {
    if (k > n) {
        int MCV = 0;
        for (int i = 1; i <= m; i++) {
            MCV = max(MCV, (int)teacher[i].size());
        }
        res = min(res, MCV);
        return;
    }

    for (int x : courses[k]) {
        if (check(x, k)) {
            X[k] = x;
            teacher[x].push_back(k);
            thu(k + 1);
            teacher[x].pop_back();
        }
    }
}

int main() {
    cin >> m >> n;
    int numsub;
    int course;

    for (int i = 1; i <= m; i++) {
        cin >> numsub;
        for (int j = 1; j <= numsub; j++) {
            cin >> course;
            courses[course].push_back(i);
        }
    }

    cin >> p;
    int subject1, subject2;
    for (int i = 1; i <= p; i++) {
        cin >> subject1 >> subject2;
        conflict[subject1].push_back(subject2);
        conflict[subject2].push_back(subject1);
    }

    thu(1);
    cout << (res == INT_MAX ? -1 : res);
}
=======
#include<bits/stdc++.h>
using namespace std;

int m, n, p;
int res = INT_MAX;
int X[35];
vector<vector<int>> conflict(35);
vector<vector<int>> courses(35);
vector<vector<int>> teacher(35);

bool check(int x, int k) {
    if (teacher[x].size() + 1 >= res) return false;
    for (int i : teacher[x]) {
        for (int sub : conflict[k]) {
            if (i == sub) return false;
        }
    }
    return true;
}

void thu(int k) {
    if (k > n) {
        int MCV = 0;
        for (int i = 1; i <= m; i++) {
            MCV = max(MCV, (int)teacher[i].size());
        }
        res = min(res, MCV);
        return;
    }

    for (int x : courses[k]) {
        if (check(x, k)) {
            X[k] = x;
            teacher[x].push_back(k);
            thu(k + 1);
            teacher[x].pop_back();
        }
    }
}

int main() {
    cin >> m >> n;
    int numsub;
    int course;

    for (int i = 1; i <= m; i++) {
        cin >> numsub;
        for (int j = 1; j <= numsub; j++) {
            cin >> course;
            courses[course].push_back(i);
        }
    }

    cin >> p;
    int subject1, subject2;
    for (int i = 1; i <= p; i++) {
        cin >> subject1 >> subject2;
        conflict[subject1].push_back(subject2);
        conflict[subject2].push_back(subject1);
    }

    thu(1);
    cout << (res == INT_MAX ? -1 : res);
}
>>>>>>> 2363758 (Initial commit)
