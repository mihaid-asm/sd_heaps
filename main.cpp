#include "heapuri.hpp"
#include<fstream>
ifstream fin("heap.in");
int main(){
    Binary B;
    fin>>B;
    B.inserare(0);
    B.inserare(1);
    B.inserare(2);
    B.inserare(3);
    B.inserare(4);
    B.inserare(5);
    B.inserare(6);
    B.stergere_min();
    B.stergere_min();
    B.update(3,7);
    bool v = B.cautare(0,5);
    cout<<B;
    cout<<v;
    fin.close();
    return 0;
}
