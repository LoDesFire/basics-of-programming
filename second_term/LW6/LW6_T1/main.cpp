#include <iostream>
#include "MyTree.h"

int main() {
    MyTree myTree;

    myTree.insert({"Shumskiy Daniil Sergeevich", 26});
    myTree.insert({"Azarov Egor Antonovich", 1});
    myTree.insert({"Artish Victoria Olegovna", 2});
    myTree.insert({"Gorgun Alexander Vitalievich", 14});
    myTree.insert({"Schur Marat", 27});
    myTree.insert({"Yackoviec Maxim", 29});

//    myTree.deleteByKey(27);

    myTree.print(Tree<Human>::RIGHT_ORDER, [](Node<Human>*node){
        std::cout << node->data.ID << "\n";
    });

    return 0;
}