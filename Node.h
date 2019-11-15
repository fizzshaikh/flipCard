// Fizzah Shaikh and Justin Chen
// Project 2b
// Header for Node class
// Provided by Professor Mi on Blackboard

#ifndef NODE_CLASS
#define NODE_CLASS
#ifndef NULL
#include <cstddef>
#endif  // NULL

// linked list node
template <typename T>
class Node
{
public:
	T nodeValue;      // data held by the node
	Node<T>* next;    // next node in the list

	// default constructor with no initial value
	Node() : next(NULL)
	{}

	// constructor. initialize nodeValue and next
	Node(const T& item, Node<T>* nextNode = NULL) :
		nodeValue(item), next(nextNode)
	{}
};

#endif   // NODE_CLASS