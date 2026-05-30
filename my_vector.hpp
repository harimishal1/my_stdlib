#pragma once
#include <memory>
#include <cstddef>

template <typename T>

class my_vector{

private:
    std::unique_ptr<T[]> data;
    std::size_t capacity;
    std::size_t size;

public:
    my_vector(std::size_t initial_capacity = 10)
        :   data(new T[initial_capacity]),
            capacity(initial_capacity),
            size(0) {}

    void add(T element){

        if(size >= capacity){
            resize(capacity * 2);
        }
        data[size++] = element;
    }

    void erase(std::size_t index){
        if(index < 0 || index >= size) return;

        for(int i =  index; i < size; i++){
            data[i] = data[i + 1];
        }
        size--;
    }

    T get(std::size_t index){
        return data[index];
    }

    std::size_t getSize(){
        return size;
    }

    void resize(std::size_t newcapacity){
        std::unique_ptr <T[]> new_data(new T[newcapacity]);
        for(int i = 0; i < size; i++){
            new_data[i] = data[i];
        }

        data = move(new_data);
        capacity = newcapacity;
    }

    T& operator[](std::size_t index){
        return data[index];
    }

    void push_back(const T& element){
        if(size >= capacity){
            resize(capacity * 2);
        }
        data[size] = element;
        size++;
    }

    void pop__back(){
        if(size > 0) size--;
    }

};
