/*
  Greedily choose the leftmost you can pick/
*/
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

const int N = 2e5+5;
int a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int curr = 1;
  int cnt = 0;
  
  for (int i = 0; i < n; i++) {
    if (curr == a[i]) curr++;
    else cnt++;
  }

  cout << (curr == 1 ? -1 : cnt) << endl; 
  return 0;
}
