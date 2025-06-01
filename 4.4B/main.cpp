#include "MyString.h"

#include <iostream>

#include <locale>

#include <windows.h>�



void clearInputBuffer() {

	char c;

	while (std::cin.get(c) && c != '\n');

}



void showMenu() {

	std::cout << "\n����:\n";

	std::cout << "1. ������ ������\n";

	std::cout << "2. �������� ������ � ������\n";

	std::cout << "3. ������� ������� �������\n";

	std::cout << "4. �������� ������ ������ � �������\n";

	std::cout << "5. �������� ������� ������\n";

	std::cout << "0. �����\n";

	std::cout << "��� �����: ";

}



int main() {

	setlocale(LC_ALL, "Russian");



	MyString str;

	MyString second;



	int choice;



	do {

		std::cout << "������� ������: \"" << str << "\"\n";

		showMenu();

		std::cin >> choice;


		if (std::cin.fail()) {

			std::cout << "������������ ����. ����������, ������� �����.\n";

			std::cin.clear();

			clearInputBuffer();

			Sleep(1000);

			continue;

		}

		clearInputBuffer();



		switch (choice) {

		case 1: {

			char buffer[8192];

			std::cout << "������� ������: ";

			std::cin.getline(buffer, sizeof(buffer));

			str = MyString(buffer);

			std::cout << "������ ������� �������.\n";

			break;

		}

		case 2: {

			char ch;

			size_t pos;

			std::cout << "������� ������ ��� ������� (���� ������): ";

			ch = std::cin.get();

			clearInputBuffer();



			bool validInput = false;

			do {

				std::cout << "������� ������� ��� ������� (0 ��� ������): ";

				std::cin >> pos;

				if (std::cin.fail()) {

					std::cout << "������������ ����. ������� ����� ��������������� �����.\n";

					std::cin.clear();

					clearInputBuffer();

				}

				else {

					validInput = true;

				}

			} while (!validInput);

			clearInputBuffer();



			str += std::make_pair(ch, pos);

			std::cout << "������ '" << ch << "' �������� �� ������� " << pos << ".\n";

			break;

		}

		case 3:

			--str;

			std::cout << "������� ������� �������.\n";

			break;

		case 4: {

			char buffer[8192];

			std::cout << "������� ������ ������ ��� ����������: ";

			std::cin.getline(buffer, sizeof(buffer));

			second = MyString(buffer);

			str = str + second;

			std::cout << "������ ������ ���������.\n";

			break;

		}

		case 5:

			break;

		case 0:

			std::cout << "�����...\n";

			break;

		default:

			std::cout << "�������� �����. ����������, ���������� �����.\n";

			Sleep(1000);

		}

		if (choice != 0 && choice != 5) {

			Sleep(1000);

		}

	} while (choice != 0);

}