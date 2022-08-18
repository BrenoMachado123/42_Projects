#ifndef BSTNODE_STRUCTURE_HPP
#define BSTNODE_STRUCTURE_HPP

namespace ft
{
	template <class T>
	struct BstNode
	{
		typedef T type;
		typedef BstNode *pointer;

		BstNode() : data(type()), left(pointer()), right(pointer()), parent(pointer()), unique(false) {}

		BstNode(type data) : data(data), left(pointer()), right(pointer()), parent(pointer()), unique(false) {}

		BstNode &operator=(const BstNode &other)
		{
			if (this != &other)
			{
				data = other.data;
				left = other.left;
				right = other.right;
				parent = other.parent;
				unique = other.unique;
			}
			return *this;
		}

		type data;
		pointer left;
		pointer right;
		pointer parent;
		bool unique;
	};
}

#endif