#include "utils.h"
#include <Windows.h> // Sleep()
#include <math.h> // pow()

void print(ActivityList const& al) {
	for (size_t i = 0; i < al.size(); i++)
		std::cout << al.at(i).getTitle() << std::endl;
}

void spin(ActivityList const& al) {
	if (!al.size()) return;
	for (int i = 1; i < 20; i++) {
		Sleep(static_cast<DWORD>(3 * pow(i, 1.8)));
		std::cout << al.at(rand() % al.size()).getTitle() << std::endl;
	}
	std::cout << al.at(rand() % al.size()).getTitle() << " <-" << std::endl;
}

void removeSpaces(std::string& buffer) {
	if (buffer.size()) {
		size_t index = std::string::npos;
		while (true) { // удаляем двойные пробелы
			index = buffer.find("  ");
			if (index == std::string::npos)
				break;
			buffer.erase(index, 1);
		}
	}
	if (buffer.size() && buffer.at(0) == ' ') // удаление пробела в начале строки
		buffer.erase(0, 1);
	if (buffer.size() && buffer.at(buffer.size() - 1) == ' ') // удаление пробела в конце строки
		buffer.erase(buffer.size() - 1, 1);
}

// вынести обработчика буфера в отдельную функцию
void readCommand(ActivityList& al, std::string& buffer, bool& run_status) {
	if (buffer.size() >= 2 && buffer.at(0) == '-') {
		char op = buffer.at(1);
		switch (op) {
		case 'a':
			if (buffer.size() > 2) {
				buffer.erase(0, 3);
				al.add(buffer);
			}
			break;
		case 'r':
			if (buffer.size() > 2) {
				buffer.erase(0, 3);
				al.remove(buffer);
			}
			break;
		case 'p':
			print(al);
			break;
		case 's':
			spin(al);
			break;
		case 'q':
			run_status = false;
			break;
		}
	}
	buffer.clear();
}


void read(ActivityList& al, std::string& buffer, char& c, bool& run_status) {
	std::cout << "to add:\t\t'-a <title>'\nto remove:\t'-r <title>'\nto print:\t'-p'\nto spin:\t'-s'\nto quit:\t'-q'\n";
	do {
		while (std::cin.get(c)) {
			if (c != '\n') { // запись в буфер
				buffer.push_back(c);
			}
			else { // обработка буфера
				if (buffer.empty()) continue;
				removeSpaces(buffer);
				readCommand(al, buffer, run_status);
				if (!run_status) break;
			}
		}
	} while (run_status);
}

int exec() {
	ActivityList& al = ActivityList::instance();
	std::string buffer;
	char c = '\0';
	bool run_status = true;
	read(al, buffer, c, run_status);
	return 0;
}