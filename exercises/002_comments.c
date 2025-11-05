// Exercise 002: Comments
//
// Comments are used to explain code to other programmers (and yourself!).
// C has two types of comments:
//   - Single line comments (like this one) start with //
//   - Multi-line comments start with /* and end with */
//
// Fix THREE comment-related bugs below so the code compiles and runs!
//
// EXPECTED: Comments are useful!
// EXPECTED: Learning C is fun!
// HINT: Watch out for unclosed comments and commented-out code

#include <stdio.h>

int main(void) {
    /* This is a multi-line comment
       that spans multiple lines
       but it's missing something...

    printf("Comments are useful!\n");

    // This line should print but it's commented out somehow
    // printf("Learning C is fun!\n");  TODO: Uncomment this line!

    /* Another comment here /* with a nested comment problem */

    return 0;
}
