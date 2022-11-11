// an example test run of sudoku solver algorithm

#include <algorithm>
#include <cstdio>
#include <cassert>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <climits> 
#include <stack>

using namespace std;

struct sudoku_solver {
    vector<vector<int>> board;

    sudoku_solver(vector<vector<int>> inp) {
        board = inp;
    }

    bool solve() {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[i][j] == 0) {
                    for(int x = 1; x <= 9; x++) {
                        if (is_valid(i, j, x)) {
                            board[i][j] = x;
                            if (solve() == true) {
                                return true;
                            }
                            board[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool is_valid(int r, int c, int x) {
        for(int i = 0; i < 9; i++) {
            if (board[i][c] == x) {
                return false;
            }
            if (board[r][i] == x) {
                return false;
            }
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == x) {
                return false;
            }
        }
        return true;
    }

    void display() {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << '\n';
        }
    }
};


void solve() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    sudoku_solver engine(board);
    if (engine.solve()) {
        cout << "SOLVED\n";
        engine.display();
    }
    else {
        cout << "INVALID\n";
    }
}



int main() {
    #ifdef devansh_local
        auto begin = std::chrono::high_resolution_clock::now();
    #endif

    solve();

    #ifdef devansh_local
        auto end = std::chrono::high_resolution_clock::now();
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms" << endl;
	#endif

    return 0;
}

