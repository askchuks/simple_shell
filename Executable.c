#include Alpha.h 

/**
* creating executable function
* Functions that will execute a prompt 
*
* using pid (process ID)
*/
void execute_command ( const char * command);
{
pid_t son_t = fork ();
If (son_t == -1)
{
perror ("fork");
exit (EXIT_FAILURE);
}
else if (son_pid == 0)
{
execlp ( command, (char *) NULL);
perror ("execlp");
exit (EXIT_FAILURE);
}
else
{
wait (NULL);
}
}
