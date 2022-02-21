#include <iostream>
#include <string>
#include <conio.h>
#include "MorseTree.h"

void help();
const MorseTree init_morse_alphabet();
void testing(const MorseTree& m_tree);
void mainloop(const MorseTree& m_tree);

int main(int argc, char** argv)
{
	const MorseTree m_tree = init_morse_alphabet();
	if(argc==1)
		help();
	else if (argc == 2) {
		if (strcmp("--help", argv[1]) == 0)
			help();
		else if (strcmp("--demo", argv[1]) == 0)
			testing(m_tree);
		else if (strcmp("--loop", argv[1]) == 0)
			mainloop(m_tree);
		else if (strcmp("--encoding", argv[1]) == 0) {
			std::string input;
			std::getline(std::cin, input);
			std::cout << m_tree.encode(input) << std::endl;
		}
		else if (strcmp("--decoding", argv[1]) == 0) {
			std::string input;
			std::getline(std::cin, input);
			std::cout << m_tree.decode(input) << std::endl;
		}
	}
	else if (argc == 3) {
		if (strcmp("--encoding", argv[1]) == 0) {
			std::cout << m_tree.encode(std::string(argv[2])) << std::endl;
		}
		else if (strcmp("--decoding", argv[1]) == 0) {
			std::cout << m_tree.decode(std::string(argv[2])) << std::endl;
		}
	}

	return 0;
}

void help() {
	std::cout	<< "Welcome to the Morse Code App. Here is the app's help menu." << std::endl << std::endl;
	std::cout << "First of all, the purpose of this application is to encode and decode any text with morse code rules."
		<< " If you want to learn more about Morse code, please visit https ://en.wikipedia.org/wiki/Morse_code." << std::endl << std::endl;
	

	std::cout	<< "There are some commands. There are --demo, --loop, --encoding, --decoding." << std::endl << std::endl;
	
	std::cout	<< "Descriptions of all of commands are belows." << std::endl << std::endl;
	
	std::cout	<< "if you like this application. Please give star. Have Fun!" << std::endl << std::endl;
	
	std::cout	<< "--demo for running and viewing the test" << std::endl << std::endl;
	
	std::cout	<< "--loop for application menu running" << std::endl << std::endl;
	
	std::cout	<< "--encoding for encoding, if you enter only one argument as --encoding,"
				<< "input from standard input is expected."
				<< "If you give the input string as an argument after --encoding," 
				<< " you are not expected to enter the input string separately." 
				<< "If you are specifying an input string that will contain more than one word,"
				<< "please put it in quotation marks." 
				<< std::endl << std::endl;

	std::cout	<< "--decoding for decoding, if you enter only one argument as --decoding,"
				<< "input from standard input is expected."
				<< "If you give the input string as an argument after --decoding,"
				<< " you are not expected to enter the input string separately."
				<< "If you are specifying an input string that will contain more than one word,"
				<< "please put it in quotation marks."
				<< std::endl;
}

const MorseTree init_morse_alphabet() {
	MorseTree m_tree;
	m_tree.insert('a', ".-");
	m_tree.insert('b', "-...");
	m_tree.insert('c', "-.-.");
	m_tree.insert('d', "-..");
	m_tree.insert('e', ".");
	m_tree.insert('f', "..-.");
	m_tree.insert('g', "--.");
	m_tree.insert('h', "....");
	m_tree.insert('i', "..");
	m_tree.insert('j', ".---");
	m_tree.insert('k', "-.-");
	m_tree.insert('l', ".-..");
	m_tree.insert('m', "--");
	m_tree.insert('n', "-.");
	m_tree.insert('o', "---");
	m_tree.insert('p', ".--.");
	m_tree.insert('q', "--.-");
	m_tree.insert('r', ".-.");
	m_tree.insert('s', "...");
	m_tree.insert('t', "-");
	m_tree.insert('u', "..-");
	m_tree.insert('v', "...-");
	m_tree.insert('w', ".--");
	m_tree.insert('x', "-..-");
	m_tree.insert('y', "-.--");
	m_tree.insert('z', "--..");
	m_tree.insert('ä', ".-.-");
	m_tree.insert('ö', "---.");
	m_tree.insert('ü', "..--");
	m_tree.insert('ß', "...--..");
	m_tree.insert('1', ".----");
	m_tree.insert('2', "..---");
	m_tree.insert('3', "...--");
	m_tree.insert('4', "....-");
	m_tree.insert('5', ".....");
	m_tree.insert('6', "-....");
	m_tree.insert('7', "--...");
	m_tree.insert('8', "---..");
	m_tree.insert('9', "----.");
	m_tree.insert('0', "-----");
	m_tree.insert('.', ".-.-.-");
	m_tree.insert(',', "--..--");
	m_tree.insert(':', "---...");
	m_tree.insert('?', "..--..");
	m_tree.insert('(', "-.--.-");
	m_tree.insert(';', "-.-.-.");
	m_tree.insert('-', "-....-");
	m_tree.insert('+', ".-.-.");
	m_tree.insert('/', "-..-.");
	m_tree.insert('\'', ".----.");
	m_tree.insert('=', "-...-");
	m_tree.insert('\"', ".-..-.");
	m_tree.insert('!', "..--.");
	m_tree.insert(' ', "");
	return m_tree;
}

void testing(const MorseTree& m_tree) {
	std::string input = "This is is a test text. 1234567890";
	std::cout << "Input: " << input << std::endl;
	std::cout << std::endl;
	std::string encode_str = m_tree.encode(input);
	std::cout << "Encoding result: " << encode_str << std::endl;
	std::cout << std::endl;
	std::cout << "Decoding result: " << m_tree.decode(encode_str) << std::endl;
	std::cin.ignore();
}

void mainloop(const MorseTree& m_tree) {
	system("cls");
	bool isFinish = false;
	char choice;
	while (!isFinish) {
		std::cout << "Morse Alphabet Menu: " << std::endl;
		std::cout << "1-Encoding" << std::endl;
		std::cout << "2-Decoding" << std::endl;
		std::cout << "3-Quit" << std::endl;
		choice = _getch();
		std::string input;
		std::string output;
		try {
			switch (choice) {
			case '1':
				std::cout << "Please input encoding string" << std::endl;
				getline(std::cin, input);
				std::cout << "Encoding String: " << m_tree.encode(input) << std::endl;
				break;
			case '2':
				std::cout << "Please input decoding string" << std::endl;
				getline(std::cin, input);
				std::cout << "Decoding String: " << m_tree.decode(input) << std::endl;
				break;
			case '3':
				isFinish = true;
				std::cout << "Program is closing";
				break;
			}
		}
		catch (const char* exception) {
			std::cout << exception << std::endl;
		}
		std::cout << std::endl;
	}
}



