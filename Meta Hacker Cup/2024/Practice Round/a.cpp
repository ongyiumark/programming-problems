#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;

void testcase() {
  ll n, k; cin >> n >> k;
  vector<ll> S(n);
  for (ll &x : S) cin >> x;
  sort(S.begin(), S.end());

  ll time = 1e18;
  if (n <= 2) time = S[0];
  else {
    time = S[0]*(n-2)*2 + S[0];
  }
  if (time <= k) cout << "YES\n";
  else cout << "NO\n";
}

void main_() {
  cin.tie(0)->sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    cout << "Case #" << t << ": ";
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