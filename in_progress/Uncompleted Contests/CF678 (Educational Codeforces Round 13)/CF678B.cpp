/*  
  Just keep increasing the year until you get back to 0 mod 7.
  
  Edge case: 
    If you start with a leap year, you must end also in a leap year.
    Vice versa.
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

bool is_leap(int n) {
  return (n%4==0)-(n%100==0)+(n%400==0);
}
int cnt(int n) {
  return (is_leap(n) ? 366%7 : 365%7);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  bool leap = is_leap(n);
  int mod = cnt(n++);
  while(mod != 0) {
    mod = (mod + cnt(n++))%7;
    if (mod == 0 && is_leap(n) != leap){
      mod = (mod + cnt(n++))%7;
    }
  }
  cout << n << endl;
  return 0;
}
