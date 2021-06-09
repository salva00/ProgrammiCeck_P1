
#include <iostream>
#include "..\lib\mystl\BinarySearchTree.h"

using namespace mystl;

int main() {
	using bst = BinarySearchTree<int>;
	bst tree;
	// tree.push(1);
	// tree.push(2);
	// tree.push(3);
	// tree.push(5);
	// tree.push(6);
	// tree.push(8);
	// tree.push(7);
	// tree.push(9);
	// tree.print();
	/*
        5
    2       9
  1   3   7
	 		  6   8
	*/
	// std::cout << "max is " << tree.getMax() << " ~ min is " << tree.getMin() << " ~ leaves is " << tree.getHeight() << '\n';
	// for(auto i = tree.begin(); i != tree.end(); ++i) {
	// 	std::cout << *i << ' ';
	// } std::cout << '\n';

	int input{0};
	while(input != -1) {
		std::cout << "insert > ";
		std::cin >> input;
		try {
			tree.push(input);
			std::cout << "min: " << tree.getMin() << " ~ max: " << tree.getMax() << '\n';
			tree.print();
			// for(auto i : tree) std::cout << i << ' ';
			// std::cout << '\n';
			// std::cout << "leaves/elements : " << tree.getLeaves() << '/' << tree.size() << '\n';
			// if(tree.getLeaves()*4 < tree.size()) {
			// 	std::cout << "Rebalancing tree ...\n";
			// 	tree.balance();
			// 	tree.print();
			// }
		} catch(std::exception& e) {
			std::cerr << e.what() << '\n';
			continue;
		}
		std::cout << "----------------\n";
	}

	tree.print();
	// for(int i = 0; i < 256; ++i) std::cout << i << (char) i << '\n';
	system("pause");
	return 0;
}







//
