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

const int N = 1e5+5;
int n, m, k;
int dig[10];
vector<char> ans1;
string ans2 = "";
deque<char> u;
map<deque<char>, int> mask;
bool found = false;

void dfs(){
  if (found) return;
  //cout << ans1.size() << " " << n+k-1 << endl;
  if (ans1.size() == n+k-1){
    found = true;
    for (int i = 0; i < n+k-1; i++){
      cout << ans1[i];
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < m; i++){
    if (mask[u]&(1<<i)) continue;
    mask[u] |= (1<<i);
    u.push_back(dig[i]+'0');
    u.pop_front();
    ans1.push_back((char)(dig[i]+'0'));
    dfs();
    ans1.pop_back();
    u.pop_back();
    u.push_front(ans1[(int)ans1.size()-(n-1)]);
  }

  if (found) return;

  ans2 += ans1[(int)ans1.size()-1];
  //cout << ans2.size() << " " << n+k-1-(n-2) << endl;
  if (ans2.size() == n+k-1-(n-2)){
    reverse(ans2.begin(), ans2.end());
    string res = "";
    for (int i = (int)ans1.size()-(n-2); i < (int)ans1.size(); i++) res += ans1[i];
    res += ans2;
    found = true;
    cout << res << endl;
  }

}

int rand(int a, int b){
  return rand()%(b-a+1)+a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  srand(time(0));

  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) cin >> dig[i];

  if (m == 1){
    string res = "";
    res.append(n, dig[0]+'0');
    cout << res << endl;
    return 0;
  }

  if (n >= 40){
    // generate random string of size n+k-1
    string res = "";
    for (int i = 0; i < n+k-1; i++){
      res.append(1, dig[rand(0,m-1)]+'0');
    }
    cout << res << endl;
    return 0;
  } 

  string start = "";
  start.append(n-1, dig[0]+'0');
  for (char ch : start) {
    ans1.push_back(ch);
    u.push_back(ch);
  }

  dfs();
  
  //cout << found << endl;
  return 0;
}
