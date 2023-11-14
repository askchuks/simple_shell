#include <stdio.h>
#include <stdlib.h>
#include "Alpha.h"
void print_environment()
{
extern char** environ;
int i=0;
for (int i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
i++
}
}

/**
*writing code for shell environment
*/
int main (int ac, char **av, char **env)
{
int i=0;
for (env[i])
{
printf("%s\n", env[i]);
i++
}
}


char *_getenv (const char **name)
{
extern char **environ;
int i=0;
char *key
while (environ [i])
{
Key=strkok (environ [i],"=");,
if (strcmp(key, name) ==0)
return (strkok (NULL, "="));
i++;
}
return (NULL);
}
int main ()
{
printf ("%s\n", _getenv ("ls"));
return (0);
