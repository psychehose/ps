#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int maxPoints(vector<int> &costs, int k) {
    int n = costs.size();
    int maxPoints = 0;

    // 1. 스킵 없이 연속으로 갈 수 있는 최대 포인트
    int completedLevels = 0;
    int money = k;
    for (int i = 0; i < n; i++) {
      if (money >= costs[i]) {
        money -= costs[i];
        completedLevels++;
      } else {
        break;
      }
    }
    maxPoints = completedLevels;

    // 2. 각 레벨을 스킵했을 때의 최대 포인트
    for (int skip = 0; skip < n; skip++) {
      int points = 0;
      money = k;

      // skip 이전까지의 비용과 포인트
      for (int i = 0; i < skip; i++) {
        if (money >= costs[i]) {
          money -= costs[i];
          points++;
        } else {
          break;
        }
      }

      // skip 이후부터의 비용과 포인트
      for (int i = skip + 1; i < n; i++) {
        if (money >= costs[i]) {
          money -= costs[i];
          points++;
        } else {
          break;
        }
      }

      maxPoints = max(maxPoints, points);
    }

    return maxPoints;
  }
};

// 테스트 함수
void runTest(vector<int> &costs, int k) {
  Solution sol;
  int result = sol.maxPoints(costs, k);

  cout << "Money: " << k << ", Costs: [";
  for (size_t i = 0; i < costs.size(); i++) {
    cout << costs[i];
    if (i < costs.size() - 1)
      cout << ", ";
  }
  cout << "]\n";
  cout << "결과: " << result << "\n";

  // 스킵 없이 진행하는 경우 계산
  cout << "\n스킵 없이 진행하는 경우: ";
  int points = 0;
  int money = k;
  for (int i = 0; i < (int)costs.size(); i++) {
    if (money >= costs[i]) {
      points++;
      money -= costs[i];
      cout << i + 1 << "(값: " << costs[i] << ", 남은돈: " << money << ") ";
    } else {
      cout << "[돈 부족] ";
      break;
    }
  }
  cout << "=> " << points << " 포인트\n";

  // 각 레벨을 스킵하는 경우 계산
  for (int skipLevel = 0; skipLevel < (int)costs.size(); skipLevel++) {
    points = 0;
    money = k;
    cout << "레벨 " << skipLevel + 1 << "(값: " << costs[skipLevel]
         << ") 스킵: ";

    for (int i = 0; i < (int)costs.size(); i++) {
      if (i == skipLevel) {
        cout << "[스킵] ";
        continue;
      }

      if (money >= costs[i]) {
        points++;
        money -= costs[i];
        cout << i + 1 << "(값: " << costs[i] << ", 남은돈: " << money << ") ";
      } else {
        cout << "[돈 부족] ";
        break;
      }
    }
    cout << "=> " << points << " 포인트\n";
  }

  cout << "\n";
}

int main() {
  // 원래 예제
  vector<int> costs1 = {2, 4, 1, 8, 6};
  runTest(costs1, 14);

  // 새로운 테스트 케이스 1
  vector<int> costs2 = {6, 3, 2, 6, 4, 6, 1};
  runTest(costs2, 15);

  // 새로운 테스트 케이스 2
  vector<int> costs3 = {1, 7};
  runTest(costs3, 3);

  return 0;
}