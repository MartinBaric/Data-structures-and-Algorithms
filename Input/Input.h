#include <list>

#include "../Trees/BinaryTree.h"

template <class T>
list<T> initializeList(string);

template <class T>
Node<T>* initializeTree(list<T>& elementsList);

template <class T>
void initializeArray(list<T>& elementsList, int* elementsArray);