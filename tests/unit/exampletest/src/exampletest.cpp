// 
// Most of the following code was produced using generative artificial intelligence.
// 

#include <gtest/gtest.h>
#include <vectorimpl/vector.hpp>
#include <utility>

// Test fixture for dev::vector
class VectorTest : public ::testing::Test {
protected:
    dev::vector<int> vec;
};

// Test iterators
TEST_F(VectorTest, Iterators) {
    vec = {1, 2, 3, 4, 5};
    auto it = vec.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(*(vec.end() - 1), 5);
}

// Test Rule of 5
TEST_F(VectorTest, RuleOfFive) {
    dev::vector<int> other = {1, 2, 3};
    dev::vector<int> copy(other);
    EXPECT_EQ(copy.size(), 3);
    EXPECT_EQ(copy[1], 2);

    dev::vector<int> moved(std::move(copy));
    EXPECT_EQ(moved.size(), 3);
    EXPECT_EQ(moved[1], 2);
}

// Test fill constructor
TEST_F(VectorTest, FillConstructor) {
    dev::vector<int> filled(5, 42);
    EXPECT_EQ(filled.size(), 5);
    EXPECT_EQ(filled[0], 42);
    EXPECT_EQ(filled[4], 42);
}

// Test at method
TEST_F(VectorTest, AtMethod) {
    vec = {10, 20, 30};
    EXPECT_EQ(vec.at(0), 10);
    EXPECT_EQ(vec.at(2), 30);
    EXPECT_THROW(vec.at(5), std::out_of_range);
}

// Test operator[]
TEST_F(VectorTest, BracketOperator) {
    vec = {5, 10, 15};
    EXPECT_EQ(vec[0], 5);
    EXPECT_EQ(vec[2], 15);
}

// Test front and back
TEST_F(VectorTest, FrontAndBack) {
    vec = {100, 200, 300};
    EXPECT_EQ(vec.front(), 100);
    EXPECT_EQ(vec.back(), 300);
}

// Test data method
TEST_F(VectorTest, DataMethod) {
    vec = {7, 14, 21};
    int* ptr = vec.data();
    EXPECT_EQ(ptr[0], 7);
    EXPECT_EQ(ptr[1], 14);
}

// Test empty method
TEST_F(VectorTest, EmptyMethod) {
    EXPECT_TRUE(vec.empty());
    vec.push_back(1);
    EXPECT_FALSE(vec.empty());
}

// Test size method
TEST_F(VectorTest, SizeMethod) {
    vec = {1, 2, 3};
    EXPECT_EQ(vec.size(), 3);
}

// Test reserve and capacity
TEST_F(VectorTest, ReserveAndCapacity) {
    vec.reserve(50);
    EXPECT_GE(vec.capacity(), 50);
}

// Test clear
TEST_F(VectorTest, Clear) {
    vec = {1, 2, 3, 4};
    vec.clear();
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}

// Test insert
TEST_F(VectorTest, Insert) {
    vec = {1, 2, 4};
    vec.insert(vec.begin() + 2, 3);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec.size(), 4);
}

// Test erase
TEST_F(VectorTest, Erase) {
    vec = {10, 20, 30, 40};
    vec.erase(vec.begin() + 1);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[1], 30);
}

// Test push_back
TEST_F(VectorTest, PushBack) {
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

// Test pop_back
TEST_F(VectorTest, PopBack) {
    vec.push_back(10);
    vec.push_back(20);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec.back(), 10);
}
