/*
  The idea is to prime factorize n!. Then, write all possible product partitions of 75.
  For each product partition, try to fit them into the multiplicities of the factorization of n!.

  This is a more general implementation, but unnecessary.
*/
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

unordered_map<int,int> factors;
vector<vector<int>> pos;
vector<int> pos_helper;
vector<int> mults;

const int N = 1000;
bool is_composite[N];
bool vis[N];
int fact[10];
vector<int> primes;

void sieve() {
  fact[0] = 1;
  for (int i = 1; i < 10; i++){
    fact[i] = i*fact[i-1];
  }

  memset(is_composite, 0, sizeof is_composite);
  for (int i = 2; i < N; i++){
    if (!is_composite[i]) primes.push_back(i);
    for (int j = 0; j < primes.size() && i*primes[j] < N; j++){
      is_composite[i*primes[j]] = 1;
      if (i%primes[j] == 0) break;
    }
  }
}

void prod(int x, int last){
  pos_helper.push_back(x);
  pos.push_back(pos_helper);
  pos_helper.pop_back();

  for (int d = 2; d*d <= x; d++){
    if (x%d != 0) continue;
    if (!is_composite[last] && last > d) continue;
    pos_helper.push_back(d);
    prod(x/d, d);
    pos_helper.pop_back();
  }
}

int solve(vector<int> &v, int i){
  if (i == v.size()) return 1;
  int ans = 0;
  for (int j = 0; j < mults.size(); j++){
    if (vis[j]) continue;
    if (v[i]-1 <= mults[j]){
      vis[j] = 1;
      ans += solve(v, i+1);
      vis[j] = 0;
    }
  }
  return ans;
}

int countrep(vector<int> &v){
  unordered_map<int,int> cnt;
  for (int &x : v){
    cnt[x]++;
  }
  int res = 1;
  for (auto it : cnt){
    res *= fact[it.second];
  }
  return res;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();

  int n; cin >> n;
  // prime factorize n!
  for (int i = 2; i <= n; i++){
    int x = i;
    for (int d = 2; d*d <= x; d++){
      while(x%d == 0){
        x/=d;
        factors[d]++;
      }
    }
    if (x > 1) factors[x]++;
  }
  for (auto it : factors){
    mults.push_back(it.second);
  }

  // possible products of 75
  prod(75, 999);
  
  int ans = 0;
  for (vector<int> v : pos){
    int rep = countrep(v);
    int tmp = solve(v, 0);
    tmp /= rep;
    ans += tmp;
  }
  
  cout << ans << endl;
  return 0;
}
