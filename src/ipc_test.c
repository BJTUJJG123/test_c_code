/*
 * interprocess communication
 */
#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
//#include ""
int pipe(int fd[2]);//success return 0; fail return -1;
void test_wrFIFO(void);
void main ()
{
    test_wrFIFO();
}
/*
 *只能用于亲缘关系的父子进程之间的通信
 * 而且是半双工进行通信
 */
void test_pipe(void)
{

  int fd[2];
  pid_t pid;
  char buff[20];

  if (pipe(fd) < 0)
  {
    printf("create pipe fail \n");
  }

  if ((pid = fork()) < 0)
  {
    printf("Fork fail \n");
  }
  else if (pid > 0)
  {
     close(fd[0]);
     write(fd[1], "hello world\n", 12);
  }
  else
  {
     close(fd[1]);
     read(fd[0], buff, 20);
     printf("%s \n", buff);
  }
}

/* FIFO-named pipe
 * 一旦创建了FIFO，就可以用一般的文件IO函数去操作它
 *O_NONBLOCK:非阻塞，只读open立即返回；只写open将出错返回-1；
 没有进程已经为读而打开该fifo，则其errno置为ENXIO
 */
/* 在read_fifo中创建fifo，所以要先执行read_fifo*/
void test_wrFIFO(void)
{
  int fd  = 0;
  int n, i;
  char buf[1024];
  time_t tp;
  
  printf("I am %d \n", getpid());

  if ((fd = open("fifo1", O_WRONLY)) < 0)
  {
        perror("open fifo error \n");
        exit(1);
  }
  
  for (i = 0; i < 20; i++)
  {
     time(&tp);
     n = sprintf(buf, "process %d time is %s \n", getpid(), ctime(&tp));
     printf("send messg: %s \n", buf);

     if (write(fd, buf, n+1) < 0)
     {
       perror("write fifo error \n");
       close(fd);
       exit(1);
     }

     sleep(1);

  }

  close(fd);
}
