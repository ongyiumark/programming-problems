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

bool check(ll a, ll b, ll c, char op) {
  return (op == '*' ? (a*b == c) : (a+b == c));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string left, right, res;
  char op, eq;
  cin >> left >> op >> right >> eq >> res;

  for (int k = 0; k < 2; k++) {
    int n = left.size();
    int m = res.size();
    for (int i = 0; i < n-1; i++) {
      for (int j = 0; j < m-1; j++) {
        string lpref = left.substr(0, i+1);
        string rpref = res.substr(0, j+1);

        string nleft = rpref+left.substr(i+1);
        string nres = lpref+res.substr(j+1);

        if(check(stoll(nleft), stoll(right), stoll(nres), op)) {
          if (k == 1) swap(nleft, right);
          cout << nleft << " " << op << " " << right << " " << eq << " " << nres << endl;
          return 0; 
        }
      }
    }
    swap(left, right);
  }

  int n = left.size();
  int m = right.size();
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < m-1; j++) {
      string lpref = left.substr(0, i+1);
      string rpref = right.substr(0, j+1);

      string nleft = rpref+left.substr(i+1);
      string nright = lpref+right.substr(j+1);

      if(check(stoll(nleft), stoll(nright), stoll(res), op)) {
        cout << nleft << " " << op << " " << nright << " " << eq << " " << res << endl;
        return 0; 
      }
    }
  }
}
