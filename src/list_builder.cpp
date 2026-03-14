#include "list_builder.h"
#include <fstream>
#include <vector>
#include <stdexcept>

ListNode* buildListFromFile(const std::string& filename) {
    std::ifstream in(filename);

    if (!in)
        throw std::runtime_error("Cannot open input file");

    std::vector<ListNode*> nodes;
    std::vector<int> randIndices;
    std::string line;

    while (std::getline(in, line)) {
        auto pos = line.rfind(';');

        if (pos == std::string::npos)
            throw std::runtime_error("Invalid input format");

        std::string data = line.substr(0, pos);
        int randIndex = std::stoi(line.substr(pos + 1));

        auto* node = new ListNode();
        node->data = data;

        if (!nodes.empty()) {
            node->prev = nodes.back();
            nodes.back()->next = node;
        }

        nodes.push_back(node);
        randIndices.push_back(randIndex);
    }

    for (size_t i = 0; i < nodes.size(); ++i) {
        if (randIndices[i] >= 0)
            nodes[i]->rand = nodes[randIndices[i]];
    }

    return nodes.empty() ? nullptr : nodes.front();
}