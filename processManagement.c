#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main() {
    // declare variables
    int n = 15;
    pid_t pList[15];
    int status;
    int zeroExitCounter = 0;
    int nonzeroExitCounter = 0;
    int sigCounter = 0;
    char operations[15][13] = {"echo", "touch", "ls", "date", "mkdir", "cp", "pwd", "cat", "ps", "stat", "history", "abort1", "abort2", "invalidcode1", "invalidcode2"};
    
    // create child processes
    printf("Parent process running, pid of the parent process is %d\n",getpid());
    for(int i=0; i<n; i++) {
        // create new child
        pid_t return_value;
        return_value = fork();
        
        if(return_value < 0){
            printf("fork() has failed during child creation");
            exit(1);
            }

        else if(return_value == 0){
            printf("\nChild index: %d, PID: %d, Operation: %s\n", i, getpid(), operations[i]);
            char *argv[] = {NULL, NULL};
            switch(i) {
                case 0:
                    argv[0] = "shellScripts/script0.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }
                    break;
                case 1: 
                    argv[0] = "shellScripts/script1.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }                    
                    break;
                case 2: 
                    argv[0] = "shellScripts/script2.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }                    
                    break;
                case 3: 
                    argv[0] = "shellScripts/script3.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }                    
                    break;
                case 4: 
                    argv[0] = "shellScripts/script4.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }                    
                    break;
                case 5: 
                    argv[0] = "shellScripts/script5.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }                     
                    break;
                case 6: 
                    argv[0] = "shellScripts/script6.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }                    
                    break;
                case 7: 
                    argv[0] = "shellScripts/script7.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }                    
                    break;
                case 8: 
                    argv[0] = "shellScripts/script8.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }                    
                    break;
                case 9: 
                    argv[0] = "shellScripts/script9.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }
                    break;
                case 10: 
                    argv[0] = "shellScripts/script10.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }
                    break;
                case 11: 
                    abort();
                    break;
                case 12:
                    abort();
                    break;
                case 13: 
                    argv[0] = "shellScripts/script13.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }                    
                    break;
                case 14: 
                    argv[0] = "shellScripts/script14.sh";
                    if (execvp(argv[0], argv) == -1) {
                        perror("Execution Failed");
                    }
                    break;
                default:
                    printf("invalid i");
            }
            exit(0);

        } else {
            pList[i] = return_value;
            waitpid(pList[i], &status, 0);

            // get exit status
            if (WIFEXITED(status)) {
                int exitCode = WEXITSTATUS(status);
                printf("Exit status: exit(), Exit Code: %d\n", exitCode);
                if (exitCode == 0) {
                    zeroExitCounter++;
                } else {
                    nonzeroExitCounter++;
                }
            } else if (WIFSIGNALED(status)) {
                int signalCode = WTERMSIG(status);
                printf("Exit status: signal(), Signal Code: %d\n", signalCode);
                sigCounter++;
            }
        }
    }

    printf("\n===== Summary =====\n");
    printf("Zero Exit Counter: %d\n", zeroExitCounter);
    printf("Non-Zero Exit Counter: %d\n", nonzeroExitCounter);
    printf("Signal Counter: %d\n", sigCounter);

    return 0;
}