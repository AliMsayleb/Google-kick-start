// Question can be found here: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bf4ed

#include <iostream>

int main()
{
    int testCases;
    std::cin >> testCases;
    int t = 0;
    while(t++ < testCases) {
        int elements;
        std::cin >> elements;
        long long current, next;
        std::cin >> current;
        std::cin >> next;
        long long diff = next - current;
        current = next;
        long long maxCount = 2;
        long long currentCount = 2;
        for (int i = 2; i < elements; i++) {
            std::cin >> next;
            auto currentDiff = next - current;
            if (currentDiff != diff) {
                diff = currentDiff;
                maxCount = currentCount > maxCount ? currentCount : maxCount;
                currentCount = 2;
            } else {
                currentCount++;
            }
            current = next;
        }
        maxCount = currentCount > maxCount ? currentCount : maxCount;
        std::cout << "Case #" << t << ": " << maxCount << std::endl;
    }
}
