#include <fstream>
#include <string>

void writeToFile(const std::string& name, const std::string& email) {
    std::ofstream outFile("output.txt", std::ios::app); // appends to file
    if (outFile.is_open()) {
        outFile << "Name: " << name << "\n";
        outFile << "Email: " << email << "\n\n";
        outFile.close();
    }
}