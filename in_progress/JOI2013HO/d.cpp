/*
  Binary search the answer.
  Objective function: Reserve the last x i's and try to form IOI/JOIs from them.
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

const int N = 1e6;
string s;
int n;

bool taken[N];
bool valid(int x){
  memset(taken, 0, sizeof taken);
  int cnt = 0;
  queue<int> q;
  for (int i = n-1; i >= 0 && cnt < x; i--){
    if (s[i] == 'I') {
      taken[i] = 1;
      cnt++;
      q.push(i);
    }
  }

  queue<int> oq; 
  for (int i = n-1; i >= 0; i--){
    if (taken[i]) continue;
    if (s[i] == 'O') oq.push(i);
    int iidx = q.front();
    while(!oq.empty() && oq.front() > iidx){
      oq.pop();
    }
    if (s[i] == 'I' && !oq.empty() && !q.empty()){
      x--;
      oq.pop();
      q.pop();
    } 
    if (s[i] == 'J' && !oq.empty() && !q.empty()){
      x--;
      oq.pop();
      q.pop();
    } 
  }
  return x <= 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s;
  int lo = 0;
  int hi = n;
  int ans = 0;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (valid(mid)){
      lo = mid+1;
      ans = mid;
    }
    else hi = mid-1;
  }
  cout << ans << endl;
  return 0;
}
