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

ll rand(ll a, ll b){
  return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(stoi(argv[1]));

  vector<ll> p = {2,3,5,7,11,13,17,19,23};
  int m = p.size();
  ll mask = stoi(argv[1])%(1<<m);
  if (mask == 0) mask = 1;
  ll n = 1;
  for (int i = 0; i < m; i++) {
    if ((1<<i)&mask) {
      n *= p[i];
    }
  }

  cout << n <<  " " << rand(0, n-1) << endl;

  return 0;
}
