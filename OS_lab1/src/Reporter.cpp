#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct employee {
    int num;
    char name[10];
    double hours;
};

bool compareEmployees(const employee& e1, const employee& e2) {
    return e1.num < e2.num;
}


int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr
                << "Error: not enough arguments. Usage: Reporter <input_file_name> <output_file_name> <hourly_pay_rate>"
                << "\n";
        return 1;
    }

    std::string inputFileName = argv[1];
    double hourlyPayRate = atof(argv[3]);

    if (hourlyPayRate < 0) {
        std::cerr
                << "Error: invalid hourly Pay Rate parameter"
                << "\n";
        return 1;
    }

    std::ifstream inputFile(inputFileName, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Error: can't open input file " << inputFileName << '\n';
        return 1;
    }

    std::vector<employee> employees;
    employee emp{};
    while (inputFile.read((char *) &emp, sizeof(employee))) {
        employees.push_back(emp);
    }

    sort(employees.begin(), employees.end(), compareEmployees);
    std::string outputFileName = argv[2];
    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Error: can't open output file " << outputFileName << '\n';
        return 1;
    }

    outputFile << "Report: \"" << inputFileName << "\":" << '\n';
    double totalPay = 0;
    for (const auto &employee: employees) {
        double pay = employee.hours * hourlyPayRate;
        outputFile << "Number: " << employee.num << ", Name: " << employee.name
        << ", worked hours: " << employee.hours << ", pay: " << pay << "$\n";
        totalPay += pay;
    }

    outputFile << "Total Pay: " << totalPay << "$\n";
    inputFile.close();
    outputFile.close();
}