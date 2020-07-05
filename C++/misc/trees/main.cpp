#include <iostream>

using namespace std;

struct node {
  int key_value;
  struct node* p_left;
  struct node* p_right;
};

node* newNode(int key) {
  node * p_new_tree = new node;
  p_new_tree->key_value = key;
  p_new_tree->p_left = NULL;
  p_new_tree->p_right = NULL;
  return p_new_tree;
}

node* insert(node *p_tree, int key) {
  if (p_tree == NULL) {
    return newNode(key);
  }
  if (key < p_tree->key_value) {
    p_tree->p_left = insert(p_tree->p_left, key);
  }
  else {
    p_tree->p_right = insert(p_tree->p_right, key);
  }
  return p_tree;
}

// inorder trasversal of the tree
void printTree(struct node* p_tree) {
  if (p_tree == NULL) {
    return;
  }
  printTree(p_tree->p_left);
  cout << p_tree->key_value << " ";
  printTree(p_tree->p_right);
}

void printPostorder(struct node* p_tree) {
  if (p_tree == NULL) {
    return;
  }
  printPostorder(p_tree->p_left);
  printPostorder(p_tree->p_right);
  cout << p_tree->key_value << " ";
}

int size(struct node* p_tree) {
  if (!p_tree) { return 0; }
  return 1 + size(p_tree->p_left) + size(p_tree->p_right);
}

int maxDepth(struct node* p_tree) {
  if (!p_tree) { return 0; }
  int left = maxDepth(p_tree->p_left);
  int right = maxDepth(p_tree->p_right);
  return (left>right) ? left+1 : right+1;
}

int minValue(struct node* p_tree) {
  if (!p_tree) { return 0; }
  if (p_tree->p_left) { return minValue(p_tree->p_left); }
  return p_tree->key_value;
}

void mirror(struct node* p_tree) {
  if (!p_tree) { return; }
  mirror(p_tree->p_left);
  mirror(p_tree->p_right);
  node* tmp = p_tree->p_right;
  p_tree->p_right = p_tree->p_left;
  p_tree->p_left = tmp;
}

node* copy(struct node* p_tree) {
  if (!p_tree) { return 0; }
  node* cp_p_tree = newNode(p_tree->key_value);
  cp_p_tree->p_left = copy(p_tree->p_left);
  cp_p_tree->p_right = copy(p_tree->p_right);
  return cp_p_tree;
}

int sameTree(struct node* a, struct node* b) {
  if(!a) { return 1; }
  if(!b) { return 1; }
  if (a->key_value==b->key_value) {
    int l = sameTree(a->p_left,b->p_left);
    int r = sameTree(a->p_right,b->p_right);
    return (l==1 && r==1) ? 1 : 0;
  }
  else {
    return 0;
  }
}

int main() {
  node* root = NULL;
  cout << "Tree size: " << size(root) << endl;
  root = insert(root,4);
  cout << "Tree size: " << size(root) << endl;
  root = insert(root,2);
  cout << "Tree size: " << size(root) << endl;
  root = insert(root,5);
  cout << "Tree size: " << size(root) << endl;
  root = insert(root,3);
  cout << "Tree size: " << size(root) << endl;
  root = insert(root,1);
  cout << "Tree size: " << size(root) << endl;
  // root = insert(root,-5);
  // cout << "Tree size: " << size(root) << endl;

  cout << "Tree maxDepth: " << maxDepth(root) << endl;
  cout << "Print tree InOrder: ";
  printTree(root);
  cout << endl;
  cout << "Print tree PostOrder: ";
  printPostorder(root);
  cout << endl;
  cout << "Tree size: " << size(root) << endl;
  cout << "Tree minVal: " << minValue(root) << endl;

  node* croot = NULL;
  croot = copy(root);
  cout << "Print tree InOrder: ";
  printTree(croot);
  cout << endl;
  cout << "Print tree PostOrder: ";
  printPostorder(croot);
  cout << endl;

  cout << "sameTree?: " << sameTree(root,croot) << endl;
  mirror(croot);
  cout << "sameTree?: " << sameTree(root,croot) << endl;

  cout << "Print tree InOrder: ";
  printTree(croot);
  cout << endl;
  cout << "Print tree PostOrder: ";
  printPostorder(croot);
  cout << endl;
}
