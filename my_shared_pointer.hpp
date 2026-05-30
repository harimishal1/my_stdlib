#pragma once
#include <cstddef>

template <typename T>

class my_shared_pointer{

    struct ControlBlock {
        size_t shared_count;
    };

private:
    T* ptr = nullptr;
    ControlBlock* control_block = nullptr;

    void release(){
        if(control_block){
            control_block->shared_count--;
            if(control_block->shared_count == 0){
                delete ptr;
                delete control_block;
            }
        }
        ptr = nullptr;
        control_block = nullptr;
    }

public:
    my_shared_pointer()
        : ptr(nullptr),
          control_block(nullptr)
    {
    }

    my_shared_pointer(T* raw_ptr)
        :   ptr(raw_ptr),
            control_block(raw_ptr ? new ControlBlock{1} : nullptr)
    {
    }

    my_shared_pointer(const my_shared_pointer& other)
        :   ptr(other.ptr),
            control_block(other.control_block)
        {
            if(control_block) control_block->shared_count++;
        }

    size_t use_count() const {
        if(control_block){
            return control_block->shared_count;
        }
        return 0;
    }

    T* operator->() const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    T& operator*() const {
        // this allows: (*book).read
        return *ptr;
    }

    explicit operator bool() const {
        return ptr != nullptr;
    }

    my_shared_pointer& operator=(const my_shared_pointer& other) {
        if (this == &other) {
            return *this;
        }

        release();
        ptr = other.ptr;
        control_block = other.control_block;

        if (control_block) {
            control_block->shared_count++;
        }

        return *this;
    }

    my_shared_pointer& operator=(my_shared_pointer&& other) {
        if (this == &other) {
            return *this;
        }

        release();

        ptr = other.ptr;
        control_block = other.control_block;

        other.ptr = nullptr;
        other.control_block = nullptr;

        return *this;
    }

    void reset() {
        release();
    }

    ~my_shared_pointer(){
        release();
    }
};
