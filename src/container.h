#pragma once

template <class T, class Allocator>
class container
{
private:
    struct Node
    {
        T value;
        Node* next;

        explicit Node (T&& value):value(std::forward<T>(value)), next(nullptr){}
    };

    struct Iterator
    {
        Node* node;

        explicit Iterator(Node* value) : node(value){}

        T& operator->() { return node->value; }
        T* operator*() { return &node->value; }
        bool operator==(const Iterator& rhs) { return node == rhs.node; }
        bool operator!=(const Iterator& rhs) { return node != rhs.node; }

        Iterator& operator++() //++a
        {
            if(node != nullptr)
            {
                node = node->next;
            }
            return *this;
        }

        Iterator operator++(int) //a++
        {
            Node* temp = node;
            if(node->value != nullptr)
            {
                node = node->next;
            }
            return Iterator{temp};
        }
    };

private:
    Node* _head;
    Node* _tail;
    using Alloc = typename Allocator::template rebind<Node>::other;
    Alloc _allocator;

public:
    template<typename... Args>
    void push(Args &&...args)
    {
        Node* node = _allocator.allocate(1);
        _allocator.construct(node, std::forward<Args>(args)...);

        if(_head == nullptr)
        {
            _head = node;
            _tail = node;
            return;
        }

        node->next = _tail;
        _tail = node;
    }

    ~container()
    {
        while(_head != nullptr)
        {
            Node* node = _head;
            _head = node->next;

            _allocator.destroy(node);
            _allocator.deallocate(node, 1);
        }
    }

    Iterator begin()
    {
        return Iterator(_head);
    }

    Iterator end()
    {
        return Iterator(_tail == nullptr ? _tail : _tail->next);
    }
};
