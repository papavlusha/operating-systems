#include <iostream>
#include <fstream>
#include <string>

struct employee {
    int num;
    char name[10];
    double hours;
};

void data_request(std::ofstream& output, int n);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: Creator [file name] [record count]\n";
        return 1;
    }

    std::ofstream out(argv[1], std::ios::binary);
    if (!out) {
        std::cout << "Unable to open file " << argv[1] << "\n";
        return 1;
    }

    int record_count = std::stoi(argv[2]);
    data_request(out, record_count);
    return 0;
}

void data_request(std::ofstream& output, int n) {
    for (int i = 0; i < n; ++i) {
        employee emp{};
        std::cout << "Enter employee number: ";
        std::cin >> emp.num;
        std::cout << "Enter employee name: ";
        std::cin >> emp.name;
        std::cout << "Enter hours worked: ";
        std::cin >> emp.hours;
        output.write((char *) &emp, sizeof(emp));
    }
    output.close();
}
