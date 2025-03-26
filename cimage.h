#include <iostream>
#include <fstream>
#include <string>

void cimg_ppm(const std::string& filename, const std::string& content) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    outFile << content;
    outFile.close();
}