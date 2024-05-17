#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int i, int j) {
  cout << "? " << i+1 << " " << j+1 << endl;
  int ret; cin >> ret;
  return ret;
}

void guess(vector<int>& res) {
  int n = res.size();
  cout << "!";
  for (int i = 0; i < n; i++) {
    cout << " " << res[i];
  }
  cout << endl;
}

pair<int,int> solve(int a, int b) {
  int x = (a+b)/2;
  int y = (b-a)/2;
  return {x,y};
}

void insert(vector<int>& res, int idx, int x) {
  int n = res.size();
  for (int i = n-2; i >= idx; i--) res[i+1] = res[i];
  res[idx] = x; 
}

int main() {
  int n; cin >> n;

  vector<int> inv(n);
  vector<bool> is_higher(n);
  vector<int> res(n); res[0] = 1;
  for (int i = 0; i < n; i++) {
    inv[i] = query(0, i);
    if (i > 0) {
      is_higher[i] = (inv[i] > inv[0]); 
      if (!is_higher[i]) res[0]++;
    }
  }

  vector<int> lo(n,-1), hi(n,-1);

  int lo_count = 0, hi_count = 0;
  for (int i = 1; i < n; i++) {
    int a = inv[i] - inv[0] - hi_count + lo_count - (is_higher[i] ? 1 : -1);
    int b = i-1;

    auto [less, more] = solve(a, b);
    if (is_higher[i]) insert(hi, more, i);
    else insert(lo, less, i);

    lo_count += !is_higher[i];
    hi_count += is_higher[i]; 
  }

  int tmp = 1;
  for (int i = 0; i < n && lo[i] >= 0; i++) res[lo[i]] = tmp++;

  tmp = n;
  for (int i = 0; i < n && hi[i] >= 0; i++) res[hi[i]] = tmp--;
  
  guess(res);
}
