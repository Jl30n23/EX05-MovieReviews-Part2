//
// Created by jp on 4/12/19.
//

#include <iostream>
#include <tuple>
#include "nearestneighbor.h"

namespace edu { namespace sbcc { namespace cs140 {

//function, which takes a target, a corpus of reviews along with the size of the corpus
//and the number of elements in all the arrays
            std::tuple<double, size_t*, size_t> findNearestNeighbor(uint8_t *target, uint8_t **corpus, size_t corpusSize, size_t arraySize){

                indices[0] = 1;
                count = 1;

                if (target == nullptr)
                    return std::make_tuple(distance, indices, nullptr);
//return std::make_tuple(distance, indices, count);
//return std::make_tuple(nearest, indices, count);
//return std::make_tuple(-1, size_t*, size_t);

//will find all the entries in the corpus with the minimum distance from the target.
                for (int Row = 0; Row < corpusSize; Row++) {
                    float distance = 0.0;

//returns the minimum distance , an array of indices of all the rows that are at the minimum distance
// and the number of rows at that minimum
                    for (int Col = 0; Col < arraySize; Col++) {
                        size_t *indices = new int[corpusSize];
                        size_t count = 0;
                        distance += target[Col] - corpus[Row][Col];
//distance = (target[Col] - corpus[Row][Col]) + distance; (same)
                    }
                }

                return std::make_tuple(distance, indices, nullptr);
//return std::make_tuple(distance, indices, count);
//return std::make_tuple(nearest, indices, count);
//return std::make_tuple(-1.0, size_t*, size_t);

            };}}}