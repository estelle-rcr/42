#ifndef RBTREE_NODE_HPP
# define RBTREE_NODE_HPP

namespace ft {
	enum _Rb_tree_color { RED = false, BLACK = true };

	template <typename T>
		class node {

			public:
				typedef node* 		basePtr;
				typedef const node* constBasePtr;
				typedef node<T>* 	linkType;
				basePtr				left;
				basePtr				right;
				basePtr				parent;
				basePtr				nil;
				int					color;
				T					value;

				// Constructor
				node()	: value(T()){
					color = RED;
				}

				node(const T &val)	: value(val) {
					left = right = parent = nil = 0;
					color = RED;
				}

				node(basePtr x) : value(x->value) {
					color = x->color;
					left = x->left;
					right = x->right;
					parent = x->parent;
					nil = 0;
				}

				static basePtr minimum(basePtr x)	{
					while (x->left != x->nil) x = x->left;
					return x;
				}

				static constBasePtr minimum(constBasePtr x)	{
					while (x->left != x->nil) x = x->left;
					return x;
				}

				static basePtr maximum(basePtr x)	{
					while (x->right != x->nil) x = x->right;
					return x;
				}

				static constBasePtr maximum(constBasePtr x)	{
					while (x->right != x->nil) x = x->right;
					return x;
				}

				void flipColor(void)
				{
					color == RED ? color = BLACK : color = RED;
				}

				bool isLeftChild(void) {
					if (this == nil) {
						if (parent->right != nil)
							return true;
						return false;
					}
					if (parent == nil)
						return false;
					if (parent->left == nil)
						return false;
					if (this == parent->left)
						return true;
					return false;
				}

				bool isRightChild(void) {
					if (this == nil) {
						if (parent->left != nil)
							return true;
						return false;
					}
					if (parent == nil)
						return false;
					if (parent->right == nil)
						return false;
					if (this == parent->right)
						return true;
					return false;
				}

				void	setParent(basePtr node) {
					parent = node;
				}

				void	setRight(basePtr node) {
					right = node;
				}

				void	setLeft(basePtr node) {
					left = node;
				}

				void	setPointers(basePtr Tnil) {
					left = right = parent = nil = Tnil;
				}

	};

	// *** INCREMENT FUNCTIONS ***

	template<typename T>
		node<T>* 	local_RBT_increment(node<T>* x) throw () {
			if (x->right != x->nil) {
				x = x->right;
				while (x->left != x->nil)
					x = x->left;
			}
			else {
				node<T>* y = x->parent;
				if (y == x->nil)
					return y->nil;
				while (x == y->right) {
					x = y;
					y = y->parent;
				}
				if (x->right != y)
					x = y;
			}
			return x;
		}


	template<typename T>
		node<T>*	_Rb_tree_increment(node<T>*	x) throw ()
		{ return local_RBT_increment(x); }

	template<typename T>
		const node<T>* _Rb_tree_increment(const node<T>* x) throw ()
		{ return local_RBT_increment(const_cast<node<T>*>(x)); }


	// *** DECREMENT FUNCTIONS ***

	template<typename T>
		node<T>* 	local_RBT_decrement(node<T>* x) throw () {
			node<T>* y;
			if (x->left != x->nil) {
				y = x->left;
				while (y->right != x->nil)
					y = y->right;
				x = y;
			}
			else {
				y = x->parent;
				while (x == y->left && y->left != x->nil) {
					x = y;
					y = y->parent;
				}
				if (x->left != y)
					x = y;
			}
			return x;
		}

	template<typename T>
		node<T>* _Rb_tree_decrement(node<T>* x) throw ()
			{ return local_RBT_decrement(x); };

	template<typename T>
		const node<T>* _Rb_tree_decrement(const node<T>* x) throw ()
			{ return local_RBT_decrement(const_cast<node<T>*>(x)); }

};


#endif
