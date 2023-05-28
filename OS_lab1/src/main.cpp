#include <iostream>
#include <boost/process.hpp>
#include <fstream>
#include <cstdio>

namespace bp = boost::process;

bool ExecutionCreator(std::string& file, std::string number) {
    std::vector<std::string> creator_args = {file, number};
    bp::child creator("../objects/Creator", creator_args);
    creator.wait();
    if (creator.exit_code() != 0) {
        return EXIT_FAILURE;
    }

    return 0;
}

bool ExecutionReporter(std::string& fileOUT, std::string fileIN, std::string pay) {
    std::vector<std::string> reporter_args = {fileIN, fileOUT, pay};
    bp::child reporter("../objects/Reporter", reporter_args);
    reporter.wait();
    if (reporter.exit_code() != 0) {
        std::cerr << "Creator failed with exit code " << reporter.exit_code() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}

bool delete_binary_file(const std::string& filename) {
    std::remove(filename.c_str());
    return 0;
}

void displayFile(const std::string& filename) {
    std::ifstream inputFile(filename, std::ios::binary);

    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    inputFile.seekg(0, std::ios::end);
    std::streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);
    char* buffer = new char[fileSize];
    inputFile.read(buffer, fileSize);
    std::cout << "Contents of file " << ":\n";
    std::cout.write(buffer, fileSize);
    std::cout << "\n";
    delete[] buffer;
    inputFile.close();
}

int main() {
    std::string number, FileBin;
    std::cout << "Enter bin File name: ";
    std::cin >> FileBin;
    std::cout << "Enter amount of quires: ";
    std::cin >> number;
    if (ExecutionCreator(FileBin, number)) {
        delete_binary_file(FileBin);
        return EXIT_FAILURE;
    }

    displayFile(FileBin);
    std::string FileReport;
    std::string pay;
    std::cout << "Enter bin File name: ";
    std::cin >> fileIN;
    std::cout << "Enter output File name: ";
    std::cin >> fileOUT;
    fileOUT = "../reports/" + fileOUT;
    std::cout << "Enter pay for an hour: ";
    std::cin >> pay;
    if (ExecutionReporter(FileReport, fileIN, pay)) {
        delete_binary_file(FileBin);
        return EXIT_FAILURE;
    }

    displayFile(FileReport);
    delete_binary_file(FileBin);

    return 0;
}
