// Question can be found here: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f4b8b

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        int K, N;
        cin >> N;
        cin >> K;
        std::vector<std::pair<int, int>> intervals;
        intervals.reserve(N);
        for (int i = 0; i < N; i++) {
            int s, e;
            cin >> s;
            cin >> e;
            intervals.push_back(make_pair(s, e));
        }
        sort(intervals.begin(), intervals.end());
        int count = 1;
        int start = intervals.at(0).first;
        int end = start + K;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals.at(i).first > end) {
                count++;
                start = intervals.at(i).first;
                end = start + K;
            }
            if (intervals.at(i).second > end) {
                int temp = ceil((double)((intervals.at(i).second - end) / (1.0 * K)));
                end = end + temp * K;
                count += temp;
            }
        }
        cout << "Case #" << testCase << ": " << count;
        cout << endl;
    }
    return 0;
}
