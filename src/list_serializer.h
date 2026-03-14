#pragma once
#include <string>

struct ListNode {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* rand = nullptr;
    std::string data;
};

void serializeList(ListNode* head, const std::string& filename);
void freeList(ListNode* head);