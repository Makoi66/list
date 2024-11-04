#include "gtest.h"
#include "tlist.h"


TEST(ListTest, PushBackOneElement) {
    List<int> list;
    list.push_back(1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 1);
}

TEST(ListTest, PushBackMultipleElements) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 3);
}



TEST(ListTest, PushFrontOneElement) {
    List<int> list;
    list.push_front(1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 1);
}

TEST(ListTest, PushFrontMultipleElements) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), 3);
    EXPECT_EQ(list.back(), 1);
}

TEST(ListTest, PopFrontFromNotEmptyList) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.back(), 2);
}

TEST(ListTest, PopFrontUntilEmpty) {
    List<int> list;
    list.push_back(1);
    list.pop_front();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(ListTest, PopFrontFromEmptyList) {
    List<int> emptyList;
    ASSERT_THROW(emptyList.pop_front(), std::out_of_range);
}


TEST(ListTest, PopBackFromNotEmptyList) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 1);
}

TEST(ListTest, PopBackUntilEmpty) {
    List<int> list;
    list.push_back(1);
    list.pop_back();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(ListTest, PopBackFromEmptyList) {
    List<int> emptyList;
    ASSERT_THROW(emptyList.pop_back(), std::out_of_range);
}


TEST(ListTest, FrontNotEmptyList) {
    List<int> list;
    list.push_back(1);
    EXPECT_EQ(list.front(), 1);

}

TEST(ListTest, FrontModify) {
    List<int> list;
    list.push_back(1);
    list.front() = 10;
    EXPECT_EQ(list.front(), 10);
}

TEST(ListTest, FrontEmptyList) {
    List<int> emptyList;
    ASSERT_THROW(emptyList.front(), std::out_of_range);
}


TEST(ListTest, BackNotEmptyList) {
    List<int> list;
    list.push_back(1);
    EXPECT_EQ(list.back(), 1);
}

TEST(ListTest, BackModify) {
    List<int> list;
    list.push_back(1);
    list.back() = 10;
    EXPECT_EQ(list.back(), 10);
}
TEST(ListTest, BackEmptyList) {
    List<int> emptyList;
    ASSERT_THROW(emptyList.back(), std::out_of_range);
}


TEST(ListTest, EmptyTrue) {
    List<int> list;
    EXPECT_TRUE(list.empty());
}


TEST(ListTest, EmptyFalse) {
    List<int> list;
    list.push_back(1);
    EXPECT_FALSE(list.empty());
}


TEST(ListTest, SizeEmpty) {
    List<int> list;
    EXPECT_EQ(list.size(), 0);
}

TEST(ListTest, SizeNotEmpty) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.size(), 2);
}


TEST(ListTest, ClearNotEmptyList) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(ListTest, ClearEmptyList) {
    List<int> list;
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}


TEST(ListTest, SortEmptyList) {
    List<int> list;
    list.sort();
    EXPECT_TRUE(list.empty());
}

TEST(ListTest, SortOneElementList) {
    List<int> list;
    list.push_back(1);
    list.sort();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 1);
}

TEST(ListTest, SortMultipleElements) {
    List<int> list;
    list.push_back(3);
    list.push_back(1);
    list.push_back(2);
    list.sort();


    List<int>::iterator it = list.begin();
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(*it++, 3);
    EXPECT_EQ(it, list.end());
}



TEST(ListTest, ReverseEmptyList) {
    List<int> list;
    list.reverse();
    EXPECT_TRUE(list.empty());
}

TEST(ListTest, ReverseOneElementList) {
    List<int> list;
    list.push_back(1);
    list.reverse();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 1);
}


TEST(ListTest, ReverseMultipleElements) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.reverse();

    List<int>::iterator it = list.begin();
    EXPECT_EQ(*it++, 3);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(it, list.end());
}


TEST(ListTest, InsertBegin) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.insert(list.begin(), 0);
    List<int>::iterator it = list.begin();

    EXPECT_EQ(*it++, 0);
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(it, list.end());
}


TEST(ListTest, InsertMiddle) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::iterator it = list.begin();

    list.insert(++it, 3);

    it = list.begin();

    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 3);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(it, list.end());
}


TEST(ListTest, InsertEnd) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.insert(list.end(), 3);

    List<int>::iterator it = list.begin();

    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(*it++, 3);
    EXPECT_EQ(it, list.end());
}


TEST(ListTest, InsertEmptyList) {
    List<int> list;
    list.insert(list.begin(), 1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 1);
}


TEST(ListTest, EraseBegin) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.erase(list.begin());

    List<int>::iterator it = list.begin();

    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(it, list.end());
}


TEST(ListTest, EraseMiddle) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    List<int>::iterator it = list.begin();
    ++it;
    list.erase(it);

    it = list.begin();
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 3);
    EXPECT_EQ(it, list.end());
}


TEST(ListTest, EraseEnd) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);


    List<int>::iterator it = list.begin();

    std::advance(it, 2);

    list.erase(it);

    it = list.begin();
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(it, list.end());
}


TEST(ListTest, EraseEmptyList) {
    List<int> emptyList;
    ASSERT_THROW(emptyList.erase(emptyList.begin()), std::runtime_error);
}
