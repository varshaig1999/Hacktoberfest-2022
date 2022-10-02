// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The EMPTY_CELL character indicates an initial empty cell.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
#define EMPTY_CELL '.'
using namespace std;

bool isSafe(int r, int c, char num, vector<vector<char>> &board)
{
    // Row[r] has num
    for (int i = 0; i < 9; i++)
    {
        if (board[r][i] == num)
            return false;
    }

    // Col[c] has num
    for (int i = 0; i < 9; i++)
    {
        if (board[i][c] == num)
            return false;
    }

    // Square has num 0(0,0),1(0,3),2(0,6),3(3,0),4(3,3),5(3,6),..
    int startcellX = (r / 3) * 3, startcellY = (c / 3) * 3; // (5,4) = 2 will be in square(3,3)

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startcellX + i][startcellY + j] == num)
                return false;
        }
    }

    return true;
}

bool solve(int cellNum, vector<vector<char>> &board)
{

    // Base Case -> All cells filled already
    if (cellNum == 81)
        return true;

    int r = cellNum / 9, c = cellNum % 9;

    // Base Case -> Cell already filled
    if (board[r][c] != EMPTY_CELL)
        return solve(cellNum + 1, board);

    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(r, c, '0' + i, board))
        {
            board[r][c] = '0' + i;

            if (solve(cellNum + 1, board))
                return true;
            else
            {
                board[r][c] = EMPTY_CELL;
            }
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    if (solve(0, board))
    {
        // Print Board
        cout << "\nSolved Board :\n";
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";

                if (j == 2 || j == 5)
                    cout << " ";
            }
            cout << endl;

            if (i == 2 || i == 5)
                cout << endl;
        }
    }
    else
    {
        cout << "NOT BE SOLVED !!" << endl;
    }
}
void solve(vector<int> &candidates, int index, int target, vector<int> &curstate, vector<vector<int>> &ans)
{
    // if target 0
    if (target == 0)
    {
        ans.push_back(curstate);
        return;
    }

    // if candidates size 0
    if (candidates.empty())
    {
        return;
    }

    // if candidates still left to see
    int cur = candidates[index];

    if (target >= cur)
    {
        // with top elem
        curstate.push_back(cur);
        solve(candidates, index, target - cur, curstate, ans);
        curstate.pop_back();
    }
    // without top element
    solve(candidates, index + 1, target, curstate, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> curstate;

    sort(candidates.begin(), candidates.end());

    solve(candidates, 0, target, curstate, ans);
    return ans;
}
int main()
{
    vvc board(9, vector<char>(9, EMPTY_CELL)); // empty 9*9 Sudoku board

    cout << "Enter the Puzzle Board:" << endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    }
    solveSudoku(board);
    vector<int> c({2, 3, 5, 7});
    vector<vector<int>> ans = combinationSum(c, 7);
    cout << ans.size() << endl;

    return 0;
}

/*
Example Inputs
--------------------------------

___EASY___
53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79

___DIFFICULT___
...6..4..
7....36..
....91.8.
.........
.5.18...3
...3.6.45
.4.2...6.
9.3......
.2....1..

*/