#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        static constexpr array<pair<int, int>, 4> d = {
            {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
        };

        auto bfs = [&](int row, int col) {
            queue<pair<int, int>> q;
            q.push({row, col});
            visited[row][col] = true;

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc] : d) {
                    int nr = r + dr;
                    int nc = c+ dc;

                    if (nr >= 0 && nr < grid.size() &&
                        nc >= 0 && nc < grid[0].size() && 
                        !visited[nr][nc] &&
                        grid[nr][nc] == '1') {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }


                }
            }
        };

        int result = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i,j);
                    ++result;
                }
            }
        }
        return result;
    }
};