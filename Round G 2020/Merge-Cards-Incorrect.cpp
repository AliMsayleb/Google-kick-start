// Question can be found here: https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000415054

// This is a brute force implementation which only worked on the first test set with numbers <= 9 (complexity is n-1! so brute force worked here for this test case)

#include <iostream>
#include <vector>
#include <numeric>
#include <stdio.h>

using namespace std;

void solveR(vector<long long>& nums, long long curSum, vector<long long>& results);

void solve()
{
    int numbers;
    cin >> numbers;
    std::vector<long long> nums;
    nums.reserve(numbers);
    for(int i = 0; i < numbers; i++) {
        long long current;
        cin >> current;
        nums.push_back(current);
    }
    std::vector<long long> results;
    solveR(nums, 0, results);
    cout.precision(7);
    printf(" %.7f\n", accumulate( results.begin(), results.end(), 0.0) / results.size());
}

vector<long long> copyWithoutI(const vector<long long>& nums, int i) {
    vector<long long> copy;
    copy.reserve(nums.size() - 1);
    for (int j = 0, x = 0; j < nums.size() - 1; j++, x++) {
        if (j == i) {
            copy.push_back(nums.at(j) + nums.at(j+1));
            x++;
        } else {
            copy.push_back(nums.at(x));
        }
    }
    
    return copy;
}

void solveR(vector<long long>& nums, long long curSum, vector<long long>& results) {
    long double totals = 0;
    if (nums.size() == 1) {
        results.push_back(curSum);
        
        return;
    }
    for (int i = 0; i < nums.size() - 1; i++) {
        vector<long long> copy = copyWithoutI(nums, i);
        solveR(copy, curSum + copy.at(i), results);
    }
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
