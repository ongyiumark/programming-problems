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

ld parse(string x) {
  unordered_map<char, ld> dir = {{'N', 0}, {'E', 90}, {'S', 180}, {'W', 270}};
  unordered_map<string, ld> other = {
    {"N", 0}, {"E", 90}, {"S", 180}, {"W", 270},
    {"NE", 45}, {"SE", 135}, {"SW", 225}, {"NW", 315}
  };

  if (other.find(x) != other.end()) return other[x];

  int n = x.size();
  ld res = other[x.substr(n-2)];
  if (x.substr(n-2) == "NW") dir['N'] = 360;

  for (int i = n-3; i >= 0; i--) {
    res = (res + dir[x[i]])/2;
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string x, y; cin >> x >> y;

  unordered_map<char, ld> dir = {{'N', 0}, {'E', 90}, {'S', 180}, {'W', 270}};
  ld a = parse(x);
  ld b = parse(y);
  
  if (a > b) swap(a,b);
  cout << setprecision(20) << fixed << min(b-a,a+360-b) << "\n";
  
  return 0;
}
