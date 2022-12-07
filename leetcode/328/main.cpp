#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // o -> x -> o -> x
        // o ---> o  -> x
        //    x -> 
        // o --> o  -> x
        //         x ->
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* root = head;
        ListNode* oddRoot = head->next;
        ListNode* evenPtr = head;
        ListNode* oddPtr = head->next;
        while (oddPtr->next != nullptr && (evenPtr->next != nullptr)) {
            if (evenPtr->next->next != nullptr) {
                evenPtr->next = evenPtr->next->next;
                evenPtr = evenPtr->next;
            }
            if (oddPtr->next->next != nullptr) {
                oddPtr->next = oddPtr->next->next;
                oddPtr = oddPtr->next;
            }
        }
        evenPtr->next = oddRoot;
        return root;
    }
};

int main() {
  
}