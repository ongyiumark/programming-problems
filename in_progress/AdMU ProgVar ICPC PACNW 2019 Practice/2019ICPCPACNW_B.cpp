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
int x[N];
map<int,int> cnt, curr_cnt;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    cnt[x[i]]++;
  }

  vector<int> ans;
  for (int i = 0; i < n; i++){
    int num = x[i];
    cnt[num]--;

    if (curr_cnt[num] > 0) continue;
    while((int)ans.size() > 0 && ans.back() > num && (curr_cnt[ans.back()] > 1 || cnt[ans.back()] > 0)){
      curr_cnt[ans.back()]--;
      ans.pop_back();
    }

    ans.push_back(num);
    curr_cnt[num]++;
  }

  while((int)ans.size() > 0 && curr_cnt[ans.back()] > 1){
      curr_cnt[ans.back()]--;
      ans.pop_back();
  }

  int sz = ans.size();
  for (int i = 0; i < sz; i++) {
    cout << ans[i];
    if (i+1 < sz) cout << " ";
    else cout << endl;
  }

  return 0;
}
