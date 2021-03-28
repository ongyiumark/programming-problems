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

const int P = 1e5+5;
bool is_composite[P];
vector<ll> primes;
vector<ld> lgprimes;

void sieve(){
  for (int i = 2; i < P; i++){
    if (!is_composite[i]){
      primes.push_back(i);
      lgprimes.push_back(log10(i));
    }
    for (int j = 0; j < (int)primes.size() && i*primes[j] < P; j++){
      is_composite[i*primes[j]] = 1;
      if (i%primes[j] == 0) break;
    }
  }
}

vector<vector<int>> solve(int n){
  if (n == 1) return {{1}};
  vector<vector<int>> ans;
  for (int i = 1; i*i <= n; i++){
    if (n%i != 0) continue;
    vector<vector<int>> tmp = solve(i);
    for (auto v : tmp){
      v.push_back(i);
      ans.push_back(v);
    }
    if (i*i == n || i == 1) continue;
    tmp = solve(n/i);
    for (auto v : tmp){
      v.push_back(n/i);
      ans.push_back(v);
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  int n = 735134400;
  n = 4;
  vector<vector<int>> factors = solve(n);
  for (auto &vec: factors){
    for (auto &v : vec){
      cout << v << " ";
    }
    cout << endl;
  }
  return 0;
}
