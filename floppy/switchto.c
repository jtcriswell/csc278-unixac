#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>

/*
 * Function: main()
 *
 * Description:
 *   Entry point for this program.
 *
 * Inputs:
 *   argc - The number of argument with which this program was executed.
 *   argv - Array of pointers to strings containing the command-line arguments. 
 *
 * Return value:
 *   0 - This program terminated normally.
 */
int
main (int argc, char ** argv) {
	int pid;
	int uid;
	if (argc != 2) {
		printf ("Usage: %s <uid>\n", argv[0]);
		return -1;
	}

	uid = atoi (argv[1]);
	printf ("Switching to %s = %d\n", argv[1], uid);

	/* Switch to the new user */
	setresuid (uid, uid, uid);

	/* Execute a shell */
	execl ("/bin/sh", "/bin/sh", 0);

	/* Exit the program */
	return 0;
}
