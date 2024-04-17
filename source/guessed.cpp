#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Insert three distinct elements
    cout << "? insert 10" << endl;
    cout.flush();
    cout << "? insert 20" << endl;
    cout.flush();
    cout << "? insert 30" << endl;
    cout.flush();

    // Now perform removals and check order of removed elements
    cout << "? remove" << endl;
    cout.flush();
    int first;
    cin >> first;

    cout << "? remove" << endl;
    cout.flush();
    int second;
    cin >> second;

    cout << "? remove" << endl;
    cout.flush();
    int third;
    cin >> third;

    if (first == 10 && second == 20 && third == 30) {
        cout << "! queue" << endl;
    } else if (first == 30 && second == 20 && third == 10) {
        cout << "! stack" << endl;
    } else if (first == 10 && second == 20 && third == 30) {
        cout << "! pq" << endl; // pq and set might behave similarly, additional checks may be needed if distinct behavior is required
    } else {
        cout << "! set" << endl;
    }

    return 0;
}
