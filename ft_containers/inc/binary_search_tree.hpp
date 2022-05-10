#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

#include <iostream>

//BST getting started slowly
namespace ft {
	template<class T>
		struct BstNode {
			typedef T type;

			BstNode() : 
			_data(type()), left(NULL), right(NULL), parent(NULL) {}

			BstNode(type data) :
			_data(data), left(NULL), right(NULL), parent(NULL) {}

			BstNode(BstNode* left, BstNode* right, BstNode* parent) :
			_data(type()), left(left), right(right), parent(parent) {}

			BstNode(type data, BstNode* left, BstNode* right, BstNode* parent) :
			_data(data), left(left), right(right), parent(parent) {}

			type _data;
			BstNode* left;
			BstNode* right;
			BstNode* parent;
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
					tmp->left = NULL;
					tmp->right = NULL;
					tmp->parent = NULL;
					_size++;
					return tmp;
				}

				~BST()
				{ _deleteAllNode(_root); }

				//std::map don't insert equal key values, so I'm not supposed to insert them too.  
				void insert(value_type key) {
					if (!_searchItem(_root, key))
						_root = _insertNode(_root, key);	
				}

				void inorder()
				{ _inorderNode(_root); }

				BSTNode* min()
				{ _findMin(_root); }

				BSTNode* max()
				{ _findMax(_root); }

				void deleteNode(value_type item)
				{ _root = _deleteNode(_root, item); }

				bool isEmpty() 
				{ return _root == NULL; }


			private:
				BSTNode* _insertNode(BSTNode* node, value_type key) {
					if (node == NULL)
						return createNode(key);
					if (key < node->_data) {
						BSTNode* lchild = _insertNode(node->left, key);
						node->left = lchild;
						lchild->parent = node;
					} else if (key >=node->_data) {
						BSTNode* rchild = _insertNode(node->right, key);
						node->right = rchild;
						rchild->parent = node;
					}
					return node;
				}

				void	_inorderNode(BSTNode* node) {
					if (node) {
						_inorderNode(node->left);
						std::cout << "Node: " << node->_data << " | ";
						if (!node->parent)
							std::cout << "<< Node parentless >>" << std::endl;
						else
							std::cout << "Parent: " << node->parent->_data << std::endl;
						_inorderNode(node->right);
					}
				}

				void	_deleteAllNode(BSTNode* node) {
					if (node) {
						if (node->left)
							_deleteAllNode(node->left);
						if (node->right)
							_deleteAllNode(node->right);
						_deallocNode(node);
					}
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
						if (item < node->_data)
						   node->left = _deleteNode(node->left, item);
						else if (item > node->_data)
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
							node->_data = item = minValueNode->_data;
							node->right = _deleteNode(node->right, item);
						}
					}
					return node;
				}

				BSTNode* _searchItem(BSTNode* node, value_type item) {
					if (!node)
						return NULL;
					else if (node->_data == item)
						return node;
					else if (node->_data < item)
						_searchItem(node->right, item);
					else
						_searchItem(node->left, item);
					return (NULL);
				}

				BSTNode* _findMin(BSTNode* node) {
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

				void	_deallocNode(BSTNode* node) {
					_alloc.destroy(&node->_data);
					_allocNode.deallocate(node, 1);
					node = NULL;
					_size--;
				}

			protected:
				BSTNode* _root;
				node_allocator_type _allocNode;
				allocator_type _alloc;
				size_type _size;
		};
}

#endif
