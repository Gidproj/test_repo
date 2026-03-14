#include "list_serializer.h"
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdexcept>

void serializeList(ListNode* head, const std::string& filename) {
    std::ofstream out(filename, std::ios::binary);

    if (!out)
        throw std::runtime_error("Cannot open output file");

    std::vector<ListNode*> nodes;
    std::unordered_map<ListNode*, uint32_t> indexMap;

    ListNode* current = head;
    uint32_t index = 0;

    while (current) {
        nodes.push_back(current);
        indexMap[current] = index++;
        current = current->next;
    }

    uint32_t count = nodes.size();
    out.write(reinterpret_cast<char*>(&count), sizeof(count));

    for (auto* node : nodes) {
        uint32_t len = node->data.size();
        out.write(reinterpret_cast<char*>(&len), sizeof(len));
        out.write(node->data.data(), len);

        int32_t randIndex = -1;
        if (node->rand)
            randIndex = indexMap[node->rand];

        out.write(reinterpret_cast<char*>(&randIndex), sizeof(randIndex));
    }
}

void freeList(ListNode* head) {
    while (head) {
        auto* next = head->next;
        delete head;
        head = next;
    }
}