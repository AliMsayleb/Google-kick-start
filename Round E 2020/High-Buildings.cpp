// Question can be found here: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bef73

#include <iostream>
#include <vector>

int main()
{
    int testCases;
    std::cin >> testCases;
    int t = 0;
    while (t++ < testCases) {
        int n, a, b, c;
        std::cin >> n;
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        if (n == a && n == b && n != c || (c+(a-c)+(b-c)>n||n>1&&a==c&&b==c&&c==1)) {
            std::cout << "Case #" << t << ": IMPOSSIBLE" << std::endl;
            continue;
        }
        std::vector<int> result;
        for (int i = 0 ; i < c; i++) {
            result.push_back(n);
        }
        int restVisibleA = a - c;
        int restVisibleB = b - c;
        int res = n - c - restVisibleB - restVisibleA;
        if (res > 0) {
            if (a > c) {
                for(int i = 0; i < res; i++) {
                    result.insert(result.begin(), 1);
                }
            } else if (b > c){
                for(int i = 0; i < res; i++) {
                    result.push_back(1);
                }
            } else {
                for(int i = 0; i < res; i++) {
                    result.insert(result.begin() + 1, 1);
                }
            }
        }
        for (int i = 0; i < restVisibleA; i++) {
            result.insert(result.begin(), n - 1);
        }
        for (int i = 0; i < restVisibleB; i++) {
            result.push_back(n-1);
        }
        std::cout << "Case #" << t << ": ";
        for (int i = 0; i < result.size() - 1; i++) {
            std::cout << result.at(i) << " ";
        }
        std::cout << result.at(result.size() - 1) << std::endl;
    }
}
