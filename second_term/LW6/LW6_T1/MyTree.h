//
// Created by Даниил Шумский on 9.05.23.
//

#ifndef LW6_T1_MYTREE_H
#define LW6_T1_MYTREE_H

#include "AvlTree.h"

struct Human
{
    std::string FIO;
    int ID{};

    bool operator<(const Human& b) const{
        return ID < b.ID;
    }
    bool operator>(const Human& b) const{
        return ID > b.ID;
    }
    bool operator==(const Human& b) const{
        return ID == b.ID;
    }
    bool operator!=(const Human& b) const{
        return ID != b.ID;
    }
    operator int() const{
        return ID;
    }
};

class MyTree : public Tree<Human> {
public:
    MyTree() :
            Tree<Human>() {}
    size_t amountOfFIOs(Node<Human> *node, char c) {
        if (!node)
            return 0;

        auto ans = amountOfFIOs(node->left, c) + amountOfFIOs(node->right, c);

        if (node->data.FIO[0] == c)
            return ans + 1;
        return ans;
    }

    size_t makeTask(char c) {
        if (!root)
            return 0;
        return amountOfFIOs(root, c);
    }
};

#endif //LW6_T1_MYTREE_H
