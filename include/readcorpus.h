//
// Created by aknight on 3/20/19.
//

#ifndef EX03_MOVIEREVIEWS_PART1_READCORPUS_H
#define EX03_MOVIEREVIEWS_PART1_READCORPUS_H

#include <string>

namespace unittest { namespace csv13 {
    void readCorpus(const std::string &filename, uint8_t **corpus, size_t corpusCount, size_t docSize);
}}

#endif //EX03_MOVIEREVIEWS_PART1_READCORPUS_H
