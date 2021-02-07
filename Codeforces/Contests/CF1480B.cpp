/*
  You can convert the damage you take from every monster as ceil(b[i]/A)*a[i].
  If the sum is less your health, then you're good.
  If its bigger, you want to save the biggest hitting one for last.

  I forgot to check for equality when checking if you're dead, so I got this wrong on the contest. 
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

const int N = 1e5;
ll a[N], b[N];
pair<ll, ll> mult[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    ll A, B, n; cin >> A >> B >> n; 
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) mult[i] = {a[i], (b[i]+A-1)/A};
    sort(mult, mult+n);

    ll damage = 0;
    bool dead = 0;
    for (int i = 0; i < n-1 && !dead; i++){
      damage += mult[i].first*mult[i].second;
      if (damage >= B) dead = 1;
    } 

    if (!dead && damage+mult[n-1].first*(mult[n-1].second-1) >= B) dead = 1;
    cout << (dead ? "NO" : "YES") << endl;
  }
  return 0;
}
