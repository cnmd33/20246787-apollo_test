#include <iostream>
#include <vector>
#include "solution.h"

void Solution::solve(std::vector<std::vector<char>>& board) {
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();

    auto dfs = [&](int x, int y, auto&& dfs) -> void {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != '0') return;
        board[x][y] = '1';
        dfs(x + 1, y, dfs);
        dfs(x - 1, y, dfs);
        dfs(x, y + 1, dfs);
        dfs(x, y - 1, dfs);
    };

    for (int i = 0; i < m; ++i) {
        dfs(i, 0, dfs);
        dfs(i, n - 1, dfs);
    }
    for (int j = 0; j < n; ++j) {
        dfs(0, j, dfs);
        dfs(m - 1, j, dfs);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '0') board[i][j] = 'X';
            if (board[i][j] == '1') board[i][j] = '0';
        }
    }
}

int main() {
    int m, n;

    std::cout << "示例:" << std::endl;
    std::cout << "（这个不用管就直接输入如左回车即可）4 4 (行数 列数)" << std::endl;
    std::cout << "x x x x" << std::endl;
    std::cout << "x 0 0 x" << std::endl;
    std::cout << "x x 0 x" << std::endl;
    std::cout << "x 0 x x" << std::endl;
    std::cout << "输入:board = [['x','x','x','x'],['x','0','0','x'],['x','x','0','x'],['x','0','x','x']]" << std::endl;
    std::cout << "输出:board = [['x','x','x','x'],['x','X','X','x'],['x','x','X','x'],['x','0','x','x']]" << std::endl;
    

    std::cin >> m >> n;

    std::vector<std::vector<char>> board(m, std::vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> board[i][j];
        }
    }

    std::cout << "输入:board = [";
    for (int i = 0; i < m; ++i) {
        std::cout << "[";
        for (int j = 0; j < n; ++j) {
            std::cout << "'" << board[i][j] << "'";
            if (j < n - 1) std::cout << ",";
        }
        std::cout << "]";
        if (i < m - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;

    Solution solution;
    solution.solve(board);

    std::cout << "输出:board = [";
    for (int i = 0; i < m; ++i) {
        std::cout << "[";
        for (int j = 0; j < n; ++j) {
            std::cout << "'" << board[i][j] << "'";
            if (j < n - 1) std::cout << ",";
        }
        std::cout << "]";
        if (i < m - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;

    return 0;
}
