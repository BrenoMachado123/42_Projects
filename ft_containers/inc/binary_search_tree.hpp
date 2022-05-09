#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

#include <iostream>

//BST getting started slowly
namespace ft {
	template<class T>
		struct BstNode {
			typedef T type;

			BstNode() : 
			_data(type()), _left(NULL), _right(NULL), _parent(NULL) {}

			BstNode(type data) :
			_data(data), _left(NULL), _right(NULL), _parent(NULL) {}

			BstNode(BstNode* left, BstNode* right, BstNode* parent) :
			_data(type()), _left(left), _right(right), _parent(parent) {}

			BstNode(type data, BstNode* left, BstNode* right, BstNode* parent) :
			_data(data), _left(left), _right(right), _parent(parent) {}

			type _data;
			BstNode* _left;
			BstNode* _right;
			BstNode* _parent;
		};

	//DefaultAlloc will the allocation of ft::pair type declared in map.hpp;
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

				BSTNode* createNode(value_type key) {
					BSTNode* tmp = _allocNode.allocate(1);
					tmp->_data = key;
					tmp->_left = NULL;
					tmp->_right = NULL;
					tmp->_parent = NULL;
					_size++;
					return tmp;
				}

				~BST()
				{ _deleteAllNode(_root); }

				void insert(value_type key)
				{ _root = _insertNode(_root, key); }

				void inorder()
				{ _inorderNode(_root); }

				BSTNode* min()
				{ _findMin(_root); }

				BSTNode* max()
				{ _findMax(_root); }


				void deleteNode(value_type item)
				{ _root = _deleteNode(_root, item); }


			private:
				BSTNode* _insertNode(BSTNode* node, value_type key) {
					if (node == NULL)
						return createNode(key);
					if (key < node->_data) {
						BSTNode* lchild = _insertNode(node->_left, key);
						node->_left = lchild;
						lchild->_parent = node;
					} else if (key >= node->_data) {
						BSTNode* rchild = _insertNode(node->_right, key);
						node->_right = rchild;
						rchild->_parent = node;
					}
					return node;
				}

				void	_inorderNode(BSTNode* node) {
					if (node) {
						_inorderNode(node->_left);
						std::cout << "Node: " << node->_data << " | ";
						if (!node->_parent)
							std::cout << "<< Node parentless >>" << std::endl;
						else
							std::cout << "Parent: " << node->_parent->_data << std::endl;
						_inorderNode(node->_right);
					}
				}

				void	_deleteAllNode(BSTNode* node) {
					if (node) {
						if (node->_left)
							_deleteAllNode(node->_left);
						if (node->_right)
							_deleteAllNode(node->_right);
						_deallocNode(node);
						node = NULL;
					}
				}

				BSTNode* _deleteNode(BSTNode* node, value_type item = value_type()) {
					if (node) {
						if (item < node->_data)
						   node->_left = _deleteNode(node->_left, item);
						else if (item > node->_data)
							node->_right = _deleteNode(node->_right, item);
						else {
							if (!node->_left and !node->_right) {
								_deallocNode(node);
								return (NULL);
							}
							else if (!node->_left) {
								BSTNode* tmp = node->_right;
								_deallocNode(node);
								return (tmp);
							}
							else if (!node->_right) {
								BSTNode* tmp = node->_left;
								_deallocNode(node);
								return (tmp);
							}
							BSTNode* minValueNode = _findMin(node->_right);
							node->_data = item = minValueNode->_data;
							node->_right = _deleteNode(node->_right, item);
						}
					}
					return node;
				}

				BSTNode* _getNode(BSTNode*node, value_type item) {
					static BSTNode* saveNode = node;
					if (node) {
						_getNode(node->_left, item);
						std::cout << "-" << node->_data << "-" << std::endl;
						if (node->_data == item)
							saveNode = node;
						_getNode(node->_right, item);
					}
					return (saveNode);
				}

				BSTNode* _findMin(BSTNode* node) {
					BSTNode* currentNode = node;
					while (currentNode->_left != NULL)
						currentNode = currentNode->_left;
					return currentNode;
				}

				BSTNode* _findMax(BSTNode* node) {
					BSTNode* currentNode = node;
					while (currentNode->_right != NULL)
						currentNode = currentNode->_right;
					return currentNode;
				}

				void	_deallocNode(BSTNode* node) {
					_alloc.destroy(&node->_data);
					_allocNode.destroy(node);
					_allocNode.deallocate(node, 1);
				}

			protected:
				BSTNode* _root;
				node_allocator_type _allocNode;
				allocator_type _alloc;
				size_type _size;
		};
}

#endif
