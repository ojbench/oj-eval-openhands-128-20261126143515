#include <iostream>
using namespace std;

int main() {
    char b[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];
        }
    }

    int xCount = 0, oCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j] == 'x') xCount++;
            else if (b[i][j] == 'o') oCount++;
        }
    }

    // Check all 8 possible winning lines
    bool xWins = false, oWins = false;

    // Rows
    for (int i = 0; i < 3; i++) {
        if (b[i][0] != '-' && b[i][0] == b[i][1] && b[i][1] == b[i][2]) {
            if (b[i][0] == 'x') xWins = true;
            else oWins = true;
        }
    }

    // Columns
    for (int j = 0; j < 3; j++) {
        if (b[0][j] != '-' && b[0][j] == b[1][j] && b[1][j] == b[2][j]) {
            if (b[0][j] == 'x') xWins = true;
            else oWins = true;
        }
    }

    // Diagonals
    if (b[0][0] != '-' && b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == 'x') xWins = true;
        else oWins = true;
    }
    if (b[0][2] != '-' && b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == 'x') xWins = true;
        else oWins = true;
    }

    // Validation checks
    // Rule 1: x goes first, so xCount == oCount or xCount == oCount + 1
    if (xCount != oCount && xCount != oCount + 1) {
        cout << "invalid" << endl;
        return 0;
    }

    // Rule 2: Both can't win
    if (xWins && oWins) {
        cout << "invalid" << endl;
        return 0;
    }

    // Rule 3: If x wins, x must have played last (xCount == oCount + 1)
    if (xWins && xCount != oCount + 1) {
        cout << "invalid" << endl;
        return 0;
    }

    // Rule 4: If o wins, counts must be equal
    if (oWins && xCount != oCount) {
        cout << "invalid" << endl;
        return 0;
    }

    // Output results
    if (xWins) {
        cout << "win" << endl;
    } else if (oWins) {
        cout << "lose" << endl;
    } else {
        // No winner - check if board is full
        if (xCount + oCount == 9) {
            cout << "tie" << endl;
        } else {
            cout << "ongoing" << endl;
        }
    }

    return 0;
}
