//
// Created by aknight on 3/20/19.
//

#include <string>
#include <fstream>
#include <iostream>

namespace unittest { namespace cs140 {
void readCorpus(const std::string &filename, uint8_t **corpus, size_t corpusCount, size_t docSize) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Unable to open corpus file: " << filename << std::endl;
        return;
    }

    size_t count = 0;
    for (; !in.eof() && count < corpusCount; count++) {
        corpus[count] = new uint8_t[docSize];
        for (size_t j = 0; j < docSize; j++) {
            uint32_t value;
            in >> value;
            corpus[count][j] = static_cast<uint8_t >(value);
        }
    }
}
}}
