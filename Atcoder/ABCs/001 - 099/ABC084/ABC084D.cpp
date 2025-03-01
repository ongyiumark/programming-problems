/*
  Check if every number from 1 to 1e5 is similar to 2017.
  A prime check can be done in O(sqrt(n)).

  Then, use a prefix sum to count the number of similars in a range.
  Alternatively, you can do a prime sieve to check for primes.
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

const int N = 1e5+1;
bool is_similar[N];
int pref[N];

bool check(int x){
  if (x%2 == 0) return false;
  for (int i = 2; i*i <= x; i++){
    if (x%i == 0) return false;
  }
  for (int i = 2; i*i <= (x+1)/2; i++){
    if ((x+1)/2%i == 0) return false;
  }
  return true;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(is_similar, 0, sizeof is_similar);
  for (int i = 2; i < N; i++){
    is_similar[i] = check(i);
  }

  memset(pref, 0, sizeof pref);
  for (int i = 1; i < N; i++){
    pref[i] += pref[i-1]+is_similar[i];
  } 

  int q; cin >> q;
  while(q--){
    int l, r; cin >> l >> r;
    cout << pref[r]-pref[l-1] << endl;
  }
  return 0;
}
