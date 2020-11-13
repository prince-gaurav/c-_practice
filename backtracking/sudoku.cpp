#include <cmath>
#include <iostream>
#include <vector>

#define sq(x) (x) * (x)
#define root(x) (int)(sqrt(x))
using namespace std;

bool check(vector<vector<int>> sudoku, int i, int j, int k) {
  int n = sudoku.size();
  int s = root(n);
  for (int z = 0; z < n; z++) {
    if (sudoku[i][z] == k || sudoku[z][j] == k ||
        sudoku[i / s * s + z / s][j / s * s + z % s] == k)
      return false;
  }
  return true;
}
bool solve(vector<vector<int>> &sudoku, int i, int j) {
  int n = sudoku.size();
  if (i == n) {
    return true;
  }
  if (sudoku[i][j])
    return solve(sudoku, j == n - 1 ? i + 1 : i, j == n - 1 ? 0 : j + 1);
  for (int k = 1; k <= n; k++) {
    if (check(sudoku, i, j, k)) {
      sudoku[i][j] = k;
      if (solve(sudoku, j == n - 1 ? i + 1 : i, j == n - 1 ? 0 : j + 1))
        return true;
      sudoku[i][j] = 0;
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  if (sq(root(n)) != n) {
    cout << "Bad Input1" << endl;
    return -1;
  }
  vector<int> i(n, 0);
  vector<vector<int>> sudoku(n, i);
  int readInp;
  cout << "Wanna Input?(0 for no, non-zero for yes)" << endl;
  cin >> readInp;
  if (readInp)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) {
        cin >> sudoku[j][k];
        if (sudoku[j][k] > n) {
          cout << "Bad Input2" << endl;
          return -2;
        }
      }
  if (solve(sudoku, 0, 0)) {
    cout << "Solution Found" << endl;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++)
        cout << sudoku[j][k] << " ";
      cout << endl;
    }
  } else {
    cout << "Solution Not Found" << endl;
  }
  return 0;
}

