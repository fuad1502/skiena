// Singly linked list
// Search: O(n)
// Data: O(1)
// Insert: O(1)
// Delete: O(1)
// Minimum: O(n)
// Maximum: O(n)
// Successor: O(n)
// Predecesor: O(n)
#include <cstdlib>
#include <limits>

template<typename T>
struct Node {
  T data;
  Node *next;
};

template<typename T>
class Dictionary {
private:
  Node<T>* root;
  const T endSentinel = std::numeric_limits<T>::max();
public:
  Dictionary();
  ~Dictionary();
  Node<T>* search(const T& e);
  void insert(const T& e);
  void remove(Node<T> *p);
  Node<T>* minimum();
  Node<T>* maximum();
  Node<T>* successor(Node<T> *p);
  Node<T>* predecessor(Node<T> *p);
};

template<typename T>
Dictionary<T>::Dictionary()
{
  root = new Node<T> {endSentinel, nullptr};
}

template<typename T>
Dictionary<T>::~Dictionary()
{
  Node<T>* node = root;
  while(node != nullptr) {
    Node<T>* tmp = node->next;
    delete node;
    node = tmp;
  }
}

template<typename T>
Node<T>* Dictionary<T>::search(const T& e)
{
  Node<T>* node = root;
  while(node->data != endSentinel) {
    if(node->data == e) {
      return node;
    }
    node = node->next;
  }
  return nullptr;
}

template<typename T>
void Dictionary<T>::insert(const T& e)
{
  root = new Node<T> {e, root};
}

template<typename T>
void Dictionary<T>::remove(Node<T> *p)
{
  if(p == nullptr)
    return;
  Node<T>* nextNode = p->next;
  if(nextNode == nullptr)
    return;
  p->data = nextNode->data;
  p->next = nextNode->next;
  delete nextNode;
}

template<typename T>
Node<T>* Dictionary<T>::successor(Node<T> *p)
{
  if(p == nullptr)
    return nullptr;
  Node<T> *successorNode = nullptr;
  T minDiff = std::numeric_limits<T>::max();
  Node<T> *node = root;
  while(node->data != endSentinel) {
    if(node != p && node->data > p->data && std::abs(node->data - p->data) < minDiff) {
      minDiff = std::abs(node->data - p->data);
      successorNode = node;
    }
    node = node->next;
  }
  return successorNode;
}

template<typename T>
Node<T>* Dictionary<T>::predecessor(Node<T> *p)
{
  if(p == nullptr)
    return nullptr;
  Node<T> *predecessorNode = nullptr;
  T minDiff = std::numeric_limits<T>::max();
  Node<T> *node = root;
  while(node->data != endSentinel) {
    if(node != p && node->data < p->data && std::abs(node->data - p->data) < minDiff) {
      minDiff = std::abs(node->data - p->data);
      predecessorNode = node;
    }
    node = node->next;
  }
  return predecessorNode;
}

template<typename T>
Node<T>* Dictionary<T>::minimum()
{
  Node<T> *minNode = nullptr;
  T min = std::numeric_limits<T>::max();
  Node<T> *node = root;
  while(node->data != endSentinel) {
    if(node->data < min) {
      min = node->data;
      minNode = node;
    }
    node = node->next;
  }
  return minNode;
}

template<typename T>
Node<T>* Dictionary<T>::maximum()
{
  Node<T> *maxNode = nullptr;
  T max = std::numeric_limits<T>::min();
  Node<T> *node = root;
  while(node->data != endSentinel) {
    if(node->data > max) {
      max = node->data;
      maxNode = node;
    }
    node = node->next;
  }
  return maxNode;
}
