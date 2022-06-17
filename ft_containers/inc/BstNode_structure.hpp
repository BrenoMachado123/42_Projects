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

            BstNode& operator=(const BstNode& other) {
                if (this != &other) {
                    data = other.data;
                    left = other.left;
                    right = other.right;
                    parent = other.parent;
                }
				return *this;
            }

			type data;
			BstNode* left;
			BstNode* right;
			BstNode* parent;
		};
}


#endif