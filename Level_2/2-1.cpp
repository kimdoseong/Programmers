//
// Created by kimdoseong on 2022/10/04.
//

/**
 * 모음사전
 * 완전탐색
 */

#ifdef TEST

#include <iostream>

#endif

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string alphabet = "AEIOU";
vector<string> dictionary;

void dfs(int max, const std::string &s) {
    if (max == s.size()) {
        dictionary.push_back(s);
        return;
    }

    for (char i: alphabet) {
        dfs(max, s + i);
    }
}

int solution(string word) {
    for (int i = 1; i <= 5; i++) {
        dfs(i, "");
    }

    sort(dictionary.begin(), dictionary.end());
    auto answer = std::find(dictionary.begin(), dictionary.end(), word) - dictionary.begin() + 1;
    return static_cast<int>(answer);
}

int main() {
#ifdef TEST
    cout << solution("I") << endl;
#endif
    return 0;
}
