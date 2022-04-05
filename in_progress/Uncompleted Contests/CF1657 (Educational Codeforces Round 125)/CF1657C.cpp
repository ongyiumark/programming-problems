/*
  Notice that "((" and "))" are palindromes, and "()" is a regular bracket.
  Notice also that if we begin with ")(", then it become a palindrome on the next ")". 
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

string s;
int n;

void testcase(){
  cin >> n;
  cin >> s;

  int idx = 0;
  int cnt = 0;
  int left = n;
  while (idx+1 < n) {
    if (!(s[idx] == ')' && s[idx+1] == '(')) {
      idx += 2;
      cnt += 1;
      left -= 2;
      continue;
    }
    // next closing
    idx += 1;
    int tcnt = 1;
    while(idx < n && s[idx] != ')') {
      idx += 1;
      tcnt += 1;
    }
    if (idx < n && s[idx] == ')') {
      left -= tcnt+1;
      cnt += 1;
      idx += 1;
    }
  }
  cout << cnt << " " << left << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) {
    testcase();
  }
  return 0;
}
