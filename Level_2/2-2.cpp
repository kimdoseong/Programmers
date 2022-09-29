//
// Created by kimdoseong on 2022/10/09.
//

/**
 * 게임 맵 최단거리
 * DFS / BFS
 */

#ifdef TEST

#include <iostream>

#endif

#include <vector>
#include <queue>
#include <array>

using namespace std;
std::array<std::pair<int, int>, 4> dist = {{{-1, 0},
                                            {1, 0},
                                            {0, -1},
                                            {0, 1}}};
vector<vector<bool>> visited;
struct Robot {
    int x = 0;
    int y = 0;
    int step = 1;
};

queue<Robot> q;

void BFS(const vector<vector<int>> &maps, const Robot &robot) {
    auto max_x = maps.size();
    auto max_y = maps[0].size();

    for (const auto &i: dist) {
        auto new_x = robot.x + i.first;
        auto new_y = robot.y + i.second;

        if (new_x >= 0 && new_y >= 0 &&
            new_x < max_x && new_y < max_y &&
            maps[new_x][new_y] && !visited[new_x][new_y]) {
            q.push({new_x, new_y, robot.step + 1});

            visited[new_x][new_y] = true;
        }
    }
}

int solution(vector<vector<int>> maps) {
    const auto max_x = maps.size();
    const auto max_y = maps[0].size();

    visited.resize(max_x, vector<bool>(max_y));
    q.push(Robot{0, 0, 1});
    visited[0][0] = true;

    while (!q.empty()) {
        auto robot = q.front();
        q.pop();

        if (robot.x == max_x - 1 && robot.y == max_y - 1) {
            return robot.step;
        }

        BFS(maps, robot);
    }

    return -1;
}

int main() {
#ifdef TEST
    cout << solution({
                             {1, 0, 1, 1, 1},
                             {1, 0, 1, 0, 1},
                             {1, 0, 1, 1, 1},
                             {1, 1, 1, 0, 1},
                             {0, 0, 0, 0, 1}}) << endl;
#endif
}