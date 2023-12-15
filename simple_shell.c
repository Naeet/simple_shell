#include "shell.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		interactive_mode();
	}
	else if (argc == 2)
	{
		non_interactive_mode(argv[1]);
	}
	else
	{
		fprintf(stderr, "Usage: %s [script]\n", argv[0]);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
