#include <stdio.h>

struct command {
  char *name;
  void (*function) (void);
};

// start 
struct command commands[] = {
  {"quit", quit_command}，
  {"help", help_command},
  ...
};
// end

#define COMMAND(NAME) { #NAME, NAME ## _command }
// 等价替换为
struct command commands[] = {
  COMMAND (quit),
  COMMAND (help),
  ...
};
