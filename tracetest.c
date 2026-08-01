#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int pid;

  printf(1, "=== Trace Inheritance Test ===\n");

  trace(1);

  pid = fork();

  if(pid == 0){
    getpid();
    trace(0);
    printf(1, "Child completed\n");
    exit();
  }

  wait();
  trace(0);

  printf(1, "Parent completed\n");
  exit();
}
