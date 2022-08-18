#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include <iostream>
#include "ft_pair.hpp"
#include <stdexcept>
#include <stdlib.h>
#include "BstNode_structure.hpp"

template<class T>
	struct BstNode;

namespace ft {
	template<class T, class Key, class DefaultAlloc = std::allocator<T>, class Compare = std::less<Key>, class BSTNodeType = ft::BstNode<T>, class BSTNodeAlloc = std::allocator< BSTNodeType > >
		class BST {
			typedef T value_type;
			typedef BSTNodeType BSTNode;
			typedef BSTNodeAlloc node_allocator_type;
			typedef DefaultAlloc allocator_type;
			typedef Compare compare_type;
			typedef typename std::size_t size_type;

			public:
				BST() :
				_tree(),
				_size(0), 
				_nodeUnique(false) {}

				BST(const BST& other)
				{*this = other; }

				BST& operator=(const BST& other) {
					if (this != &other) {
						clear();
						BSTNode* tmp = other._tree;
						this->insert(tmp->data);
						tmp = _findMin(other._tree);
						while (tmp != NULL) {
							this->insert(tmp->data);
							tmp = _nodeNext(tmp);
						}
					}
					return *this;
				}

				~BST()
				{ clear(); }

				BSTNode* insert(const value_type& key) {
					_nodeUnique = false;
					_tree = _insertNode(_tree, key);
					return _tree;
				}

				void insert_pos(BSTNode* node, const value_type& key) {
					BSTNode* tmp = _tree;
					if (node)
						_tree = _insertNode(node, key);
					_tree = _searchItem(tmp, tmp->data);
					_size++;
				}

				void inorder()
				{ _inorderNode(_tree); }


				BSTNode* min() const
				{ return _findMin(_tree); }


				BSTNode* max() const
				{ return _findMax(_tree); }

				void deleteNode(const value_type& item) {
					_deleteNode(search(item));
					_size--;
				}

				BSTNode* getEnd() const
				{ return NULL; }

				bool isEmpty() const
				{ return (!_size); }

				BSTNode* next()
				{ return (nodeNext(_searchItem(_tree->data))); }

				BSTNode* prev()
				{ return (nodePrev(_searchItem(_tree->data))); }

				BSTNode* search(const value_type& key) const
				{ return _searchItem(_tree, key); }

				void clear() {
					if (!_size)
						return ;
					_deleteAllNode(_tree);
					_tree = NULL;
				}

				size_type getSize() const
				{ return _size; }

				size_type maxSize() const
				{ return (_allocNode.max_size()); }

				bool isNodeUnique()
				{ return _nodeUnique; }

				void swap(BST& x)
				{
					size_type tmp_size;
					BSTNode* tmp_root;

					tmp_size = _size;
					tmp_root = _tree;

					_tree = x._tree;
					_size = x._size;

					x._tree = tmp_root;
					x._size = tmp_size;
				}

			private:
				BSTNode* createNode(const value_type& key) {
					BSTNode* tmp = _allocNode.allocate(1);
					_alloc.construct(&tmp->data, key);
					tmp->left = NULL;
					tmp->right = NULL;
					tmp->parent = NULL;
					tmp->unique = true;
					_size++;
					return tmp;
				}

				BSTNode* _insertNode(BSTNode* node, const value_type& key) {
					if (node == NULL) {
						return createNode(key);
					}
					BSTNode* current = search(key);
					if (current) {
						_nodeUnique = current->unique;
						return node;
					}
					current = node;
					BSTNode* tmp = NULL;
					while (current) {
						tmp = current;
						if (_comp(current->data.first, key.first))
							current = current->right;
						else
							current = current->left;
					}
					if (!_comp(tmp->data.first, key.first)) {
						tmp->left = createNode(key);
						tmp->left->parent = tmp;
					} else {
						tmp->right = createNode(key);
						tmp->right->parent = tmp;
					}
					return node;
				}

				void	_inorderNode(BSTNode* node) {
					if (node) {
						if (node->left) {
							std::cout << "moving to left" << std::endl;
							_inorderNode(node->left);
						}
						else
							std::cout << "no left node" << std::endl;
						std::cout << "Node: " << node->data.first << "," << node->data.second << " | ";
						if (!node->parent)
							std::cout << "<< Node parentless >>" << std::endl;
						else
							std::cout << "Parent: " << node->parent->data.first << std::endl;
						if (node->right) {
							std::cout << "moving to right" << std::endl;
							_inorderNode(node->right);
						}
						else
							std::cout << "no right node" << std::endl;
					}
				}

				void	_deleteAllNode(BSTNode* node) {
					if (!node)
						return ;
					_deleteAllNode(node->left);
					_deleteAllNode(node->right);
					_deallocNode(node);
					if (_size > 0)
						_size--;
				}

				void _transplant(BSTNode** root, BSTNode* target, BSTNode* branch) {
					if (!target)
						return ;
					else if (!target->parent)
						*root = branch;
					else if (target->parent->left == target)
						target->parent->left = branch;
					else
						target->parent->right = branch;
					if (branch != NULL)
						branch->parent = target->parent;
				}

				BSTNode* _deleteNode(BSTNode* node) {
					if (!node)
						return _tree;
					if (!node->left) {
						_transplant(&_tree, node, node->right);
					}
					else if (!node->right) {
						_transplant(&_tree, node, node->left);
					}
					else {
						BSTNode* nextNode = _nodeNext(node);
						if (node->right != nextNode) {
							_transplant(&_tree, nextNode, nextNode->right);
							nextNode->right = node->right;
							nextNode->right->parent = nextNode;
						}
						_transplant(&_tree, node, nextNode);
        				nextNode->left = node->left;
        				nextNode->left->parent = nextNode;
					}
					_deallocNode(node);
					return _tree;
				}

				BSTNode* _searchItem(BSTNode* node, const value_type& item) const {
					if (!node)
						return NULL;
					BSTNode* tmp = node;
					while (tmp) {
						if (tmp->data.first == item.first)
							return tmp;
						if (_comp(tmp->data.first, item.first))
							tmp = tmp->right;
						else
							tmp = tmp->left;
					}
					return NULL;
				}

				BSTNode* _findMin(BSTNode* node) const {
					if (!node)
						return NULL;
					BSTNode* currentNode = node;
					while (currentNode->left != NULL)
						currentNode = currentNode->left;
					return currentNode;
				}

				BSTNode* _findMax(BSTNode* node) const {
					if (!node)
						return NULL;
					BSTNode* currentNode = node;
					while (currentNode->right != NULL)
						currentNode = currentNode->right;
					return currentNode;
				}

				void	_deallocNode(BSTNode* node) {
					_alloc.destroy(&node->data);
					_allocNode.deallocate(node, 1);
					node = NULL;
				}

				BSTNode* _nodeNext(BSTNode* node) const {
					if (!node)
						return node;
					BSTNode* ptr = node;
                    if (ptr->right and ptr->right->parent)
                        return _findMin(ptr->right);
                    BSTNode* tmp = ptr->parent;
                    while (tmp and ptr == tmp->right) {
                        ptr = tmp;
                        tmp = tmp->parent;
                    }
                    return tmp;
				}

				BSTNode* _nodePrev(BSTNode* node) const {
					if (!node)
						return node;
                    if (node->left and node->left->parent)
                        return _findMax(node->left);
                    BSTNode* tmp = node->parent;
                    while (tmp and node == tmp->left) {
                        node = tmp;
                        tmp = tmp->parent;
                    }
                    return tmp;
				}

				void _abortInvalidPtr() {
					this->~BST();
					std::cerr << "free() : invalid pointer" << std::endl;
					std::abort();
				}

			protected:
				BSTNode* _tree;
				node_allocator_type _allocNode;
				allocator_type _alloc;
				compare_type _comp;
				size_type _size;
				bool _nodeUnique;
		};
		
}

#endif
