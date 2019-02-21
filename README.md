## EX03-MovieReviews-Part1

The objective of this assignment is to familiarize yourselves with arrays, heap memory management and error checking.

This assignment is the beginning of a multi-assignment project called Movie Reviews. The goal of the overall project is
to implement a basic machine learning algorithm called Nearest Neighbor to predict the review values for movies a user has
not entered yet based on similar reviewers within a corpus of reviews. This assignment is the first step in that algorithm, 
which is to find the nearest neighbor given a target and a corpus.

In this assignment you will create a single function, called `findNearestNeighbor`, which takes a target, a corpus
of reviews along with the size of the corpus, and the number of elements in all the arrays. The function will then
find the entry in the corpus with the minimum distance from the target. The function then returns the minimum distance
and the entry in the corpus that had that minimum distance, as an array. Remember since you are returning two values
you will have to return these values as an `std::pair`.

### Getting Started

The first thing you will need to do is accept the invitation to this assignment
from GitHub Classroom. You can click [here](https://classroom.github.com/a/_eRWh5dJ) to accept the invitation. 

Be sure that you accept the invitation first and use the URL from
the your new project when you clone it in CLion.

### Writing the code for this Project

Writing the code for this project is very simple. You will create three files: a header and implementation of a function, and an implementation of main to test your personally test your code.

#### findNearestNeighbor

Your function should be in the namespace `edu::vcccd::vc::csv13` and should have the following declaration:

```cpp
namespace edu { namespace vcccd { namespace vc { namespace csv13 {
  std::pair<double, uint8_t> findNearestNeighbor(uint8_t *target, uint8_t **corpus, size_t corpusSize, size_t arraySize);
}}}}
```

To create this function you'll need a header file with a declaration so it can be used in other code, and an implementation file with the C++ code of this function.

##### nearestneighbor.h

First you'll need to create nearestneighbor.h. This is the only file that must be named exactly this. If you misspell, or use different capitalization, the test program will not compile.

In CLion in the project explorer, right-click the `include` directory
and chose `New => C++ Header File`. 

Under **Name** fill in
nearestneighbor. CLion will add the `.h` extension. Press **OK**. You should now see the file `nearestneighbor.h` in
the project explorer in the `include` directory.

Write your declaration of the `findNearestNeighbor` in here in the `edu::vcccd::vc::csv13` namepspace.

##### Implementation

Next you'll need to create the implementation, separately from the declaration, of the `findNearestNeighbor`. This can be done in any file in the `src` directory as long as it has the extension `.cc` and is not named `main.cc`. 

In CLion in the project explorer, right-click the `src` directory
and chose `New => C++ Source File`. 

Under **Name** fill in
nearestneighbor (or any other name besides `main`). CLion will add the extension, but by default 
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `nearestneighbor.cc` (or whatever you named the file) in
the project explorer in the `src` directory.

Write your implementation of the `findNearestNeighbor` in here in the `edu::vcccd::vc::csv13` namepspace.

#### main()

If you want to test this code yourself, without using the unit tests, which I recommend for at least the first few projects, then you will need to create a `main()` function in a file named `main.cc` in the `src` directory. It is very important that you name it exactly this way, or things might not compile properly.

In CLion in the project explorer, right-click the `src` directory
and chose `New => C++ Source File`. 

Under **Name** fill in
main. CLion will add the extension, but by default 
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `main.cc` in
the project explorer in the `src` directory.

Your main function should look something like this:

```cpp
#include "nearestneighbor.h"

int main() {
  // Put your code here that calls findNearestNeighbor with some valid input and write the result to the terminal.
  
  return 0;
}
```

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `NearestNeighbor | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It should look something like this:

```bash
nearest distance: 1.73205

Process finished with exit code 0
```
Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `NearestNeighbor_Gtest` and press the 
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from NearestNeighborTest
[ RUN      ] NearestNeighborTest.DefaultCase
[       OK ] NearestNeighborTest.DefaultCase (0 ms)
[ RUN      ] NearestNeighborTest.NullPtrCase
[       OK ] NearestNeighborTest.NullPtrCase (2 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 2 tests from NearestNeighborTest (2 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (2 ms total)
[  PASSED  ] 2 tests.

Process finished with exit code 0

```

Remember, You should also see your score for this
assignment minus code styling points which I will add later.

### Submitting the code for this project

Before submitting your code the first time, you will need to add a webhook to this project to trigger the build in the cloud. This process is simple, and only required once per assignment. First, go to the **Settings** tab at the top of this page. It's right next to **Insights**. Then along the left side select **Webhooks**. On the Webhooks page click **Add Webhook** and copy http://209.129.49.16:8080/github-webhook/ into the **Payload URL** input box and then click **Add Webhook**. That's it. Every time you push code now, a new build will test your latest changes. The results are pasted to the #build channel in slack.

First, right click on the project name, then select `Git -> Commit Directory...`. 
Make sure only the files you want to push are selected, `nearestneighbor.h`, `nearestneighbor.cc`, and `main.cc`. Then uncheck `Perform code analysis` and `Check TODO`. It's OK to leave them checked, but committing will take longer. Leave `Run git hooks` unchecked as well. Put a message in `Commit Message` and then press the **Commit** button. If anything goes wrong check the _Version Control_ view
in the lower left corner and select the _Console_ tab.
 
Finally, right click on the project name, then select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will then submit them to the cloud to have the tests run for grading. You can find your results
in the [#build](https://vc-csv13-spring2019.slack.com/messages/CFBKTRAAU) channel on slack.
