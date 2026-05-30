#include <iostream>
#include <cstdio>
#include "my_vector.hpp"
#include "my_shared_pointer.hpp"

struct _book {
    std::pair<int, std::string> book_id_title;
    bool read;
};

void printer(my_vector<my_shared_pointer<_book>>& vectr){
    std::cout<<vectr[0]->book_id_title.second<<"\n";
    printf("%p \n", vectr[0].get());
}

int main(){
    my_shared_pointer<_book> book(new _book{{1, "Modern Operating Systems"}, false});
    my_vector<my_shared_pointer<_book>> vectr;
    vectr.push_back(book);
    printer(vectr);
    return 0 ;
}
