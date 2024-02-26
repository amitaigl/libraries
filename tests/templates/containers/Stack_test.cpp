#include <iostream>

#include "Stack.hpp"
#include "../test_func.hpp"

using namespace AG;

int main()
{
    Stack<int, std::deque<int>> s1;

    TEST(s1.empty());
    TEST(0 == s1.size());

    s1.push(5);
    TEST(1 == s1.size());
    TEST(5 == s1.top());
    s1.push(6);
    TEST(2 == s1.size());
    TEST(6 == s1.top());
    s1.pop();
    TEST(1 == s1.size());
    TEST(5 == s1.top());

    // Test for swap
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    TEST(5 == s1.size());
    TEST(8 == s1.top());
    Stack<int, std::deque<int>> s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    TEST(4 == s2.top());
    s1.swap(s2);
    TEST(4 == s1.top());
    TEST(8 == s2.top());

    // Test for asignment operator
    Stack<int, std::deque<int>> s3;
    s3 = s2;
    TEST(8 == s3.top());

    // Test for cctor:
    Stack<int> s4(s3);
    TEST(8 == s3.top());

    return 0;
}