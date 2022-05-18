#include "BTree.h"
#include <iostream>
#include <fstream>
#include <sstream>

template<typename T>
BTree<T> read_file(string file_name);

using namespace std;

int main()
{
  string filename = "";
  cout << "Input filename: ";
	getline(cin, filename);
  cout << endl;
  BTree<int> new_tree = read_file<int>(filename);
	new_tree.inorder(cout);
	new_tree.print_level_by_level(cout);
	cout << "Average Search Time: " << new_tree.get_average_search_time() << endl;
}

template<typename T>
BTree<T> read_file(string file_name)
{
    /*
        open the file and use the input operator (operator>>)
        to construct a new tree
    */
    BTree<T> new_tree;
		string in_path = "data-files/" + file_name;
		ifstream in(in_path);

		if (in.is_open()) {
			while(!in.eof()){
				in >> new_tree;
			}
			in.close();
		} else {
			cout << "cannot open file" << endl;
		}

    return new_tree;
}
