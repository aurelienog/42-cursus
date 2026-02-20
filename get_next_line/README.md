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

##Algorithm Explanation and Justification

Overview
The objective of this project is to implement a function that reads a file descriptor line by line using the read() system call, while correctly handling buffering, memory allocation, and static storage between function calls.

The selected algorithm is based on incremental buffered reading with persistent static storage.

Algorithm Description

The function reads from the file descriptor in chunks of size BUFFER_SIZE. Each chunk is appended to a static string that stores previously unread data.

The algorithm follows these steps:

- Validate input (fd, and read() error check).
- Repeatedly call read() until:
 -- A newline character (\n) is found in the stash, or
 -- End of file is reached.
- Extract the line up to and including \n (if present).
- Update the stash by keeping only the remaining characters after the extracted line.
- Return the extracted line.
- Return NULL if there is nothing left to read or if an error occurs.

In the bonus version, a static array indexed by file descriptor is used to support multiple file descriptors simultaneously.

Justification

This approach was selected because:
It respects the project constraint of using read() only.
It supports any BUFFER_SIZE value.
It correctly handles lines longer than BUFFER_SIZE.
It preserves unread data between calls using static storage.
It allows efficient extension to multiple file descriptors.

The algorithm guarantees that each character is read and processed only once, resulting in linear time complexity relative to file size.
