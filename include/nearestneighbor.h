//
// Created by jp on 4/12/19.
//

#ifndef EX05_MOVIEREVIEWS_PART2_NEARESTNEIGHBOR_H
#define EX05_MOVIEREVIEWS_PART2_NEARESTNEIGHBOR_H

#include <iostream>

namespace edu { namespace sbcc { namespace cs140 {
            std::tuple<double, size_t*, size_t> findNearestNeighbor(uint8_t *target, uint8_t **corpus, size_t corpusSize, size_t arraySize);
        }}}}

#endif //EX05_MOVIEREVIEWS_PART2_NEARESTNEIGHBOR_H
