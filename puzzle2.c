/* This program reads a line from the console, verifies that it contains a
 * sequence of unsigned integers, and that those integers are the beginning of a
 * specific mathematical sequence.  The program succeeds if the string matches,
 * otherwise, it reports the error and returns failure.
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Matches
 * Returns true if line is a sequence of space-separated unsigned that matches
 * the beginning of a specific, infinite, mathematical sequence.  The input
 * defines the number of elements from the sequence.
 */

// There are several parts to the puzzle.  First is to extract natural numbers
// from a string.  Second is the verify that those numbers are the start of your
// favorite sequence.  Consider reading the manual for strtok(3) ans sscanf(3).
//
// Hint: ask yourself what is necessary for this function to return true?  Can
// you formally state this as loop-invariant?
//
// You may NOT use recursion to solve this puzzle.
//
// Before turning in your solution, remove the comment block that begin with the
// double slash (e.g., //).  If you solution is somewhat difficult to
// understand, add a line to the block comment above with hints to the reader.
bool matches(char* line) {
  return 0;
}


/* Main
 * Returns success if the input string matches (above).  Otherwise, it returns
 * failure.  
 *
 * There are really two failure modes: gitline falure, input mismatch.  In the
 * former case, perror is used to display the error condition set by getline.
 * In the latter case, the a brief error message is printed.  
 *
 * Note the if-statement that removes the trailing new-line.  The last character
 * from getline does not have to be a new-line, so the if-statement is
 * required.  
 */
// Do not modify this function!
int main() {
  bool   isSuccess = false;
  char*  line = NULL;
  size_t size = 0;
  ssize_t len = getline(&line, &size, stdin);

  if(-1 == len) {
    perror("getline");
  }
  else {
    
    if(line[len-1] == '\n') {
      line[len-1] = '\0';
    }
       
    isSuccess = matches(line);

    if(!isSuccess) {
      printf("Didn't match\n");
    }

    free(line);
  }

  return isSuccess ? EXIT_SUCCESS : EXIT_FAILURE;
}
