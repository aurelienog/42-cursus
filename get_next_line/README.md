*This project has been created as part of the 42 curriculum by aunoguei.*

# Get Next Line

## Description

***Get Next Line*** is a project that consists of implementing a function that reads line by line in a file descriptor, in order to gain a deeper understanding of the C language and static variable.

**Function behavior**
- Reads from a given file descriptor
- Returns a line ending with `\n`, except at EOF
- Returns `NULL` on error or when no more lines are available

## Instructions

**Single file descriptor** :
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c.  
Compiled with and without the -D BUFFER_SIZE=n flag, defining how many bytes are read per read() system call.

**Multiple file descriptors**:
cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c.  
Compiled with and without the -D BUFFER_SIZE=n flag, defining how many bytes are read per read() system call.

## Resources
man 2 read
https://www.w3schools.com/c/ref_keyword_static.php
