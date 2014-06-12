#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 80

#define MSG "hello world\n"

int main(void) {
  int n;
  int fd[2];

  pid_t pid;
  char line[MAXLINE];

  if (pipe(fd) < 0) {
    perror("pipe");
    exit(1);
  }

  if ((pid = fork()) < 0) {
    perror("fork");
    exit(1);
  }

  if (pid > 0) {
    close(fd[0]); // close read port
    write(fd[1], MSG, strlen(MSG));
    wait(NULL);
  } else {
    close(fd[1]);
    n = read(fd[0], line, MAXLINE);
    write(STDOUT_FILENO, line, n);
  }
  return 0;
}
