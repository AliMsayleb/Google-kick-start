// Question can be found here: https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414a23

#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long sums[2*n - 1] = {0};
    long long max = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            int current;
            cin >> current;
            int currentPos = i - j + n - 1;
            sums[currentPos] += current;
            if (sums[currentPos] > max) {
                max = sums[currentPos];
            }
        }
    }
    cout << " " << max << endl;
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        cout << "Case #" << i << ":";
        solve();
    }
}