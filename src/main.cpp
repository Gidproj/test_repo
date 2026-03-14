#include "list_builder.h"
#include "list_serializer.h"
#include <iostream>

int main() {
    try {
        ListNode* head = buildListFromFile("../input/inlet.in");
        serializeList(head, "../output/outlet.out");
        freeList(head);

        std::cout << "Done\n";
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
        return 1;
    }

    return 0;
}