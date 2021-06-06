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

int gcd(int a, int b){
  if (b == 0) return a; 
  return gcd(b, a%b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a[6], b[6];
  for (int i = 0; i < 6; i++) cin >> a[i];
  for (int i = 0; i < 6; i++) cin >> b[i];

  int cnt = 0;
  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 6; j++){
      cnt += a[i] > b[j];
    }
  }

  int g = gcd(cnt, 36);
  cout << cnt/g << "/" << 36/g << endl;

  return 0;
}
