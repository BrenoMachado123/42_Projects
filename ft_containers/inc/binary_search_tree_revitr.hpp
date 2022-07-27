#ifndef BINARY_SEARCH_TREE_REVITR_HPP
# define BINARY_SEARCH_TREE_REVITR_HPP

#include <iostream>
#include "./binary_search_tree.hpp"
#include "ft_pair.hpp"

template<class T>
class BSTIter_const_rev;

namespace ft {
    template <class T>
        class BSTIter_rev {
            public:
                typedef T  value_type;
                typedef T& reference;
                typedef ft::BstNode<value_type>* pointer;
                typedef typename std::ptrdiff_t difference_type;
                typedef typename std::bidirectional_iterator_tag iterator_category;

                BSTIter_rev() : _bstRevPtr(pointer()) {}
                BSTIter_rev(pointer ptr) : _bstRevPtr(ptr) {}
			    BSTIter_rev(const BSTIter_rev& other)
                { *this = other; }

                pointer base() const
                { return _bstRevPtr; }

			    BSTIter_rev& operator=(const BSTIter_rev& other) {
				    if (this != &other)
				    	this->_bstRevPtr = other._bstRevPtr;
			    	return (*this);
			    }
			    ~BSTIter_rev() {}

                value_type* operator->() const
                { return &_bstRevPtr->data; }

                value_type& operator*() const
                { return _bstRevPtr->data; }
                
                bool operator==(const BSTIter_rev& other)
                { return (_bstRevPtr == other._bstRevPtr); }

                bool operator!=(const BSTIter_rev& other)
                { return (!(_bstRevPtr == other._bstRevPtr)); }

                bool operator==(const BSTIter_const_rev<T>& other)
                { return (_bstRevPtr == other._bstRevPtr); }

                bool operator!=(const BSTIter_const_rev<T>& other)
                { return (!(_bstRevPtr == other._bstRevPtr)); }

                BSTIter_rev operator++() {
                    _bstRevPtr = _nodePrevItr(_bstRevPtr);
                    return *this;
                }

                 BSTIter_rev operator--() {
                    _bstRevPtr = _nodeNextItr(_bstRevPtr);
                    return *this;
                }

                BSTIter_rev operator--(int) {
                    BSTIter_rev tmp(*this);
                    operator--();
                    return tmp;
                }

                BSTIter_rev operator++(int) {
                    BSTIter_rev tmp(*this);
                    operator++();
                    return tmp;
                }

            private:
                pointer _findMinItr(pointer node) {
					pointer currentNode = node;
					while (currentNode->left->parent != NULL)
						currentNode = currentNode->left;
					return currentNode;
				}

				pointer _findMaxItr(pointer node) {
					pointer currentNode = node;
					while (currentNode->right != NULL)
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

            private:
                pointer _bstRevPtr;
        };

    template <class T>
        class BSTIter_const_rev {
            public:
                typedef T  value_type;
                typedef T& reference;
                typedef ft::BstNode<value_type>* pointer;
                typedef typename std::ptrdiff_t difference_type;
                typedef typename std::bidirectional_iterator_tag iterator_category;

                BSTIter_const_rev() : _bstRevPtr(pointer()) {}
                BSTIter_const_rev(pointer ptr) : _bstRevPtr(ptr) {}
			    BSTIter_const_rev(const BSTIter_const_rev& other)
                { *this = other; }

                pointer base() const
                { return _bstRevPtr; }

                BSTIter_const_rev(const BSTIter_rev<T>& other)
                {  _bstRevPtr = other.base(); }

			    BSTIter_const_rev& operator=(const BSTIter_const_rev& other) {
				    if (this != &other)
				    	this->_bstRevPtr = other._bstRevPtr;
			    	return (*this);
			    }
			    ~BSTIter_const_rev() {}

                const value_type* operator->() const
                { return &_bstRevPtr->data; }

                const value_type& operator*() const
                { return _bstRevPtr->data; }
                
                bool operator==(const BSTIter_const_rev& other)
                { return (_bstRevPtr == other._bstRevPtr); }

                bool operator!=(const BSTIter_const_rev& other)
                { return (!(_bstRevPtr == other._bstRevPtr)); }

                bool operator==(const BSTIter_rev<T>& other)
                { return (this->base() == other.base()); }

                bool operator!=(const BSTIter_rev<T>& other)
                { return (!(this->base() == other.base())); }

                BSTIter_const_rev operator++() {
                    _bstRevPtr = _nodePrevItr(_bstRevPtr);
                    return *this;
                }

                 BSTIter_const_rev operator--() {
                    _bstRevPtr = _nodeNextItr(_bstRevPtr);
                    return *this;
                }

                BSTIter_const_rev operator--(int) {
                    BSTIter_const_rev tmp(*this);
                    operator--();
                    return tmp;
                }

                BSTIter_const_rev operator++(int) {
                    BSTIter_const_rev tmp(*this);
                    operator++();
                    return tmp;
                }

            private:
                pointer _findMinItr(pointer node) {
					pointer currentNode = node;
					while (currentNode->left->parent != NULL)
						currentNode = currentNode->left;
					return currentNode;
				}

				pointer _findMaxItr(pointer node) {
					pointer currentNode = node;
					while (currentNode->right != NULL)
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

            private:
                pointer _bstRevPtr;
        };
}

#endif