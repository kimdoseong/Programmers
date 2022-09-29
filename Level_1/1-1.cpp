//
// Created by kimdoseong on 2022/09/29.
//
/**
 * 성격 유형 검사하기
 * 2022 KAKAO TECH INTERNSHIP
 */

#ifdef TEST

#include <iostream>

#endif

#include <vector>
#include <array>
#include <string>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    int pos = 0;
    array<int, 26> result{};

    for (const auto &s: survey) {
        if (choices[pos] < 4) {
            // disagree
            result[s[0] - 65] = result[s[0] - 65] + abs(choices[pos] - 4);
        } else if (choices[pos] > 4) {
            // agree
            result[s[1] - 65] = result[s[1] - 65] + abs(choices[pos] - 4);
        }

        pos++;
    }

    string answer;
    result['R' - 65] >= result['T' - 65] ? answer.append("R") : answer.append("T");
    result['C' - 65] >= result['F' - 65] ? answer.append("C") : answer.append("F");
    result['J' - 65] >= result['M' - 65] ? answer.append("J") : answer.append("M");
    result['A' - 65] >= result['N' - 65] ? answer.append("A") : answer.append("N");

    return answer;
}

int main() {
#ifdef TEST
    // test code
    std::vector<std::string> s{"TR", "RT", "TR"};
    std::vector<int> c{7, 1, 3};
    std::cout << solution(s, c) << std::endl;
#endif
    return 0;
}
