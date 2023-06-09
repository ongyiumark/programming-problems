#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5e5+5;
int b[N];

const int M = 5e6+5;
int sieve[M];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(sieve, 0, sizeof sieve);

  int n; cin >> n;
  int m = 0;

  map<int,int> freq;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    freq[b[i]] += 1;

    m = max(b[i], m);
  }

  for (auto [key, val] : freq) {
    for (int j = 1; j*key <= m; j++) {
      sieve[j*key] += val;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << sieve[b[i]]-1;
    if (i+1 < n) cout << " ";
    else cout << "\n";
  }

  
  return 0;
}
