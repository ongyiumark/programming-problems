#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 1e7;
vector<int> lp(N+1);
vector<bool> isp(N+1);
vector<ll> pr;
vector<int> cnt;
void sieve() {
  for (ll i = 2; i <= N; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      isp[i] = true;
      pr.push_back(i);
    }
    for (int j = 0; j < pr.size() && i*pr[j] <= N; j++) {
      lp[i*pr[j]] = pr[j];
      if (i%pr[j] == 0) break;
    }
  }
}

void testcase() {
  int n; cin >> n;
  if (n < 5) {
    cout << 0 << "\n";
    return;
  }

  // find index of max p <= n
  int lo = 0;
  int hi = (int)pr.size()-1;
  int ans = -1;
  while (lo <= hi) {
    int mid = hi - (hi-lo)/2;
    if (pr[mid] <= n) {
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  cout << cnt[ans] << "\n";
}

void main_() {
  cin.tie(0)->sync_with_stdio(false);
  sieve();
  int sz = pr.size();
  cnt.resize(sz);

  cnt[0] = 0; cnt[1] = 0; cnt[2] = 2;
  int counter = 2;
  for (int i = 3; i < sz; i++) {
    if (isp[pr[i]-2]) counter++;
    cnt[i] = counter;
  }
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