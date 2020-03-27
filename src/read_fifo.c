#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <fcntl.h>
#include <sys/stat.h>

int main()
{
  int fd;
  int len;
  char buf[1024];
  /* 使用指定的文件名，创建管道 */
  if (mkfifo("fifo1", 0666) < 0 && errno!=EEXIST)
  {
    perror("mkfifo fail \n");
  }
  if ((fd = open("fifo1", O_RDONLY)) < 0)
  {
    perror("open fifo fail \n");
    exit(1);
  }

  while ((len = read(fd, buf, 1024)) > 0)
  {
    printf("read messg: %s \n", buf);

  }

  close(fd);
  return 0;
}
