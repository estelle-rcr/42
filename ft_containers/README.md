# Ft_containers

### The project
This project aims at rebuilding 3 containers from the STD library in CPP: vectors, stack and map. The project is about learning on iterators, sequence & associative containers, adapters, data structures and algorithms (implementation of a balanced tree - AVL or red/black tree - for map), and generic programming (templates).

### Containers and functions rewritten as ft namespace:
- Containers :
  - Vector
  - Stack
  - Map
  - Set
- iterator_traits
- reverse_iterator
- enable_if
- is_integral
- equal
- lexicographical_compare
- pair

### How to use it
The project runs only on a Linux distribution.
  Compile the project using Makefile:
  `make`

  Start the program:
  `./ft_containers`

  To compare the two generated programs (the second program uses STL containers & functions):
  `./ft_containers > ft_tests && ./std_containers > std_tests && diff ft_tests std_tests`

### Resources:
#### VECTOR:
https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01069_source.html#l00217
https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/
https://www.journaldev.com/56360/vector-class-in-cpp
https://www.cs.odu.edu/~zeil/cs361/sum18/Public/vectorImpl/index.html
https://medium.com/@vgasparyan1995/how-to-write-an-stl-compatible-container-fc5b994462c6
https://medium.com/@vgasparyan1995/what-is-an-allocator-c8df15a93ed
https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
http://cs.brown.edu/people/jwicks/libstdc++/html_user/stl__iterator_8h-source.html
https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html
https://medium.com/@vgasparyan1995/interpolation-search-a-generic-implementation-in-c-part-2-164d2c9f55fa
https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
https://code.woboq.org/appleseed/include/boost/type_traits/is_integral.hpp.html
https://riptutorial.com/cplusplus/example/3777/enable-if#:~:text=std%3A%3Aenable_if%20is%20a,boolean%20conditions%20to%20trigger%20SFINAE.
https://stackoverflow.com/questions/15598939/how-do-i-use-stdis-integral-to-select-an-implementation



#### MAP:
https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
https://www.programiz.com/dsa/red-black-tree
https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
https://stackoverflow.com/questions/67460546/what-does-it-mean-for-a-red-black-tree-to-have-same-number-of-black-nodes-on-all
https://stackoverflow.com/questions/65262899/what-is-the-purpose-of-pointer-rebind
https://www.dre.vanderbilt.edu/Doxygen/5.6/html/ace/classACE__Map__Impl.html
http://gauss.ececs.uc.edu/RedBlack/redblack.html#:~:text=The%20predecessor%20of%20a%20node,in%20the%20case%20of%20predecessor



#### Code source:
https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a01067_source.html
https://stackoverflow.com/questions/17150544/what-is-the-definition-of-rb-tree-increment-in-bits-stl-tree-h
https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/src/c%2B%2B98/tree.cc

