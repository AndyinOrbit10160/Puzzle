/* This program reads a line form the console and verifies that it matches a
 * specific string.  The program succeeds if the string matches, otherwise, it
 * reports the error and returns failure. 
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Match
 * Returns true if line is equivalent to the hard-coded string. 
 *
 */

// Note: You are free to chose any safe-for-work string between 10 and 80
// characters long.  This function should return true if and only if the string
// pointed to by the parameter line is equivalent to your chosen string. 
// 
// Consider reading the manual for strcmp(3).  The manual is an on-line,
// terminal program called man.  The number in parenthesis refers to the manual
// section.  Section 3, for example, is the manual for library functions.  In
// the case of strcmp, it is in the C-library or libc for short.  To see the
// man-pages for strcmp(3), execute the following command in a terminal:
//
//   $man 3 strcmp
//
// The dollar-sign ($) is a generic prompt and is not part of the command.  The
// program is called man with two arguments: 3 and strcmp.  
//
// Before turning in your solution, remove the comment block that begin with the
// double slash (e.g., //).  If you solution is somewhat difficult to
// understand, add a line to the block comment above with hints to the reader.
//
// Just as a sanity check, the symbols true and false should not appear in your
// solution.  This is actually pretty easy.  It can be solved with a single line
// of code.  An if-statement is not required nor is it a good idea.  
bool matches(char* line) {

  char* str = "hello world";

  return strcmp (line, str) == 0;
}


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
