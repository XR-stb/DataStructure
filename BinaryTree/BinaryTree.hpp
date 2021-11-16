#ifndef _BinaryTree__
#define _BinaryTree__

#include <stack> 
#include <string>
#include <iostream>
#include <malloc.h>

template<typename Ty>
struct BinaryTree
{
   Ty value;
   BinaryTree *left, *right;
   static void build(BinaryTree<Ty> *root, const std::string &s);
   static void destroy(BinaryTree<Ty> *root);
   static int height(BinaryTree<Ty> *&root);
   static int nodeCount(BinaryTree<Ty> *&root);
   static int leafCount(BinaryTree<Ty> *&root);
   static void showTree(BinaryTree<Ty> *root);
};

template<typename Ty>
void build(BinaryTree<Ty> *&root, const std::string &s){
    std::stack<BinaryTree<Ty>*> stk;
    BinaryTree<Ty> *p = nullptr;
    root = nullptr;
    p = (BinaryTree<Ty>*)malloc(sizeof(BinaryTree<Ty>));
    int k = 1;

    for(int i = 0; i < s.length(); i++){
        switch (s[i]) {
          case '(': {
            k = 1;
            stk.push(p);
            break;
          }
          case ')': {
            stk.pop();
            break;
          }
          case ',': {
            k = 2;
            break;
          }
          default : {
            p = (BinaryTree<Ty>*)malloc(sizeof(BinaryTree<Ty>));
            p->value = s[i];
            p->left = nullptr; p->right = nullptr;

            if(!root) {
                root = p;
            }else {
                if(k == 1) {
                    if(!stk.empty()) stk.top()->left  = p;
                    else root->left = p;
                }else {
                     if(!stk.empty()) stk.top()->right = p;
                     else root->right = p;
                }
            }
          }
        }
    }
}

template<typename Ty>
void destroy(BinaryTree<Ty> *root){
    if(root != nullptr){
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
    
}

template<typename Ty>
int height(BinaryTree<Ty> *&root){
    if(root == nullptr) return 0;
    int lHeight,rHeight;
    lHeight = height(root->left);
    rHeight = height(root->right);
    if(lHeight > rHeight) return lHeight+1;
    else return rHeight+1;
}

template<typename Ty>
int nodeCount(BinaryTree<Ty> *&root){
    if(root == nullptr) return 0;
    int lcnt = nodeCount(root->left);
    int rcnt = nodeCount(root->right);
    return lcnt + rcnt + 1;
}

template<typename Ty>
int leafCount(BinaryTree<Ty> *&root){
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;//如果是叶子
    int lcnt = leafCount(root->left);
    int rcnt = leafCount(root->right);
    return lcnt + rcnt;
}

template<typename Ty>
void showTree(BinaryTree<Ty> *&root){
    if(root != nullptr){
        std::cout << root->value;
        if(root->left != nullptr || root->right != nullptr){
            std::cout << '(';
                showTree(root->left);
                if(root->right != nullptr){
                    std::cout << ",";
                }
                showTree(root->right);
            std::cout << ")";
        }
    }
    return ;
}

#endif
