#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<bool>> chess, int i, int j) {
  for (int k = 0; k < chess.size(); k++)
    if (chess[i][k] || chess[k][j] ||
        (i - k >= 0 && j + k < chess.size() && chess[i - k][j + k]) ||
        (i + k < chess.size() && j + k < chess.size() && chess[i + k][j + k]) ||
        (i - k >= 0 && j - k >= 0 && chess[i - k][j - k]) ||
        (j - k >= 0 && i + k < chess.size() && chess[i + k][j - k]))
      return false;
  return true;
}
void search(vector<vector<bool>> chess, int q, int &ways) {
  if (q == chess.size()) {
    ways++;
    return;
  }
  for (int i = 0; i < chess.size(); i++) {
    if (check(chess, q, i)) {
      chess[q][i] = true;
      search(chess, q + 1, ways);
      chess[q][i] = false;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<bool> i(n, false);
  vector<vector<bool>> chess(n, i);
  int ways;
  search(chess, 0, ways);
  cout << ways << endl;
  return 0;
}

