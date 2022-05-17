#ifndef BINARY_SEARCH_TREE_REVITR_HPP
# define BINARY_SEARCH_TREE_REVITR_HPP

#include <iostream>
#include "./binary_search_tree.hpp"
#include "ft_pair.hpp"

// not working
namespace ft {
    template <class Key, class Val>
        class BSTIter_rev {
            public:
                typedef ft::pair<Key, Val>  value_type;
                typedef ft::pair<Key, Val>& reference;
                typedef ft::BstNode<value_type>* pointer;
                typedef typename std::ptrdiff_t difference_type;
                typedef typename std::bidirectional_iterator_tag iterator_category;

                BSTIter_rev() : _bstPtr(pointer()) {}
                BSTIter_rev(pointer ptr) : _bstPtr(ptr) {}
			    BSTIter_rev(const BSTIter_rev& other)
                { *this = other; }

			    BSTIter_rev& operator=(const BSTIter_rev& other) {
				    if (this != &other)
				    	this->_bstPtr = other._bstPtr;
			    	return (*this);
			    }
			    ~BSTIter_rev() {}

                value_type* operator->() const
                { return &_bstPtr->data; }

                value_type& operator*() const
                { return _bstPtr->data; }
                
                bool operator==(const BSTIter_rev& other) {
                    return (_bstPtr == other._bstPtr);
                }

                bool operator!=(const BSTIter_rev& other) {
                    return (!(_bstPtr == other._bstPtr));
                }

                BSTIter_rev operator++() {
                    _bstPtr = _nodePrevItr(_bstPtr);
                    return *this;
                }

                 BSTIter_rev operator--() {
                    _bstPtr = _nodeNextItr(_bstPtr);
                    return *this;
                }

                BSTIter_rev operator--(int) {
                    BSTIter_rev tmp(*this);
                    ++(*this);
                    return tmp;
                }

                BSTIter_rev operator++(int) {
                    BSTIter_rev tmp(*this);
                    --(*this);
                    return tmp;
                }

            private:
                pointer _findMinItr(pointer node) {
                    if (!node or !node->right)
                        return NULL;
					pointer currentNode = node;
					while (currentNode->left->parent != NULL)
						currentNode = currentNode->left;
					return currentNode;
				}

				pointer _findMaxItr(pointer node) {
                    if (!node or !node->right)
                        return NULL;
					pointer currentNode = node;
					while (currentNode->right->parent != NULL)
						currentNode = currentNode->right;
					return currentNode;
				}
                pointer _nodeNextItr(pointer node) {
                    if (node->right and node->right->parent)
                        return _findMinItr(node->right);
                    pointer tmp = node->parent;
                    while (tmp and node == tmp->right) {
                        node = tmp;
                        tmp = tmp->parent;
                    }
                    return tmp;
				}

				pointer _nodePrevItr(pointer node) {
                    if (node->left and node->left->parent)
                        return _findMaxItr(node->left);
                    pointer tmp = node->parent;
                    while (tmp and node == tmp->left) {
                        node = tmp;
                        tmp = tmp->parent;
                    }
                    return tmp;
				}

            public:
                pointer _bstPtr;
        };
}

#endif