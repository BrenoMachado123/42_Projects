#ifndef BSTNODE_STRUCTURE_HPP
# define BSTNODE_STRUCTURE_HPP

namespace ft {
	template<class T>
		struct BstNode {
			typedef T type;
			typedef BstNode* pointer;

			BstNode() : 
			data(type()),left(pointer()), right(pointer()), parent(pointer()), unique(false) {}

			BstNode(type data) :
			data(data), left(pointer()), right(pointer()), parent(pointer()), unique(false) {}

			type data;
			pointer left;
			pointer right;
			pointer parent;
			bool unique;
		};
}


#endif