#include <iostream>

#include "cppds/linked_list.hpp"
#include "cppds/dynamic_array.hpp"

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

    // ============================== DynamicArray ==============================
    cppds::DynamicArray<int> list1;
    list1.push_back(1);
    list1.push_back(3);
    list1.push_back(7);
    list1.push_back(7);

    ll_i = 0;
    for(const auto& item: linked_list){
        if(expected[ll_i] != item){
            std::cerr << "Dynamic array items are incorrect" << std::endl;
            return 1;
        }
        ll_i++;
    }

    cppds::DynamicArray<int> list2(8);
    list2.push_back(1);
    list2.push_back(3);
    list2.push_back(7);
    list2.push_back(7);

    list2.push_back(1);
    list2.push_back(3);
    list2.push_back(7);
    list2.push_back(7);

    list2.push_back(1);
    list2.push_back(3);
    list2.push_back(7);
    list2.push_back(7);
    list2.pop_back();

    int expected_2[] = {1,3,7,7,1,3,7,7,1,3,7,};
    size_t ll_i_2 = 0;
    for(const auto& item: linked_list){
        if(expected_2[ll_i_2] != item){
            std::cerr << "Dynamic array items are incorrect" << std::endl;
            return 1;
        }
        ll_i_2++;
    }

    if(list1[1] != list2[1]){
        std::cerr << "Dynamic array items are incorrect" << std::endl;
        return 1;
    }

    return 0;
}