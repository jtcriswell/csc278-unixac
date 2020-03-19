/*
 * Skeleton code for Unix Access Control assignment
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

/* Define constants for the three user IDs */
static const uid_t jim  = 10;
static const uid_t john = 20;
static const uid_t judy = 30;

/*
 * Function: getdirname()
 *
 * Description:
 * 	Given an absolute pathname with three top-level directories (the first
 * 	being the root directory), create a new pathname that includes only
 * 	the first set of pathname components.
 *
 * Inputs:
 * 	pathname   - A pointer to a string containing the pathname.  The
 * 	             pathname *must* be of the form /dir1/dir2/file.
 *
 * 	components - The number of components to include in the resulting
 * 	             pathname.
 *
 * Return Value:
 * 	Success - A pointer to the new pathname (which is allocated on the heap)
 * 	          is returned.
 * 	Error   - Otherwise, a NULL pointer is returned.
 */
char *
getdirname (char * pathname, unsigned int components) {
	/* Index for iterating through the levels of directories */
	unsigned int index;

	/* Pointer to duplicated directory name */
	char * dirname;

	/* Pointer into the string */
	char * p;

	/*
	 * Iterate through each directory name until we hit the index and
	 * then duplicate the directory name up to that point.
	 */
	p = pathname;
	for (index = 0; index < components; ++index) {
		/*
		 * Find the next directory deliminator character.
		 */
		++p;
		if ((p = strchr (p, '/')) == NULL) {
			return NULL;
		}
	}

	*p = '\0';
	dirname = strdup (pathname);
	*p = '/';
	return dirname;
}

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
	/* File descriptor for the file we will open */
	int fd;

	/* Length of data read from file */
	int length;

	/* Buffer into which to read data */
	unsigned char buffer[1024];

	/* Buffer to write to file */
	unsigned char * output = "Mighty Mighty Bosstones\n";

	/*
	 * Ensure that the program was executed with the correct number of
	 * arguments and that the argument is properly formatted.  If not,
	 * terminate early.
	 */
	if (argc != 2) {
		fprintf (stderr, "Usage: %s <pathname>\n", argv[0]);
		return 1;
	}
	if (argv[1][0] != '/') {
		fprintf (stderr, "%s must be an absolute path\n", argv[1]);
		return 1;
	}

	/*
	 * Set the group IDs.  The choice of 100 is arbitrary.
	 */
	if ((setresgid (100, 100, 100)) == -1) {
		perror ("Failed to set group IDs");
		return 1;
	}

	/*
	 * Simulate executing two setuid binaries as described in Quiz 3.
	 */
	if ((setresuid (john, judy, jim)) == -1) {
		perror ("Failed to set user IDs");
		return 1;
	}

	/*
	 * TODO: Students should insert their code here so that the subsequent
	 * call to open() succeeds.
	 */
	printf ("%s\n", getdirname(argv[1], 1));
	printf ("%s\n", getdirname(argv[1], 2));

	/*
	 * Open the file.
	 */
	if ((fd = open (argv[1], O_RDWR)) == -1) {
		perror ("Failed to open file");
		return 1;
	} else {
		/*
		 * Read data from the file and print it to the screen.  We
		 * flush the standard output file pointer so that a simple call
		 * to the write() system call to the standard output file
		 * descriptor will not rearrange the output due to buffering.
		 */
		if ((length = read (fd, buffer, sizeof (buffer))) == -1) {
			perror ("Failed to read file");
			return 1;
		}
		fflush (stdout);
		write (STDOUT_FILENO, buffer, length);

		/*
		 * Replace the contents of the file with new contents.
		 */
		if ((lseek (fd, 0, SEEK_SET)) == -1) {
			perror ("Failed to seek to beginning of file");
			return 1;
		}

		if ((write (fd, output, strlen (output))) == -1) {
			perror ("Failed to read file");
			return 1;
		}
	}
	return 0;
}
