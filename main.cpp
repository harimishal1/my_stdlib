#include <iostream>
#include <cstdio>
#include "my_vector.hpp"
#include "my_shared_pointer.hpp"

struct _book {
    std::pair<int, std::string> book_id_title;
    bool read;
};

void printer(my_vector<my_shared_pointer<_book>>& vectr){
    std::cout<<"Book 1 is: "<<vectr[0]->book_id_title.second<<"\n";
    printf("Stored at: %p \n", vectr[0].get());
}

int main(){
    my_shared_pointer<_book> book(new _book{{1, "Modern Operating Systems"}, false});
    std::cout<<"Shared reference is: "<<book.use_count()<<"\n";
    my_vector<my_shared_pointer<_book>> vectr;
    vectr.push_back(book);
    std::cout<<"Shared reference is: "<<book.use_count()<<"\n";
    printer(vectr);
    my_shared_pointer<_book> book2 = book;
    std::cout<<"Shared reference is: "<<book.use_count()<<"\n";
    book2.reset();
    std::cout<<"Shared reference is: "<<book.use_count()<<"\n";

    return 0 ;
}
