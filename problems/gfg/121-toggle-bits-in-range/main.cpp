#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  --l;
  r;

  int msk = ((1 << r) - 1) ^ ((1 << l) - 1);
  int res = n ^ msk;
  cout << res << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}