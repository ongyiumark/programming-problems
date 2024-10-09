#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

struct wilddigit {
  int lo, hi;
  wilddigit(int _lo, int _hi) : lo(_lo), hi(_hi) {}
};
const int MOD = 998244353;
void testcase() {
  string E; int k;
  cin >> E >> k;
  int n = E.size();

  vector<wilddigit> wilds;
  if (n == 1) {
    if (E[0] == '?') wilds.push_back(wilddigit(0,9));
    else {
      int d = E[0]-'0';
      wilds.push_back(wilddigit(d,d));
    }
  }
  else {
    if (E[n-1] == '?') {
      if (E[n-2] == '?' || E[n-2] == '1' || E[n-2] == '2') wilds.push_back(wilddigit(0,9));
      else wilds.push_back(wilddigit(1,9));
    }
    else {
      int d = E[n-1]-'0';
      wilds.push_back(wilddigit(d,d));
    }

    for (int i = n-1; i >= 0; i--) {
      int highest_next = wilds.back().hi;
      if (E[i] == '?') {
        if (highest_next >= 7) wilds.push_back(wilddigit(1,1));
        else wilds.push_back(wilddigit(1,2));
      }
      else {
        int d = E[i]-'0';
        wilds.push_back(wilddigit(d,d));
      }
    }
    reverse(wilds.begin(), wilds.end());
  }

  vector<int> bases(n);
  for (int i = 0; i < n; i++) {
    bases[i] = wilds[i].hi - wilds[i].lo + 1;
  }

  // write k in terms of bases
  vector<int> num(n);
  int curk = k-1;
  for (int i = n-1; i >= 0; i--) {
    num[i] = curk%bases[i];
    curk /= bases[i];
  }
  
  vector<int> ans(n);
  ll pos = 1;
  for (int i = 0; i < n; i++) {
    ans[i] = num[i];
    pos = pos*bases[i]%MOD;
  }

  for (int i = 0; i < n; i++) cout << ans[i];
  cout << " " << pos << "\n";



}

void main_() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    testcase();
  }
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
  char *stack, *send;
  stack = (char *)malloc(stsize);
  send = stack + stsize - 16;
  send = (char *)((uintptr_t)send / 16 * 16);
  asm volatile(
    "mov %%rsp, (%0)\n"
    "mov %0, %%rsp\n"
    :
    : "r"(send));
  func();
  asm volatile("mov (%0), %%rsp\n" : : "r"(send));
  free(stack);
}
int main() {
  run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
  return 0;
}