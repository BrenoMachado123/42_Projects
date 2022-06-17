#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include <iostream>
#include "ft_pair.hpp"
#include <stdexcept>
#include <stdlib.h>
#include "BstNode_structure.hpp"

namespace ft {
	template<class T, class DefaultAlloc = std::allocator<T>, class BSTNodeType = BstNode<T>, class BSTNodeAlloc = std::allocator< BstNode<T> > >
		class BST {
			typedef T value_type;
			typedef BSTNodeType BSTNode;
			typedef BSTNodeAlloc node_allocator_type;
			typedef DefaultAlloc allocator_type;
			typedef typename std::size_t size_type;

			public:
				BST() :
				_tree(),
				_root(nihil_ptr()),
				_allocNode(node_allocator_type()), 
				_alloc(allocator_type()), 
				_size(0), 
				_treeNode(true),
				nodeRepeated(false) {}

				BST(const BST& other)
				{*this = other; }

				BST& operator=(const BST& other) {
					if (this != &other) {
						clear();
						BSTNode* tmp = other._tree;
						this->insert(tmp->data);
						tmp = _findMin(other._tree);
						while (tmp != NULL) {
							if (tmp != other._root)
								this->insert(tmp->data);
							tmp = _nodeNext(tmp);
						}
					}
					return *this;
				}

				~BST() { 
					clear();
					_deallocNode(_root);
				}

				BSTNode* insert(const value_type& key)
				{
					nodeRepeated = false;
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
					_tree = _deleteNode(_tree, item);
					_size--;
				}

				BSTNode* getEnd() const { 
					if (isEmpty())
						return NULL;
					return _root;
				}

				bool isEmpty() const
				{ return (_tree == NULL); }

				BSTNode* next()
				{ return (nodeNext(_searchItem(_tree->data))); }

				BSTNode* prev()
				{ return (nodePrev(_searchItem(_tree->data))); }

				BSTNode* search(const value_type& key) const
				{ return _searchItem(_tree, key); }

				void clear() {
					_deleteAllNode(_tree);
					_tree = NULL;
				}

				size_type getSize() const
				{ return _size; }

				size_type maxSize() const
				{ return (_allocNode.max_size()); }

				bool isNodeRepeated() {
					return nodeRepeated;
				}

			private:
				BSTNode* nihil_ptr() {
					value_type emptyData;
					BSTNode* node = _allocNode.allocate(1);
					_alloc.construct(&node->data, emptyData);
					node->left = NULL;
					node->right = NULL;
					node->parent = NULL;
					return node;
				}

				BSTNode* createNode(const value_type& key) {
					BSTNode* tmp = _allocNode.allocate(1);
					_alloc.construct(&tmp->data, key);
					tmp->left = NULL;
					tmp->right = NULL;
					if (_treeNode) {
						tmp->parent = _root;
						_treeNode = false;
					}
					else
						tmp->parent = NULL;
					_size++;
					return tmp;
				}

				BSTNode* _insertNode(BSTNode* node, const value_type& key) {
					if (node == NULL)
						return createNode(key);
					/*if (key.first < node->data.first) {
						BSTNode* lchild = _insertNode(node->left, key);
						node->left = lchild;
						lchild->parent = node;
					} else if (key.first > node->data.first) {
						BSTNode* rchild = _insertNode(node->right, key);
						node->right = rchild;
						rchild->parent = node;
					}*/

					BSTNode* current = node;
					BSTNode* tmp = NULL;
					while (current) {
						tmp = current;
						if (current->data.first < key.first)
							current = current->right;
						else if ( current->data.first > key.first )
							current = current->left;
						else {
							nodeRepeated = true;
							return current;
						}
					}

					if (tmp->data.first > key.first) {
						tmp->left = createNode(key);
						tmp->left->parent = tmp;
					} else if (tmp->data.first < key.first) {
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
					std::cout << "BST {end}" << std::endl;
				}

				void	_deleteAllNode(BSTNode* node) {
					if (!node)
						return ;
					_deleteAllNode(node->left);
					_deleteAllNode(node->right);
					_deallocNode(node);
					if (_size > 0)
						_size--;
					_treeNode = true;
				}

				BSTNode* _getFilledBranch(BSTNode* node) {
					if (!node->left and node->right)
						return node->right;
					else if (node->left and !node->right)
						return node->left;
					return NULL;
				}

				BSTNode* _deleteNode(BSTNode* node, value_type item) {
					if (node) {
						if (item.first < node->data.first)
						   node->left = _deleteNode(node->left, item);
						else if (item.first > node->data.first)
							node->right = _deleteNode(node->right, item);
						else {
							if (!node->left and !node->right) {
								_deallocNode(node);
								return (NULL);
							}
							else if (!node->left or !node->right) {
								BSTNode* tmp = _getFilledBranch(node);
								tmp->parent = node->parent;
								if (node->parent == _tree->parent)
									_deallocNode(node->parent);
								_deallocNode(node);
								return (tmp);
							}
							BSTNode* minValueNode = _findMin(node->right);
							node->data = item = minValueNode->data;
							node->right = _deleteNode(node->right, item);
						}
					}
					return node;
				}

				BSTNode* _searchItem(BSTNode* node, const value_type& item) const {
					if (!node)
						return NULL;
					BSTNode* tmp = _findMin(node);
					while (tmp) {
						if (tmp->data.first == item.first) {
							return tmp;
						}
						tmp = _nodeNext(tmp);
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
				BSTNode* _root;
				node_allocator_type _allocNode;
				allocator_type _alloc;
				size_type _size;
				bool _treeNode;
				bool nodeRepeated;
		};
		
}

#endif
