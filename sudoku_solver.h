// this is a header file for custom implementation of sudoku solver

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
