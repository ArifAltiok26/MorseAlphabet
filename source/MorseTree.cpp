#include "MorseTree.h"
#include <exception>
MorseTree::MorseTree() {
	this->root = new Node;
}

MorseTree::~MorseTree(){
	clean(root);
}

void MorseTree::clean(Node* node){
	if(node){
		clean(node->left);
		clean(node->right);
		delete node;
	}
}

void MorseTree::insert(char c, std::string path) {
	Node* temp = root;
	for (size_t i = 0; i < path.length(); i++) {
		if (path[i] == '.') {
			if (!temp->left)
				temp->left = new Node;
			temp = temp->left;
		}
		else if (path[i] == '-') {
			if (!temp->right)
				temp->right = new Node;
			temp = temp->right;
		}
	}
	temp->c = c;
}

std::string MorseTree::encode(Node* node, char c, std::string encoding) const{
	if (node) {
		if (node->c == c)
			return encoding;
		else {
			std::string left = encode(node->left, c, encoding + ".");
			if (left != "")
				return left;
			std::string right = encode(node->right, c, encoding + "-");
			if (right != "")
				return right;
		}
	}
	return "";
}

std::string MorseTree::encode(std::string sentence)const {
	std::string retval;
	for (size_t i = 0; i < sentence.length(); i++) {
		retval += encode(root, std::tolower(sentence[i])) + " ";
	}
	return retval;
}

std::string MorseTree::decode(std::string sentence) const{
	std::string retval;
	Node* temp = root;
	for (size_t i = 0; i < sentence.length(); i++) {
		if (temp == NULL)
			throw std::exception("Invalid character in Morse Alphabet for decoding");
		if (sentence[i] == ' ') {
			retval += temp->c;
			temp = root;
			continue;
		}

		if (sentence[i] == '.')
			temp = temp->left;
		else if (sentence[i] == '-')
			temp = temp->right;
	}
	return retval;
}
