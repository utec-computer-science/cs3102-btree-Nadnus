#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Macros.h"
using namespace std;

template <typename T>
class BNode
{
public:
  typedef T value_t;
  typedef vector<value_t> container_t;
  typedef vector<BNode *> pcontainer_t;

  long order;
  long degree;
  container_t data;
  //BNode** children;
  pcontainer_t children;
  size_t current_keys;

  BNode(unsigned int order )
      : order(order)
  {
    //children = new BNode*[B_NODE_ORDER];
    degree = long(std::ceil(float(order / 2)));
    children.resize(order, nullptr);
    data.resize(order, 0);
    current_keys = 0;
  }
  bool isLeaf()
  {
    return (nullptr == children[0]);
  }
  bool isContainerFull()
  {
    return current_keys == order;
  }
  void printNode()
  {
    
    int i;
    for ( i = 0; i < current_keys; i++)
    {
      if (!isLeaf())
      {
        children[i]->printNode();
      }
      cout << " " << data[i];
    }
    cout << endl;
    if (!isLeaf())
    {
      children[i]->printNode();
    }
  }
  void insertToContainer(value_t value)
  {
    cout << "inserting " << value<< "\n";
    int index = current_keys - 1;
    if (isLeaf())
    {
      while (index >= 0 and data[index] > value)
      {
        data[index + 1] = data[index];
        index--;
      }
      data[index + 1] = value;
      current_keys++;
    }
    else
    {
      while (index >= 0 and data[index] > value)
      {
        index--;
      }
      if (children[index + 1]->isContainerFull())
      {
        splitChild(children[index + 1], index + 1);
        if (data[index + 1] < value)
        {
          index++;
        }
      }
      children[index + 1]->insertToContainer(value);
    }
  }

  void splitChild(BNode *child, long index)
  {
    cout<<"Node being split" << endl;

    BNode *overflow = new BNode(order);
    overflow->current_keys = (degree)-1;
    for (int j = 0; j < degree - 1; j++)
    {
      overflow->data[j] = child->data[j + degree];
    }
    if (!child->isLeaf())
    {
      for (int j = 0; j < degree; j++)
      {
        overflow->children[j] = child->children[j + degree];
      }
    }
    child->current_keys = degree - 1;
    for (int j = current_keys; j >= index + 1; j--)
    {
      children[j + 1] = children[j];
    }
    children[index] = child;
    children[index + 1] = overflow;
    for (int j = current_keys - 1; j >= index; j--)
    {
      data[j + 1] = data[j];
    }
    data[index] = child->data[degree - 1];
    current_keys = current_keys + 1;
  }

  ~BNode(void) {}
};

#endif