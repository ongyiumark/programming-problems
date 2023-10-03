#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 6002;
vector<string> ar(N);
unordered_map<string,int> idx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s; cin >> n >> s;
    int sz = n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        idx[ar[i]] = i;
    }

    for (int i = 0; i < s; i++) {
        string t; cin >> t;
        if (t == "insert") {
            string ns; int pos;
            cin >> ns >> pos;
            for (int j = sz-1; j >= pos; j--) {
                ar[j+1] = ar[j];
                idx[ar[j+1]] = j+1;
            }

            ar[pos] = ns;
            idx[ns] = pos;
            sz++;
        }
        else if (t == "depart") {
            string ns; cin >> ns;
            int pos = idx[ns];
            for (int j = pos; j < sz; j++) {
                ar[j] = ar[j+1];
                idx[ar[j]] = j;
            }

            sz--;
        }
        else {
            string ns; int d; cin >> ns >> d;
            int pos = idx[ns];
            if (d > 0) {
                for (int j = pos; j < pos+d; j++) {
                    idx[ar[j]] = j+1;
                    idx[ar[j+1]] = j;
                    swap(ar[j], ar[j+1]);
                }
            }
            else {
                for (int j = pos; j > pos+d; j--) {
                    idx[ar[j]] = j-1;
                    idx[ar[j-1]] = j;
                    swap(ar[j], ar[j-1]);
                }
            }
        }
    }

    for (int i = 0; i < sz; i++) {
        cout << ar[i];
        cout << (i+1 < sz ? " " : "\n");
    }

    
    return 0;
}