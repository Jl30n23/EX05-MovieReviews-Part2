// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX05-String in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>

#include <iostream>
#include <fstream>
#include <cmath>

#include "gtest/gtest.h"

#include "nearestneighbor.h"
#include "readcorpus.h"
#include "GTestNoDeath.h"

namespace {

// Tests edu::sbcc:cs140::String.

    using std::istringstream;
    using std::ostringstream;
    using std::string;

    using edu::vcccd::vc::csv13::findNearestNeighbor;
    
    using namespace ::testing_internal;

    class NearestNeighborTest : public ::testing::Test {
    protected:
        static const uint64_t MAX_TESTED_SCORE = 20;
        static const uint64_t MAX_OVERALL_SCORE = 25;
        static uint64_t _testScore;

    protected:
        static void TearDownTestCase() {
            if (_testScore == MAX_TESTED_SCORE) {
                std::cout << std::endl << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << std::endl;
            } else {
                std::cout << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                          << ")" << std::endl;
            }

            std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                      << " where the remaining points" << std::endl;
            std::cout << "comes from grading related to documentation, algorithms, and other"
                      << std::endl;
            std::cout << "criteria." << std::endl << std::endl;
        }
    };

    uint64_t NearestNeighborTest::_testScore = 0;

    TEST_F(NearestNeighborTest, DefaultCase) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        uint8_t target[] = {0, 1, 0, 2, 0, 3};
        uint8_t *neighbors[1000];
        unittest::csv13::readCorpus("../reviews.txt", neighbors, 1000, 6);

        auto result = findNearestNeighbor(target, neighbors, 1000, 6);

        ASSERT_DOUBLE_EQ(0, std::get<0>(result)); // Nearest distance should be 0.0
        ASSERT_EQ(10, std::get<2>(result)); // Count of neighbors at that distance is 10
        _testScore += 5;

        size_t *nearestIndices = std::get<1>(result);
        ASSERT_EQ(59,  nearestIndices[0]);
        ASSERT_EQ(200, nearestIndices[1]);
        ASSERT_EQ(206, nearestIndices[2]);
        ASSERT_EQ(232, nearestIndices[3]);
        ASSERT_EQ(381, nearestIndices[4]);
        ASSERT_EQ(434, nearestIndices[5]);
        ASSERT_EQ(465, nearestIndices[6]);
        ASSERT_EQ(559, nearestIndices[7]);
        ASSERT_EQ(906, nearestIndices[8]);
        ASSERT_EQ(955, nearestIndices[9]);
        _testScore += 5;
    }

    TEST_F(NearestNeighborTest, NullPtrCase) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.

        uint8_t target[] = {1, 1, 3, 2, 0, 3};
        uint8_t *neighbors[1000];
        ASSERT_NO_DEATH(findNearestNeighbor(target, nullptr, 100, 6), ".*");
        ASSERT_NO_DEATH(findNearestNeighbor(nullptr, neighbors, 100, 6), ".*");
        ASSERT_NO_DEATH(findNearestNeighbor(target, neighbors, 100, 6), ".*");

        _testScore += 10;
    }

}