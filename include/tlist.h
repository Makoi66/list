#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>

template <typename T>
class List {
private:
    template <typename U>
    class Node {
    public:
        U value;
        Node<U>* next;
        Node(const U& value = U(), Node<U>* next = nullptr) : value(value), next(next) {}
    };

    Node<T>* first = nullptr;
    Node<T>* last = nullptr;

public:
    List(int n = 0) {
        for (int i = 0; i < n; ++i) {
            push_back(T());
        }
    }

    ~List() {
        while (first != nullptr) {
            pop_front();
        }
    }

    void push_front(const T& value) {
        first = new Node<T>(value, first);
        if (last == nullptr) {
            last = first;
        }
    }

    void pop_front() {
        if (first == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node<T>* temp = first;
        first = first->next;
        delete temp;

        if (first == nullptr) {
            last = nullptr;
        }
    }

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (last == nullptr) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    void pop_back() {
        if (first == nullptr) {
            throw std::out_of_range("List is empty");
        }
        if (first == last) {
            delete first;
            first = last = nullptr;
            return;
        }

        Node<T>* current = first;
        while (current->next != last) {
            current = current->next;
        }
        delete last;
        last = current;
        last->next = nullptr;
    }

    T& front() {
        if (first == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return first->value;
    }

    const T& front() const {
        if (first == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return first->value;
    }

    T& back() {
        if (last == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return last->value;
    }

    const T& back() const {
        if (last == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return last->value;
    }


    size_t size() const {
        size_t count = 0;
        Node<T>* current = first;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }


    bool empty() const {
        return first == nullptr;
    }



    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        iterator(Node<T>* ptr = nullptr) : m_ptr(ptr) {}

        T& operator*() const { return m_ptr->value; }
        T* operator->() const { return &m_ptr->value; }

        iterator& operator++() { m_ptr = m_ptr->next; return *this; }
        iterator operator++(int) { iterator temp = *this; ++(*this); return temp; }

        bool operator==(const iterator& other) const { return m_ptr == other.m_ptr; }
        bool operator!=(const iterator& other) const { return m_ptr != other.m_ptr; }

    private:
        Node<T>* m_ptr;
        friend class List<T>;
    };


    iterator begin() { return iterator(first); }
    iterator end() { return iterator(nullptr); }



    iterator insert(iterator pos, const T& value) {
        if (pos == end() || first == nullptr) {
            push_back(value);
            return iterator(last);
        }

        if (pos == begin()) {
            push_front(value);
            return begin();
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* prev = first;

        while (prev->next != pos.m_ptr) {
            prev = prev->next;
            if (prev == nullptr || prev->next == nullptr) {
                throw std::runtime_error("Invalid iterator");
            }
        }

        newNode->next = prev->next;
        prev->next = newNode;

        return iterator(newNode);
    }

    iterator erase(iterator pos) {
        if (pos == end() || first == nullptr) {
            throw std::runtime_error("Cannot erase element at end or in empty List");
        }

        if (pos == begin()) {
            pop_front();
            return begin();
        }

        Node<T>* prev = first;
        while (prev->next != pos.m_ptr) {
            prev = prev->next;
            if (!prev || !prev->next) {
                throw std::runtime_error("Invalid iterator");
            }
        }

        Node<T>* temp = prev->next;
        prev->next = temp->next;

        if (temp == last) {
            last = prev;
        }

        delete temp;
        return iterator(prev->next);
    }



    void clear() {
        while (first != nullptr) {
            pop_front();
        }
    }


    void sort() {
        if (!first || !first->next) {
            return;
        }

        bool swapped;
        Node<T>* ptr1;
        Node<T>* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = first;

            while (ptr1->next != lptr) {
                if (ptr1->value > ptr1->next->value) {
                    std::swap(ptr1->value, ptr1->next->value);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }


    void reverse() {
        if (!first || !first->next) {
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* current = first;
        Node<T>* next = nullptr;
        last = first;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        first = prev;
    }


    void print() const {
        Node<T>* current = first;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
