#include <iostream>
#include <vector>
using namespace std;

void subset(vector<int> s, int i, vector<int> sub) {
  if (i == s.size()) {
    for (auto i : sub)
      cout << i << " ";
    cout << endl;
    return;
  }
  sub.push_back(s[i]);
  subset(s, i + 1, sub);
  sub.pop_back();
  subset(s, i + 1, sub);
}
int main() {
  int n;
  cin >> n;
  vector<int> s(n, 0);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  vector<int> sub;
  subset(s, 0, sub);
  return 0;
}
