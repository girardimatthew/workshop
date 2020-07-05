/********************************************************
 * fibonacci.cpp
 *
 *  Created on: 21. nov. 2016
 *      Author: s163144
 *              Girardi Matteo
 ********************************************************/

#include <iostream>

using namespace std;

class fibo {
private:
  struct node {
    int wfibo;
    node * left;
    node * right;
  };

  node * root;
  int size;
  int height;
  int leaves;

  node * tree(int n_node, node * n) {
    ++size;
    if (!n && n_node>=2) {
      node * tmp = new node;
      tmp->left=tmp->right=0;
      tmp->left = tree(n_node-1,tmp->left);
      tmp->right = tree(n_node-2,tmp->right);
      tmp->wfibo = tmp->left->wfibo + tmp->right->wfibo;
      return tmp;
    }
    if (!n && n_node<2) {
      ++leaves;
      node * tmp = new node;
      tmp->wfibo = 1;
      tmp->left=tmp->right=0;
      return tmp;
    }
  };

  void setDepth(int n_node) {
    if (n_node>1) { height = n_node; }
  };

  void deleteR(node * n) {
    if (!n) return;
    deleteR(n->left);
    deleteR(n->right);
    delete n;
  }

  void printInOrder(node * n) {
    if (!n) { return; }
    cout << n->wfibo << " ";
    printInOrder(n->left);
    printInOrder(n->right);
  }

public:
  fibo() {
    root = 0;
    size = 0;
    height = 1;
    leaves = 0;
  }
  ~fibo() { deleteR(root); }

  void insert(int n_node) {
    root = tree(n_node,root);
    setDepth(n_node);
  };

  int getDepth() { return height; }
  int getSize() { return size; }
  int getLeaves() { return leaves; }
  void print() { printInOrder(root); };

};

int main() {
  fibo computeFibo;
  int f = 0;
  cin >> f;
  computeFibo.insert(f);
  cout << "Call tree in pre-order: ";
  computeFibo.print();
  cout << endl;
  cout << "Call tree size: " << computeFibo.getSize() << endl;
  cout << "Call tree depth: " << computeFibo.getDepth() << endl;
  cout << "Call tree leafs: " << computeFibo.getLeaves() << endl;

  return 0;
}
