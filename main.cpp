#include <iostream>
#include <cstdio>
#include "my_vector.hpp"
#include "my_shared_pointer.hpp"

using namespace std;


struct _book {
    pair<int, string> book_id_title;
    bool read;
};

void printer(my_vector<my_shared_pointer<_book>>& vectr){
    cout<<vectr[0]->book_id_title.second<<"\n";
    cout<<vectr[0].get();
}

int main(){
    my_shared_pointer<_book> book(new _book{{1, "Modern Operating Systems"}, false});
    my_vector<my_shared_pointer<_book>> vectr;
    //_book newbook = {{1, "Modern Operating Systems"}, false};
    vectr.push_back(book);
    printer(vectr);
    return 0 ;
}
