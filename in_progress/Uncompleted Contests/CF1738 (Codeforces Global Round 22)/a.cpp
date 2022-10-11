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


const int N = 1e5+5;
bool a[N];
ll b[N];
int n;
void testcase() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  vector<ll> frost, fire;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) fire.push_back(b[i]);
    else frost.push_back(b[i]);
  }
  
  sort(fire.begin(), fire.end(), greater<ll>());
  sort(frost.begin(), frost.end(), greater<ll>());

  int firesz = fire.size();
  int frostsz = frost.size();

  ll total = 0;
  for (int i = 0; i < max(firesz, frostsz); i++) {
    if (i >= min(firesz, frostsz)) {
      if (i < firesz) total += fire[i];
      if (i < frostsz) total += frost[i];
    }
    else {
      if (i < firesz) total += 2*fire[i];
      if (i < frostsz) total += 2*frost[i];
    }
  }

  if (firesz == frostsz) {
    total -= min(fire[firesz-1], frost[frostsz-1]);
  }
  cout << total << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
