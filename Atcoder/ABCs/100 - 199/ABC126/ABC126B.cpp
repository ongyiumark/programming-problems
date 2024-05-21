/*
  We only really have to check the month because the year is always valid.
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

bool valid_month(int x){
  return 0 < x && x <= 12;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string s; cin >> s;
  int first  = stoi(s.substr(0,2));
  int second = stoi(s.substr(2,2));

  if (valid_month(first) && valid_month(second)) cout << "AMBIGUOUS" << endl;
  else if (valid_month(first)) cout << "MMYY" << endl;
  else if (valid_month(second)) cout << "YYMM" << endl;
  else cout << "NA" << endl;

  return 0;
}
