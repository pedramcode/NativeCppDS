#include <iostream>

#include "cppds/linked_list.hpp"

int main(){
    // ============================== LinkedList ==============================
    cppds::LinkedList<int> linked_list;
    linked_list.push_back(3);
    linked_list.push_back(7);
    linked_list.push_back(7);
    linked_list.push_front(1);
    linked_list.push_front(123);
    linked_list.pop_front();
    linked_list.push_back(321);
    linked_list.pop_back();

    int expected[] = {1,3,7,7};
    size_t ll_i = 0;
    for(const auto& item: linked_list){
        if(expected[ll_i] != item){
            std::cerr << "Linked list items are incorrect" << std::endl;
            return 1;
        }
        ll_i++;
    }
    return 0;
}