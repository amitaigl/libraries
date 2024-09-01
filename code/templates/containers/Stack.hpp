#pragma once

#include <deque>
#include <algorithm>
#include <cstddef>  // size_t

namespace AG
{
template <class T, class Container = std::deque<T>>
class Stack
{
public:
    Stack()
    {
        //empty
    }

    Stack(const Stack &other)
    {
        m_container = other.m_container;
    }

    Stack &operator=(const Stack &other)
    {
        m_container = other.m_container;
        return *this;
    }

    ~Stack()
    {
        // empty
    }

    T top()
    {
        return m_container.back();
    }

    bool empty()
    {
        return m_container.empty();
    }

    size_t size()
    {
        return m_container.size();
    }

    void push(T value)
    {
        m_container.push_back(value);
    }

    void emplace(T value)
    {
        m_container.emplace_back(value);
    }

    void pop()
    {
        m_container.pop_back();
    }

    void swap(Stack &other)
    {
        m_container.swap(other.m_container);
    }

private:
    Container m_container;

};

} // AG