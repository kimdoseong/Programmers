//
// Created by kimdoseong on 2022/10/10.
//

/**
 * 여행경로
 * DFS / BFS
 */

#ifdef TEST

#include <iostream>

#endif

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(const string &cur, vector<vector<string>> &tickets, vector<bool> &visited, vector<string> &result, int last) {
    if (result.size() == tickets.size()) {
        result.emplace_back(tickets[last][1]);
        return true;
    }

    for (auto i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == cur) {
            visited[i] = true;
            result.emplace_back(cur);
            bool ret = dfs(tickets[i][1], tickets, visited, result, i);
            if (ret) {
                return true;
            }
            visited[i] = false;
            result.pop_back();
        }
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), [](const vector<string> &t1, const vector<string> &t2) {
        return t1[1] < t2[1];
    });

    vector<bool> visited(tickets.size());
    vector<string> answer;
    dfs("ICN", tickets, visited, answer, 0);

    return answer;
}

int main() {
#ifdef TEST
    auto v = solution({{"ICN", "SFO"},
                       {"ICN", "ATL"},
                       {"SFO", "ATL"},
                       {"ATL", "ICN"},
                       {"ATL", "SFO"}}

    );
    for_each(v.begin(), v.end(), [](const string &s) {
        cout << s << " ";
    });
#endif
}