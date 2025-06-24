/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

    ListNode *res;

    while (list1 != nullptr || list2 != nullptr) {
      if (list1 == nullptr) {
        res->next = list2;
        break;
      }

      if (list2 == nullptr) {
        res->next = list2;
        break;
      }

      int val1 = list1->val;
      int val2 = list2->val;

      if (val1 >= val2) {
        // attach val2;
        res->next = new ListNode(val2);
        list2 = list2->next;
      } else {
        // attach val1
        res->next = new ListNode(val1);
        list1 = list1->next;
      }
    }
    return res;
  }
};