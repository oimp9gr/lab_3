#pragma once

std::string TicTacToeResult(std::vector<std::vector<char>> board) {
    // check rows
    for (size_t i = 0; i < 3; ++i) {
        size_t tic_count = 0;
        size_t tac_count = 0;
        for (size_t j = 0; j < 3; ++j) {
            if (board[i][j] == 'X') {
                tic_count++;
            } else if (board[i][j] == 'O') {
                tac_count++;
            }
        }
        if (tic_count == 3) return "X";
        if (tac_count == 3) return "O";
    }
    // check columns
    for (size_t i = 0; i < 3; ++i) {
        size_t tic_count = 0;
        size_t tac_count = 0;
        for (size_t j = 0; j < 3; ++j) {
            if (board[j][i] == 'X') {
                tic_count++;
            } else if (board[j][i] == 'O') {
                tac_count++;
            }
        }
        if (tic_count == 3) return "X";
        if (tac_count == 3) return "O";
    }
    // check diagonals
    size_t tic_count = 0;
    size_t tac_count = 0;
    for (size_t i = 0; i < 3; ++i) {
        if (board[i][i] == 'X') {
            tic_count++;
        } else if (board[i][i] == 'O') {
            tac_count++;
        }
    }
    if (tic_count == 3) return "X";
    if (tac_count == 3) return "O";
    tic_count = 0;
    tac_count = 0;
    for (size_t i = 0; i < 3; ++i) {
        if (board[i][2 - i] == 'X') {
            tic_count++;
        } else if (board[i][2 - i] == 'O') {
            tac_count++;
        }
    }
    if (tic_count == 3) return "X";
    if (tac_count == 3) return "O";
    return "Tie";
}