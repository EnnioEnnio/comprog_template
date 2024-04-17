#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

bool canDistributePies(const vector<int>& ponies, int pies, int maxSlices) { // ponies, 3, 3 .. ponies 5 7
    long long requiredPies = 0;
    for (int poniesCount : ponies) {
        requiredPies += (poniesCount + maxSlices - 1) / maxSlices; // This is ceil(poniesCount / maxSlices)
        if (requiredPies > pies) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int testcases;
    cin >> testcases;

    while (testcases--) {
        int households, pies;
        cin >> households >> pies; // 2 3

        vector<int> ponies(households, 0);
        int maxPonies = 0;

        for (int i = 0; i < households; i++) {
            cin >> ponies[i]; // 5 7
            maxPonies = max(maxPonies, ponies[i]); // 7
        }

        int low = 1;
        int high = maxPonies; // 7
        int answer = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // 3
            if (canDistributePies(ponies, pies, mid)) {
                answer = mid; // If it's possible, try for a larger slice size
                high = mid - 1;
            } else {
                low = mid + 1; // If not, decrease the slice size
            }
        }

        cout << answer << "\n";
    }
    return 0;
}

// test-input: 1, 2, 3, 5, 7 -> should result in 5
