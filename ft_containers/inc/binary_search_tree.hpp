#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include <iostream>
#include "ft_pair.hpp"

namespace ft {
	template<class T>
		struct BstNode {
			typedef T type;

			BstNode() : 
			data(type()), left(NULL), right(NULL), parent(NULL) {}

			BstNode(type data) :
			data(data), left(NULL), right(NULL), parent(NULL) {}

			type data;
			BstNode* left;
			BstNode* right;
			BstNode* parent;
		};
};

namespace ft {
	template<class T, class BSTNodeType = BstNode<T>, class BSTNodeAlloc = std::allocator<BstNode<T> >, class DefaultAlloc = std::allocator<T> >
		class BST {
			typedef T value_type;
			typedef BSTNodeType BSTNode;
			typedef BSTNodeAlloc node_allocator_type;
			typedef DefaultAlloc allocator_type;
			typedef typename std::size_t size_type;

			public:
				BST() :
				_root(NULL), _allocNode(node_allocator_type()), _alloc(allocator_type()), _size(0) {}

				BST(const BST& other)
				{*this = other; }

				BST& operator=(const BST& other) {
					if (this != &other) {
						deleteAllNode(_root);
						BSTNode* tmp = other._root;
						this->insert(tmp->data);
						tmp = other.min();
						while (tmp != other.max()) {
							this->insert(tmp->data);
							tmp++;
						}
					}
				}

				~BST()
				{ _deleteAllNode(_root); }

				void insert(value_type key)
				{ _root = _insertNode(_root, key); }

				void insert_pos(BSTNode* node, value_type key) {
					BSTNode* tmp = _root;
					if (node)
						_root = _insertNode(node, key);
					_root = _searchItem(tmp, tmp->data);
					_size++;
				}

				void inorder()
				{ _inorderNode(_root); }

				BSTNode* min()
				{ return _findMin(_root); }

				BSTNode* max()
				{ return _findMax(_root); }

				void deleteNode(value_type item)
				{ _root = _deleteNode(_root, item); }

				bool isEmpty() 
				{ return (_root == NULL); }

				BSTNode* next()
				{ return (nodeNext(_searchItem(_root->data))); }

				BSTNode* prev()
				{ return (nodePrev(_searchItem(_root->data))); }

				BSTNode* search(const value_type& key)
				{ return _searchItem(_root, key); }

				BSTNode* search(const value_type& key) const
				{ return _searchItem(_root, key); }

				void clear() {
					_deleteAllNode(_root);
					_root = NULL;
				}

				size_type getSize()
				{ return _size; } 

			private:
				BSTNode* createNode(value_type key) {
					BSTNode* tmp = _allocNode.allocate(1);
					tmp->data = key;
					_alloc.construct(&tmp->data, key);
					tmp->left = NULL;
					tmp->right = NULL;
					tmp->parent = NULL;
					_size++;
					return tmp;
				}

				BSTNode* _insertNode(BSTNode* node, value_type key) {
					if (node == NULL)
						return createNode(key);
					if (key.first < node->data.first) {
						BSTNode* lchild = _insertNode(node->left, key);
						node->left = lchild;
						lchild->parent = node;
					} else if (key.first > node->data.first) {
						BSTNode* rchild = _insertNode(node->right, key);
						node->right = rchild;
						rchild->parent = node;
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
					_size--;
				}

				BSTNode* _getFilledBranch(BSTNode* node) {
					if (!node->left and node->right)
						return node->right;
					else if (node->left and !node->right)
						return node->left;
					return NULL;
				}

				BSTNode* _deleteNode(BSTNode* node, value_type item = value_type()) {
					if (node) {
						if (item < node->data)
						   node->left = _deleteNode(node->left, item);
						else if (item > node->data)
							node->right = _deleteNode(node->right, item);
						else {
							if (!node->left and !node->right) {
								_deallocNode(node);
								return (NULL);
							}
							else if (!node->left or !node->right) {
								BSTNode* tmp = _getFilledBranch(node);
								_deallocNode(node);
								return (tmp);
							}
							BSTNode* minValueNode = _findMin(node->right);
							node->data = item = minValueNode->data;
							node->right = _deleteNode(node->right, item);
						}
					}
					_size--;
					return node;
				}

				BSTNode* _searchItem(BSTNode* node, const value_type& item) {
					if (!node)
						return(NULL);
					BSTNode* tmp = _findMin(node);
					while (tmp) {
						if (tmp->data.first == item.first) {
							return tmp;
						}
						tmp = _nodeNext(tmp);
					}
					return NULL;
				}

				BSTNode* _searchItem(BSTNode* node, const value_type& item) const {
					if (!node)
						return(NULL);
					BSTNode* tmp = _findMin(node);
					while (tmp) {
						if (tmp->data.first == item.first) {
							return tmp;
						}
						tmp = _nodeNext(tmp);
					}
					return NULL;
				}

				BSTNode* _findMin(BSTNode* node) {
					BSTNode* currentNode = node;
					while (currentNode->left != NULL)
						currentNode = currentNode->left;
					return currentNode;
				}

				BSTNode* _findMin(BSTNode* node) const {
					BSTNode* currentNode = node;
					while (currentNode->left != NULL)
						currentNode = currentNode->left;
					return currentNode;
				}

				BSTNode* _findMax(BSTNode* node) {
					BSTNode* currentNode = node;
					while (currentNode->right != NULL)
						currentNode = currentNode->right;
					return currentNode;
				}

				BSTNode* _findMax(BSTNode* node) const {
					BSTNode* currentNode = node;
					while (currentNode->right != NULL)
						currentNode = currentNode->right;
					return currentNode;
				}

				void	_deallocNode(BSTNode* node) {
					_alloc.destroy(&node->data);
					_allocNode.destroy(node);
					_allocNode.deallocate(node, 1);
					node = NULL;
				}

				BSTNode* _nodeNext(BSTNode* node) {
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

				BSTNode* _nodePrev(BSTNode* node) {
                    if (node->left and node->left->parent)
                        return _findMax(node->left);
                    BSTNode* tmp = node->parent;
                    while (tmp and node == tmp->left) {
                        node = tmp;
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

			protected:
				BSTNode* _root;
				node_allocator_type _allocNode;
				allocator_type _alloc;
				size_type _size;
		};
		
}

#endif
