#include "Application.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "windows.h"

void Application::help()const {
	std::cout << "Welcome to the Morse Code App. Here is the app's help menu." << std::endl << std::endl;
	std::cout << "First of all, the purpose of this application is to encode and decode any text with morse code rules."
		<< " If you want to learn more about Morse code, please visit https ://en.wikipedia.org/wiki/Morse_code." << std::endl << std::endl;


	std::cout << "There are some commands. There are --demo, --loop, --encoding, --decoding." << std::endl << std::endl;

	std::cout << "Descriptions of all of commands are belows." << std::endl << std::endl;

	std::cout << "if you like this application. Please give star. Have Fun!" << std::endl << std::endl;

	std::cout << "--demo for running and viewing the test" << std::endl << std::endl;

	std::cout << "--loop for application menu running" << std::endl << std::endl;

	std::cout << "--play for voicing a morse code encoded value." << std::endl << std::endl;

	std::cout << "--encoding for encoding, if you enter only one argument as --encoding,"
		<< "input from standard input is expected."
		<< "If you give the input string as an argument after --encoding,"
		<< " you are not expected to enter the input string separately."
		<< "If you are specifying an input string that will contain more than one word,"
		<< "please put it in quotation marks."
		<< std::endl << std::endl;

	std::cout << "--decoding for decoding, if you enter only one argument as --decoding,"
		<< "input from standard input is expected."
		<< "If you give the input string as an argument after --decoding,"
		<< " you are not expected to enter the input string separately."
		<< "If you are specifying an input string that will contain more than one word,"
		<< "please put it in quotation marks."
		<< std::endl;
}

MorseTree Application::init_morse_alphabet() {
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

void Application::demo()const {
	std::string input = "This is a test text. 1234567890";
	std::cout << "Input: " << input << std::endl;
	std::cout << std::endl;
	std::string encode_str = m_tree.encode(input);
	std::cout << "Encoding result: " << encode_str << std::endl;
	std::cout << std::endl;
	std::cout << "Decoding result: " << m_tree.decode(encode_str) << std::endl;
}

void Application::mainloop() const{
	system("cls");
	bool isFinish = false;
	char choice;
	std::string input;
	std::string output;
	while (!isFinish) {
		std::cout << "Morse Alphabet Menu: " << std::endl;
		std::cout << "1-Encoding" << std::endl;
		std::cout << "2-Decoding" << std::endl;
		std::cout << "3-Play" << std::endl;
		std::cout << "4-Play last output" << std::endl;
		std::cout << "5-Quit" << std::endl;
		choice = _getch();

		switch (choice) {
		case '1':
			std::cout << "Please input encoding string" << std::endl;
			getline(std::cin, input);
			output = m_tree.encode(input);
			std::cout << "Encoding String: " << output << std::endl;
			break;
		case '2':
			std::cout << "Please input decoding string" << std::endl;
			getline(std::cin, input);
			try {
				output = m_tree.decode(input);
				std::cout << "Decoding String: " << output << std::endl;
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;
		case '3':
			std::cout << "Please input encoding string for voicing." << std::endl;
			getline(std::cin, input);
			play(input);
			break;
		case '4':
			play(output);
			break;
		case '5':
			isFinish = true;
			std::cout << "Program is closing";
			break;
		}

		std::cout << std::endl;
	}
}

void Application::beep(int sound_time,int sleep_time)const{
    Beep(523,sound_time);
    Sleep(sleep_time);
}

void Application::play(const std::string& encoding_value)const{
	for(char c : encoding_value){
		switch(c){
			case '.':
			beep(450,300);
			break;
			case '-':
			beep(900,300);
			break;
			case ' ':
			Sleep(300);
			break;
		}
	}
}

void Application::run(int argc,char** argv){
    bool is_play=false;
	if (argc == 1 || (argc == 2 && strcmp("--help", argv[1]) == 0))
		help();
	else {
		try {
			m_tree = init_morse_alphabet();
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
			exit(-1);
		}
		if (argc == 2) {
			std::string command = argv[1];
			if (command == "--demo") {
				demo();
			}
			else if (command == "--loop") {
				mainloop();
			}
			else if(command == "--play"){
				std::string input;
				std::getline(std::cin, input);
				play(input);
			}
			else if (command == "--encoding") {
				std::string input;
				std::getline(std::cin, input);
				std::cout << m_tree.encode(input) << std::endl;
			}
			else if (command == "--decoding") {
				std::string input;
				std::getline(std::cin, input);
				std::cout << m_tree.decode(input) << std::endl;
			}
		}
		else if (argc > 2) {
			
			std::string command_1(argv[1]);
			std::string command_2(argv[2]);

			if(command_1 == "--play" || command_2 == "--play")
				is_play = true;

			if(command_1 == "--play")
				std::swap(command_1,command_2);

			std::string input;
			for(size_t i= is_play ? 3 : 2;i < argc; i++)
				input += std::string(argv[i]) + ' ';
			
			if (command_1 == "--encoding") {
				std::string encoding_value = m_tree.encode(input);
				std::cout << encoding_value << std::endl;
				if(is_play){
					play(encoding_value);
				}
			}
			else if (command_1 == "--decoding") {
				std::cout << m_tree.decode(input) << std::endl;
			}
		}
	}
}