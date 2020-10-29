/*
  Rolling median with 2 heaps (priority queues).
  You can compute for the change in distance given the new median and the old median.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5;
priority_queue<int> lleft;
priority_queue<int, vector<int>, greater<int>> rright;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q; cin >> q;
  ll B = 0;
  ll med = 0;
  ll A = 0;
  while (q--){
    int t; cin >> t;
    if (t == 1){
      ll a, b; cin >> a >> b;
      B += b;

      ll new_med = -1;
      int n = lleft.size();
      int m = rright.size();
      bool check = true;
      
      if (n <= m){
        rright.push(a);
        lleft.push(rright.top());
        rright.pop();
        new_med = lleft.top();
      }
      else {
        lleft.push(a);
        rright.push(lleft.top());
        lleft.pop();
        new_med = lleft.top();
        check = false;
      }
      
      A += abs(med - a) - abs(med-new_med)*check;
      med = new_med;
    }
    else {
      cout << med << " " << A + B << "\n";
    }
  }
  return 0;
}
