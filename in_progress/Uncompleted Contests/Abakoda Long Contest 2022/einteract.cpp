#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INF = 1e9;
const ll INFLL = 4e18;
int rand(int a, int b) {
    return a + rand() % (b-a+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m; cin >> m;

    int t = 100;
    cout << t << endl;
    while(t--) {
        a[0] = rand(1,20);
        cerr << "To Guess: " << a[0] << endl; 
        while(1) {
            string s; cin >> s;
            if (s == "WEIGH") {
                int kl; cin >> kl;
                int Lsum = 0;
                for (int i = 0; i < kl; i++) {
                    int x; cin >> x; Lsum += a[x];
                }

                int kr; cin >> kr;
                int Rsum = 0;
                for (int i = 0; i < kr; i++) {
                    int x; cin >> x; Rsum += a[x];
                }

                //cerr << Lsum << " " << Rsum << endl;

                if (Lsum == Rsum) cout << "=" << endl;
                else if (Lsum > Rsum) cout << ">" << endl;
                else cout << "<" << endl;
            }
            else if (s == "VERDICT") {
                string t; cin >> t;
                if (t == "EXACT") {
                    int guess; cin >> guess;
                    cout << (guess == a[0] ? ":)" : ">:(") << endl;
                }
                else {
                    cout << (a[0] > m ? ":)" : ">:(") << endl;
                }
                cerr << "Correct Answer: " << a[0] << endl;
                break;
            }
        }
        
    }


    return 0;
}