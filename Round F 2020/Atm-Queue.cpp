// Question can be found here: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f4ed8

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        int N;
        int X;
        cin >> N;
        cin >> X;
        std::vector<std::pair<int, int>> A;
        for (int i = 1; i <= N; i++) {
            int Ai;
            cin >> Ai;
            A.push_back(make_pair((Ai - 1) / X + 1, i));
        }
        cout << "Case #" << testCase << ":";
        sort(A.begin(), A.end());
        for (auto pair: A) {
            cout << " " << pair.second;
        }
        cout << endl;
    }
    return 0;
}
