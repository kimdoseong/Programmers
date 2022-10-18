//
// Created by kimdoseong on 2022/10/18.
//

/**
 * 성격 유형 검사하기
 * 2022 KAKAO BLIND RECRUITMENT
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long num) {
    if (num > 2) {
        if (num % 2 == 0) {
            return false;
        }

        long const n = abs(num);
        long const sqrt_number = static_cast<long>(std::sqrt(static_cast<double>(n)));

        for (long i = 3; i <= sqrt_number; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
    } else if (num == 0 || num == 1) {
        return false;
    }

    return true;
}


int solution(int n, int k) {
    int answer = 0;
    std::vector<int> num;

    while (n > 0) {
        num.emplace_back(n % k);
        n /= k;
    }

    std::reverse(num.begin(), num.end());
    auto first = num.begin();
    while (first != num.end()) {
        first = find_if(first, num.end(), [](int num) {
            if (num != 0) {
                return true;
            }

            return false;
        });

        if (first != num.end()) {
            string number = to_string(*first);
            auto last = find(first, num.end(), 0);
            std::for_each(first + 1, last, [&number](int num) {
                number.append(to_string(num));
            });

            if (isPrime(stol(number))) {
                answer++;
            }

            first = last;
        }
    }

    return answer;
}

int main() {
    std::cout << solution(1000000, 3) << std::endl;

    return 0;
}