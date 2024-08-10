# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

void main() {
	int fd;
	fd = open("lol", O_RDWR |  O_EXCL);
	if (fd == -1){
		printf("bruh - errno = (%d)\n", errno);
		perror("ERROR:");
	}
	else
	{
		printf("\n open() system call executed successfully lol, the file descriptor of opened file is (%d)\n", fd);
	}
}
