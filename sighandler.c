#include <stdio.h>
#include<signal.h>
#include<stdlib.h>
#include <unistd.h>
int done = 0;
void sig_handler(int signum) {
done = 1;
}
int main() {
int status;
signal(SIGUSR1, sig_handler);
while(! done)
 compute();
status = finalize();
exit(status);
}