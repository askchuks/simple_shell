#include "Alpha.h"
/**
 * main - main function
 * @argc: argument count
 * @argv: pointer parameter
 *
 * Return: integer
 */
int main(int argc, char **argv)
{
	info_t information[] = {INFO_INIT};
	int file_des;

	file_des = 2;
	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (file_des)
			: "r" (file_des));
	if (argc == 2)
	{
		file_des = open(argv[1], O_RDONLY);
		if (file_des == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				err_puts(argv[0]);
				err_puts(":0:Can't open file");
				err_puts(argv[1]);
				err_putchar('\n');
				err_putchar(BUFFER_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		information->read_fd = file_des;
	}
	pop_env(information);
	rd_hist(information);
	hsh(information, argv);
	return (EXIT_SUCCESS);
}
