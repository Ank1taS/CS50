#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(int argc,char **argv)
{
	int n;
	char buf[100];

    // checking numbers of arguments
	if (argc!=3)
	{
		perror("Invalid numbers of arguments !");
		return 1;
	}

	// opening source file in read-only mode
	int fd1=open(argv[1],O_RDONLY);
	// checking source file
	if (fd1== -1)
    {
        perror("1st File does not exist!!");
        return 1;
    }

	// opening destination file in read-only mode
	int fd2=open(argv[2],O_WRONLY);
	// checking destination file
	if (fd2 == -1)
    {
        perror("2nd File does not exist!!");
        return 1;
    }

    // copying source file to destination file
	while((n=read(fd1,buf,100)) > 0)
		write(fd2,buf,n);

    // closing both the files
	close(fd1);
	close(fd2);

    return 0;
}