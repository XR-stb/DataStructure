#include "BinaryTree.hpp"
#include <string>
#include <iostream>

int main(){
    std::string s = "A(B(D,E(G,H)),C(,F(I)))";
    BinaryTree<char> *root;
    root = (BinaryTree<char>*)malloc(sizeof(BinaryTree<char>));
    build(root, s);
    showTree(root); std::cout << '\n';
    std::cout << "Tree height is : " << height(root) << '\n';
    std::cout << "Tree nodeCount is : " << nodeCount(root) << '\n';
    std::cout << "Tree leafCount is : " << leafCount(root) << '\n';
    destroy(root);

    
    system("pause");
    return 0;
}
