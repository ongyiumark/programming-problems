#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int N = 1e7+5;
vector<bool> is_composite(N);
vector<int> primes;

const int nMAX = 1e5+5;

struct cards{
  int p, c, l;
};

vector<cards> pcl(N);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i < N; i++) {
    if (!is_composite[i]) primes.push_back(i);
    for (int j = 0; j < (int)primes.size() && i*primes[j] < N; j++) {
      is_composite[i*primes[j]] = 1;
      if (i%primes[j] == 0) break;
    }
  }

  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> pcl[i].p >> pcl[i].c >> pcl[i].l;
  }

  sort(pcl.begin(), pcl.begin()+n, [](const cards &left, const cards &right){
    if (left.l == right.l) {
      if (left.p == right.p) return left.c < right.c;
      return left.p < right.p;
    }
    return left.l < right.l;
  });

  for (int i = 0; i < n; i++) {
    cout << pcl[i].p << " " << pcl[i].c << " " << pcl[i].l << endl;
  }

  // dp[i][]

  return 0;
}
