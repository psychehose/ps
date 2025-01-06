#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <json.hpp> // Include the JSON library

using json = nlohmann::json;

int main() {
    // 문제 리스트 생성
    std::vector<std::pair<int, std::string>> easyProblems = {
        {1, "Two Sum"}, {141, "Linked List Cycle"}, {268, "Missing Number"},
        {190, "Reverse Bits"}, {191, "Number of 1 Bits"}, {70, "Climbing Stairs"},
        {206, "Reverse Linked List"}, {217, "Contains Duplicate"},
        {226, "Invert Binary Tree"}, {100, "Same Tree"}, {104, "Maximum Depth of Binary Tree"},
        {242, "Valid Anagram"}, {338, "Counting Bits"}, {252, "Meeting Rooms"},
        {121, "Best Time to Buy and Sell Stock"}, {125, "Valid Palindrome"}
    };

    std::vector<std::pair<int, std::string>> mediumProblems = {
        {128, "Longest Consecutive Sequence"}, {3, "Longest Substring Without Repeating Characters"},
        {5, "Longest Palindromic Substring"}, {133, "Clone Graph"},
        {261, "Graph Valid Tree"}, {647, "Palindromic Substrings"},
        {11, "Container With Most Water"}, {139, "Word Break"},
        {15, "3Sum"}, {143, "Reorder List"}, {271, "Encode and Decode Strings"},
        {19, "Remove Nth Node From End of List"}, {20, "Valid Parentheses"},
        {21, "Merge Two Sorted Lists"}, {23, "Merge k Sorted Lists"},
        {152, "Maximum Product Subarray"}, {153, "Find Minimum in Rotated Sorted Array"},
        {33, "Search in Rotated Sorted Array"}, {417, "Pacific Atlantic Water Flow"},
        {39, "Combination Sum"}, {424, "Longest Repeating Character Replacement"},
        {300, "Longest Increasing Subsequence"}, {48, "Rotate Image"},
        {49, "Group Anagrams"}, {53, "Maximum Subarray"}, {54, "Spiral Matrix"},
        {55, "Jump Game"}, {56, "Merge Intervals"}, {57, "Insert Interval"},
        {62, "Unique Paths"}, {322, "Coin Change"}, {207, "Course Schedule"},
        {208, "Implement Trie (Prefix Tree)"}, {198, "House Robber"},
        {200, "Number of Islands"}, {73, "Set Matrix Zeroes"}
    };

    std::vector<std::pair<int, std::string>> hardProblems = {
        {269, "Alien Dictionary"}, {295, "Find Median from Data Stream"},
        {297, "Serialize and Deserialize Binary Tree"}, {76, "Minimum Window Substring"},
        {212, "Word Search II"}, {124, "Binary Tree Maximum Path Sum"}
    };

    // 랜덤 시드 초기화
    std::srand(static_cast<unsigned int>(std::time(0)));

    // enable 상태 확인 (하드코딩된 예제, 실제로는 외부 입력으로 받을 수 있음)
    bool enableHard = true;

    // 랜덤 인덱스 선택
    int randomEasyIndex = std::rand() % easyProblems.size();
    int randomMediumIndex = std::rand() % mediumProblems.size();
    int randomHardIndex = enableHard ? (std::rand() % hardProblems.size()) : -1;

    // JSON 파일 저장을 위한 데이터 구조
    json outputJson;

    // 선택된 문제 추가
    outputJson["Easy"] = {
        {"id", easyProblems[randomEasyIndex].first},
        {"title", easyProblems[randomEasyIndex].second}
    };
    outputJson["Medium"] = {
        {"id", mediumProblems[randomMediumIndex].first},
        {"title", mediumProblems[randomMediumIndex].second}
    };
    if (enableHard) {
        outputJson["Hard"] = {
            {"id", hardProblems[randomHardIndex].first},
            {"title", hardProblems[randomHardIndex].second}
        };
    }

    // JSON 출력
    std::ofstream outputFile("selected_problems.json");
    outputFile << outputJson.dump(4); // JSON 데이터를 파일에 저장 (4는 들여쓰기 수준)
    outputFile.close();

    // 콘솔 출력
    std::cout << "Today's Easy problem: [" << easyProblems[randomEasyIndex].first << "] "
              << easyProblems[randomEasyIndex].second << std::endl;
    std::cout << "Today's Medium problem: [" << mediumProblems[randomMediumIndex].first << "] "
              << mediumProblems[randomMediumIndex].second << std::endl;
    if (enableHard) {
        std::cout << "Today's Hard problem: [" << hardProblems[randomHardIndex].first << "] "
                  << hardProblems[randomHardIndex].second << std::endl;
    }

    return 0;
}
