#ifndef BSTNODE_STRUCTURE_HPP
# define BSTNODE_STRUCTURE_HPP

namespace ft {
	template<class T>
		struct BstNode {
			typedef T type;

			BstNode() : 
			data(type()),left(NULL), right(NULL), parent(NULL), empty(true) {}

			BstNode(type data) :
			data(data), left(NULL), right(NULL), parent(NULL), empty(true) {}

            BstNode& operator=(const BstNode& other) {
                if (this != &other) {
                    data = other.data;
                    left = other.left;
                    right = other.right;
                    parent = other.parent;
                    empty = other.empty;
                }
				return *this;
            }

			type data;
			BstNode* left;
			BstNode* right;
			BstNode* parent;
			bool empty;
		};
}


#endif