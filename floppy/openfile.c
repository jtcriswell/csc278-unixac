/*
 * Skeleton code for Unix Access Control assignment
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>

/* Define constants for the three user IDs */
static const uid_t jim  = 10;
static const uid_t john = 20;
static const uid_t judy = 30;

/*
 * Function: main()
 *
 * Description:
 *   This function is the entry point of the program.  It should open the file
 *   specified on the command line.  The pathname to this file should have the
 *   format <dir1>/<dir2>/<filename>.  Each component should have the following
 *   attributes:
 *
 *   <dir1> : Owned by John.  Group is unknown. Permission bits are unknown.
 *   <dir2> : Owned by Jim.   Group is unknown.  Permission bits are unknown.
 *   <file> : Owned by Judy.  Grouip is unknown.  Permission bits are unknown.
 *
 * Inputs:
 *   argc - The number of arguments on the command line.
 *   argv - A pointer to an array of strings.  Each string is one argument to
 *          the program.
 *
 * Return value:
 *   0 - No error.
 *   1 - Some error occurred.
 */
int
main (int argc, char ** argv) {
	/*
	 * Simulate executing two setuid binaries as described in Quiz 3.
	 */
	setresuid (john, judy, jim);
	return 0;
}
