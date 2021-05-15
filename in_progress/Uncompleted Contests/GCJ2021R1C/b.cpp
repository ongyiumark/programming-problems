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

ll y;
void testcase(){
  cin >> y;
  string s = to_string(y);
  int n = s.size();

  vector<string> answers;
  for (int i = 1; i <= 19; i++){
    if (i > n) continue;
    int pos = 0;
    string t = s.substr(pos,i);
    ll x = stoll(t);
    pos += i;

    // try with same starting
    string ans = t;
    while(true){
      x++;
      string strx = to_string(x);
      //cout << strx.size() << " " << pos << " " << n << endl;
      if (n-pos <= strx.size()){
        ans += strx;
        answers.push_back(ans);
        break;
      }
      ans += strx;
      pos += strx.size();
    }

    pos = 0;
    t = s.substr(pos,i);
    x = stoll(t);
    x++;
    pos += i;

    ans = to_string(x);
    while(true){
      x++;
      string strx = to_string(x);
      if (n-pos <= strx.size()){
        ans += strx;
        answers.push_back(ans);
        break;
      }
      ans += strx;
      pos += strx.size();
    }
    
    pos = 0;
    t = "1";
    t.append(i-1, '0');
    x = stoll(t);
    pos += i;

    ans = to_string(x);
    while(true){
      x++;
      string strx = to_string(x);
      if (n-pos < strx.size()){
        ans += strx;
        answers.push_back(ans);
        break;
      }
      ans += strx;
      pos += strx.size();
    }
  }

  answers.push_back(s);
  sort(answers.begin(), answers.end(), [](string &left, string &right){
    int n = left.size();
    int m = right.size();
    if (n == m){
      for (int j = 0; j < n; j++){
        if (left[j] == right[j]) continue;
        return left[j] < right[j];
      } 
      return false;
    }
    else return n < m;
  });
  
  int idx = 0;
  while(idx < answers.size() && answers[idx] != s) idx++;
  while(idx < answers.size() && answers[idx] == s) idx++;
  cout << answers[idx] << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
