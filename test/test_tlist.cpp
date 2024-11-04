#include "gtest.h"
#include "tlist.h"
#include <algorithm> // для std::reverse

template <typename T>
void addToList(List<T>& lst, int num) {
    lst.reverse();

    typename List<T>::iterator it = lst.begin();
    int carry = num;

    while (carry > 0 || it != lst.end()) {
        if (it != lst.end()) {
            carry += *it;
            *it = carry % 10; 
            carry /= 10;
            ++it;
        }
        else {
            lst.push_back(carry % 10);
            carry /= 10;
        }
    }

    lst.reverse();
}

//helper
template <typename T>
int listToNumber(const List<T>& lst) {
    int result = 0;
    for (const auto& digit : lst) {
        result = result * 10 + digit;
    }
    return result;
}




TEST(ListTest, NoEmptyNoEmpty) {
    List<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3); // List: 123

    addToList(lst, 987); // 123 + 987 = 1110

    EXPECT_EQ(listToNumber(lst), 1110);
}


TEST(ListTest, AddToEmptyList) {
    List<int> lst;  // Empty list
    addToList(lst, 5);
    EXPECT_EQ(listToNumber(lst), 5);
}


TEST(ListTest, EmptyNoEmpty) {
    List<int> lst;
    addToList(lst, 987);

    addToList(lst, 123);

    EXPECT_EQ(listToNumber(lst), 1110);
}


TEST(ListTest, AddZeroToSingleElementList) {
    List<int> lst;
    lst.push_back(3);

    addToList(lst, 0);
    EXPECT_EQ(listToNumber(lst), 3);
}


TEST(ListTest, AddSmallNumberWithoutCarry) {
    List<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    addToList(lst, 4);
    EXPECT_EQ(listToNumber(lst), 127);
}


TEST(ListTest, AddSmallNumberWithCarry) {
    List<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(9);

    addToList(lst, 3);
    EXPECT_EQ(listToNumber(lst), 132);
}


TEST(ListTest, AddWithMultipleCarries) {
    List<int> lst;
    lst.push_back(9);
    lst.push_back(9);
    lst.push_back(9);

    addToList(lst, 1);
    EXPECT_EQ(listToNumber(lst), 1000);
}


TEST(ListTest, AddLargeNumber) {
    List<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(8);
    lst.push_back(9);

    addToList(lst, 987654321);
    EXPECT_EQ(listToNumber(lst), 1111111110);
}


TEST(ListTest, AddToSingleElementList) {
    List<int> lst;
    lst.push_back(9);

    addToList(lst, 8);
    EXPECT_EQ(listToNumber(lst), 17);
}


TEST(ListTest, AddWithLeadingZeros) {
    List<int> lst;
    lst.push_back(1);
    lst.push_back(0);
    lst.push_back(0);
    lst.push_back(0);

    addToList(lst, 23);
    EXPECT_EQ(listToNumber(lst), 1023);
}


TEST(ListTest, ReverseCheckAfterAddition) {
    List<int> lst;
    lst.push_back(8);
    lst.push_back(7);
    lst.push_back(6);
    lst.push_back(5);
    lst.push_back(4);
    lst.push_back(3);
    lst.push_back(2);
    lst.push_back(1);
    lst.push_back(0);

    addToList(lst, 123456790);
    EXPECT_EQ(listToNumber(lst), 1000000000);  // Should result in a billion exactly
}


TEST(ListTest, AddToExtendList) {
    List<int> lst;
    lst.push_back(5);

    addToList(lst, 995);
    EXPECT_EQ(listToNumber(lst), 1000);
}
