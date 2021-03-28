#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int N = 100;
char grid[N][N];
int r, c;

bool is_connector(char c){
    return c == '|' || c == '-' || c == '+';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        set<char> nodes;
        set<pair<char,char>> pset;
        cin >> r >> c;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cin >> grid[i][j];
                if (!is_connector(grid[i][j])) nodes.insert(grid[i][j]);
            }
        }
        
        for (int i = 0; i < r; i++){
            int j = 0;
            while(j < c){
                while(j < c && nodes.find(grid[i][j]) == nodes.end()) j++;
                if (j == c) continue;
                char u = grid[i][j];
                j++;
                if (j == c) continue;
                if (!(grid[i][j] == '-' || grid[i][j] == '+')) continue;
                j++;
                if (j == c) continue;
                while(j < c && (grid[i][j] == '-' || grid[i][j] == '+')) j++;
                if (j == c) continue;
                char v;
                if (nodes.find(grid[i][j]) != nodes.end()) v = grid[i][j];
                else continue;
                j++;

                if (u > v) swap(u, v);
                nodes.erase(u);
                nodes.erase(v);
                pset.insert({u, v});
            }
        }

        for (int j = 0; j < c; j++){
            int i = 0;
            while(i < r){
                while(i < r && nodes.find(grid[i][j]) == nodes.end()) i++;
                if (i == r) continue;
                char u = grid[i][j];
                i++;
                if (i == r) continue;
                if (!(grid[i][j] == '|' || grid[i][j] == '+')) continue;
                i++;
                if (i == r) continue;
                while(i < r && (grid[i][j] == '|' || grid[i][j] == '+')) i++;
                if (i == r) continue;
                char v;
                if (nodes.find(grid[i][j]) != nodes.end()) v = grid[i][j];
                else continue;
                i++;

                if (u > v) swap(u, v);
                nodes.erase(u);
                nodes.erase(v);
                pset.insert({u, v});
            }
        }

        cout << nodes.size() << endl;
        int cnt = 0;
        for (char c : nodes){
            if (cnt > 0) cout << " ";
            cout << c;
            cnt++;
        }
        cout << endl;

        cout << pset.size() << endl;
        cnt = 0;
        for (auto p : pset){
            if (cnt > 0) cout << " ";
            cout << p.first << p.second;
            cnt++;
        }
        cout << endl;
    }


    return 0;
}