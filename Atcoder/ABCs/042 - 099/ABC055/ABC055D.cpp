/*
  Any two consecutive animals will determine the whole sequence.
  Simply try all 4 possibilities.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
string s;

string is_valid(int a, int b){
  vector<int> arr;
  arr.push_back(a);
  arr.push_back(b);

  for (int i = 1; i < n-1; i++){
    bool change = (s[i] == 'x')^arr[i];
    arr.push_back((change ? 1-arr[i-1] : arr[i-1]));
  }

  bool change = (s[n-1] == 'x')^arr[n-1];
  if ((change ? 1-arr[n-2] : arr[n-2]) != arr[0]) return "-1";

  change = (s[0] == 'x')^arr[0];
  if ((change ? 1-arr[1] : arr[1]) != arr[n-1]) return "-1";

  string ret;
  for (int i = 0; i < n; i++){
    ret += (arr[i] ? "W" : "S");
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin >> s;

  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      string ans = is_valid(i, j);
      if (ans != "-1") {
        cout << ans << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
