// Question can be found here: https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414a24

// Solved it in a way that i created an array of size N and filled it with the number of steps needed so all wheels would turn there and then got the minimum but i got a wrong answer so something is not correct

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve()
{
    long long wheels, max;
    cin >> wheels;
    cin >> max;
    long long positions[max + 1] = {0};
    std::unordered_map<long long, long long> counts;
    for (long long i = 0; i < wheels; i++) {
        long long wheel;
        cin >> wheel;
        long long c = counts[wheel - 1] + 1;
        counts[wheel - 1] = c;
    }
    
    for (auto& curPair: counts) {
        for (int j = 0; j < max; j++) {
            long long currentCount = curPair.second;
            long long wheelPosition = curPair.first;
            
            long long currentNext = min(abs(wheelPosition - j), (j + max - wheelPosition));
            positions[j] += currentNext * currentCount;
        }
    }
    long long min = 99999999999;
    for (int j = 0; j < max; j++) {
        if(positions[j] < min) {
            min = positions[j];
        }
    }
    
    cout << " " << min << endl;
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
