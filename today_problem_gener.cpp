#include "json.hpp" // Include the JSON library
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using json = nlohmann::json;

// 이미 해결한 문제 목록을 불러오는 함수
std::vector<int> loadSolvedProblems() {
  std::vector<int> solvedProblems;
  std::ifstream file("selected_problems.json");

  if (file.is_open()) {
    try {
      json j;
      file >> j;

      // JSON 배열에서 문제 번호 추출
      for (const auto &item : j) {
        solvedProblems.push_back(item.get<int>());
      }
    } catch (const std::exception &e) {
      std::cerr << "Error parsing JSON: " << e.what() << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Could not open selected_problems.json" << std::endl;
  }

  return solvedProblems;
}

// 아직 풀지 않은 문제 중에서 랜덤으로 선택하는 함수
int getRandomUnsolvedProblem(
    const std::vector<std::pair<int, std::string>> &problems,
    const std::vector<int> &solvedProblems) {
  std::vector<int> unsolvedIndices;

  // 아직 풀지 않은 문제 인덱스 찾기
  for (size_t i = 0; i < problems.size(); i++) {
    int problemId = problems[i].first;
    if (std::find(solvedProblems.begin(), solvedProblems.end(), problemId) ==
        solvedProblems.end()) {
      unsolvedIndices.push_back(i);
    }
  }

  // 풀지 않은 문제가 없는 경우
  if (unsolvedIndices.empty()) {
    return -1;
  }

  // 랜덤으로 선택
  int randomIndex = std::rand() % unsolvedIndices.size();
  return unsolvedIndices[randomIndex];
}

int main() {
  // 문제 리스트 생성
  std::vector<std::pair<int, std::string>> easyProblems = {
      {1, "Two Sum"},
      {141, "Linked List Cycle"},
      {268, "Missing Number"},
      {190, "Reverse Bits"},
      {191, "Number of 1 Bits"},
      {70, "Climbing Stairs"},
      {206, "Reverse Linked List"},
      {217, "Contains Duplicate"},
      {226, "Invert Binary Tree"},
      {100, "Same Tree"},
      {104, "Maximum Depth of Binary Tree"},
      {242, "Valid Anagram"},
      {338, "Counting Bits"},
      {252, "Meeting Rooms"},
      {121, "Best Time to Buy and Sell Stock"},
      {125, "Valid Palindrome"}};

  std::vector<std::pair<int, std::string>> mediumProblems = {
      {128, "Longest Consecutive Sequence"},
      {3, "Longest Substring Without Repeating Characters"},
      {5, "Longest Palindromic Substring"},
      {133, "Clone Graph"},
      {261, "Graph Valid Tree"},
      {647, "Palindromic Substrings"},
      {11, "Container With Most Water"},
      {139, "Word Break"},
      {15, "3Sum"},
      {143, "Reorder List"},
      {271, "Encode and Decode Strings"},
      {19, "Remove Nth Node From End of List"},
      {20, "Valid Parentheses"},
      {21, "Merge Two Sorted Lists"},
      {23, "Merge k Sorted Lists"},
      {152, "Maximum Product Subarray"},
      {153, "Find Minimum in Rotated Sorted Array"},
      {33, "Search in Rotated Sorted Array"},
      {417, "Pacific Atlantic Water Flow"},
      {39, "Combination Sum"},
      {424, "Longest Repeating Character Replacement"},
      {300, "Longest Increasing Subsequence"},
      {48, "Rotate Image"},
      {49, "Group Anagrams"},
      {53, "Maximum Subarray"},
      {54, "Spiral Matrix"},
      {55, "Jump Game"},
      {56, "Merge Intervals"},
      {57, "Insert Interval"},
      {62, "Unique Paths"},
      {322, "Coin Change"},
      {207, "Course Schedule"},
      {208, "Implement Trie (Prefix Tree)"},
      {198, "House Robber"},
      {200, "Number of Islands"},
      {73, "Set Matrix Zeroes"}};

  std::vector<std::pair<int, std::string>> hardProblems = {
      {269, "Alien Dictionary"},
      {295, "Find Median from Data Stream"},
      {297, "Serialize and Deserialize Binary Tree"},
      {76, "Minimum Window Substring"},
      {212, "Word Search II"},
      {124, "Binary Tree Maximum Path Sum"}};

  // 랜덤 시드 초기화
  std::srand(static_cast<unsigned int>(std::time(0)));

  // 이미 해결한 문제 목록 불러오기
  std::vector<int> solvedProblems = loadSolvedProblems();

  // 사용자 입력 받기
  std::string difficulty;
  bool validInput = false;

  while (!validInput) {
    std::cout << "난이도를 입력하세요 (easy, medium, hard): ";
    std::cin >> difficulty;

    // 소문자로 변환
    std::transform(difficulty.begin(), difficulty.end(), difficulty.begin(),
                   ::tolower);

    if (difficulty == "easy" || difficulty == "medium" ||
        difficulty == "hard") {
      validInput = true;
    } else {
      std::cout << "잘못된 입력입니다. easy, medium, hard 중 하나를 입력하세요."
                << std::endl;
    }
  }

  // 선택된 난이도에 따라 랜덤 문제 선택
  int selectedIndex = -1;

  if (difficulty == "easy") {
    selectedIndex = getRandomUnsolvedProblem(easyProblems, solvedProblems);
    if (selectedIndex != -1) {
      std::cout << "Today's Easy problem: ["
                << easyProblems[selectedIndex].first << "] "
                << easyProblems[selectedIndex].second << std::endl;
    } else {
      std::cout << "모든 Easy 문제를 이미 해결했습니다!" << std::endl;
    }
  } else if (difficulty == "medium") {
    selectedIndex = getRandomUnsolvedProblem(mediumProblems, solvedProblems);
    if (selectedIndex != -1) {
      std::cout << "Today's Medium problem: ["
                << mediumProblems[selectedIndex].first << "] "
                << mediumProblems[selectedIndex].second << std::endl;
    } else {
      std::cout << "모든 Medium 문제를 이미 해결했습니다!" << std::endl;
    }
  } else if (difficulty == "hard") {
    selectedIndex = getRandomUnsolvedProblem(hardProblems, solvedProblems);
    if (selectedIndex != -1) {
      std::cout << "Today's Hard problem: ["
                << hardProblems[selectedIndex].first << "] "
                << hardProblems[selectedIndex].second << std::endl;
    } else {
      std::cout << "모든 Hard 문제를 이미 해결했습니다!" << std::endl;
    }
  }

  return 0;
}
