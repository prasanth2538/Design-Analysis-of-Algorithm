#include <stdio.h>

void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int m = boardSize;
    int n = *boardColSize;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;
            for (int k = 0; k < 8; k++) {
                int ni = i + directions[k][0];
                int nj = j + directions[k][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && (board[ni][nj] & 1)) {
                    liveNeighbors++;
                }
            }

            if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                board[i][j] = 3; 
            } else if (board[i][j] == 0 && liveNeighbors == 3) {
                board[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] >>= 1;
        }
    }
}

int main() {
    int board[][3] = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    int boardSize = sizeof(board) / sizeof(board[0]);
    int boardColSize = sizeof(board[0]) / sizeof(board[0][0]);

    gameOfLife((int**)board, boardSize, &boardColSize);

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
