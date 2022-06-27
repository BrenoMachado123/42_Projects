#ifndef BSTNODE_STRUCTURE_HPP
# define BSTNODE_STRUCTURE_HPP

namespace ft {
	template<class T>
		struct BstNode {
			typedef T type;

			BstNode() : 
			data(type()),left(NULL), right(NULL), parent(NULL) {}

			BstNode(type data) :
			data(data), left(NULL), right(NULL), parent(NULL) {}

			type data;
			BstNode* left;
			BstNode* right;
			BstNode* parent;
		};
}


#endif