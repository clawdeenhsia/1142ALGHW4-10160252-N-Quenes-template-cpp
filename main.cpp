#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// c[i] 表示第 i 欄皇后所在列
// 這裡使用 1-based index，方便對照題目
vector<int> c;

// 儲存所有解
vector<vector<int>> solutions;

// ==============================
// 檢查第 i 欄放在 row 是否合法
// ==============================

bool isSafe(int i, int row) {
    for (int j = 1; j <= i - 1; j++) {
        if (c[j] == row || abs(c[j] - row) == abs(j - i)) {
            return false;
        }
    }

    return true;
}    
    // TODO:
    // 檢查是否和前面 1 ~ i-1 欄的皇后衝突
    //
    // 衝突條件：
    // 1. 同一列：c[j] == row
    // 2. 同一對角線：abs(c[j] - row) == abs(j - i)
    //
    // 若無衝突，回傳 true
    // 否則回傳 false

    return true; // 請修改
}

// ==============================
// 回溯法
// i 表示目前要放第 i 欄皇后
// ==============================

void backtrack(int i, int n) {
    if (i > n) {
        solutions.push_back(c);
        return;
    }

    for (int row = 1; row <= n; row++) {
        if (isSafe(i, row)) {
            c[i] = row;
            backtrack(i + 1, n);
        }
    }
}
    // TODO:
    // 若 i > n，表示找到一組完整解
    // 1. 將 c[1..n] 存入 solutions
    // 2. return

    // TODO:
    // 對 row = 1 到 n 逐一嘗試
    // 若 isSafe(i, row) 為 true：
    //   1. 設 c[i] = row
    //   2. 遞迴呼叫 backtrack(i + 1, n)
}

// ==============================
// 印出單一解
// ==============================
void printSolution(const vector<int>& sol) {
    cout << "[";
    for (int i = 1; i < (int)sol.size(); i++) {
        cout << sol[i];
        if (i != (int)sol.size() - 1) cout << ", ";
    }
    cout << "]";
}

// ==============================
// 印出棋盤
// ==============================
void printBoard(const vector<int>& sol) {
    int n = sol.size() - 1;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            if (sol[col] == row) {
    cout << "Q ";
} else {
    cout << ". ";
}
            // TODO:
            // 若第 col 欄皇后在第 row 列，印 "Q "
            // 否則印 ". "
        }
        cout << "\n";
    }
}

// ==============================
// 執行 n-Queens
// ==============================
void solveNQueens(int n) {
    c.assign(n + 1, 0);
    solutions.clear();

    // TODO:
    // 從第 1 欄開始回溯
    backtrack(1, n);

    cout << "n = " << n << "\n";
    cout << "Total solutions = " << solutions.size() << "\n";

    // 印前兩個解
    if (!solutions.empty()) {
        cout << "First solution: ";
        // TODO:
        printSolution(solutions[0]);
        cout << "\n";
    }

    if (solutions.size() >= 2) {
        cout << "Second solution: ";
        // TODO:
        printSolution(solutions[1]);
        cout << "\n";
    }

    // n = 8 時印出至少一組棋盤
    if (n == 8 && !solutions.empty()) {
        cout << "\nOne board for n = 8:\n";
        // TODO:
        printBoard(solutions[0]);
    }

    cout << "\n";
}

// ==============================
// 主程式
// ==============================
int main() {
    // 測試 n = 6
    solveNQueens(6);

    // 測試 n = 7
    solveNQueens(7);

    // 測試 n = 8
    solveNQueens(8);

    return 0;
}
