#pragma once
#include <string>
class Node {
public:
	char c;
	Node* left;
	Node* right;
	Node(char c = '\0', Node* left = NULL, Node* right = NULL) {
		this->c = c;
		this->left = left;
		this->right = right;
	}
};

class MorseTree {
	Node* root;

	void clean(Node* node);
public:
	MorseTree();

	~MorseTree();

	void insert(char c, std::string path);

	std::string encode(Node* node, char c, std::string encoding = "")const;

	std::string encode(std::string sentence)const;

	std::string decode(std::string sentence)const;
};
