#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<bool> contains_triple(1<<n);
  for (int i = 0; i < n; i++) 
    for (int j = i+1; j < n; j++) 
      for (int k = j+1; k < n; k++)
        if ((a[i]^a[j]^a[k]) == 0)
          contains_triple[(1<<i)|(1<<j)|(1<<k)] = true;

  // mark all subsets that contain triples
  for (int mask = 0; mask < (1<<n); mask++)
    if (contains_triple[mask])
      for (int i = 0; i < n; i++)
        contains_triple[mask|(1<<i)] = true;

  // in the largest subset that does not contain a triple,
  // the answer is the number of people not in the subset
  int ans = 30;
  for (int mask = 0; mask < (1<<n); mask++) 
    if (!contains_triple[mask]) 
      ans = min(ans, n - __builtin_popcount(mask));
  
  cout << ans << "\n";

  return 0;
}