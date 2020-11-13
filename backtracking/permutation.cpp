#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int> s, int i, int l, vector<int> p, vector<bool> c) {
  if (i == l) {
    for (auto j : p)
      cout << j << " ";
    cout << endl;
  }
  for (int k = 0; k < s.size(); k++) {
    if (c[k])
      continue;
    c[k] = true;
    p.push_back(s[k]);
    permutation(s, i + 1, l, p, c);
    c[k] = false;
    p.pop_back();
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> numbers(n, 0);
  for (int i = 0; i < n; i++)
    cin >> numbers[i];
  vector<int> p;
  vector<bool> c(n, false);
  permutation(numbers, 0, k, p, c);
  return 0;
}
