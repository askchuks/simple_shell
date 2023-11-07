#ifndef SHELLMAIN_H
#define SHELLMAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#define RD_BUFFER_SIZE 1024
#define WR_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define COMMAND_NOR 0
#define COMMAND_OR 1
#define COMMAND_AND 2
#define COMMAND_CHAIN 3
#define LOWERCASE 1
#define UPPERCASE 2
#define HISTORY_FILE ".shell_history"
#define HISTORY_MAX 5120
#define GETLINE 0
#define STRTOK 0
extern char **environ;
typedef struct list_string
{
	int number;
	char *string;
	struct list_string *next;
} list_t;
typedef struct passcode
{
	char *argument;
	char *argv;
	char *path;
	int argc;
	unsigned int count;
	int error_number;
	int count_flag;
	char *fname;
	char **environ;
	int stat;
	int env_change;
	list_t *alias;
	list_t *history;
	list_t *env;
	char *command_buffer;
	int history_count;
	int cmd_buffer_type;
	int read_fd;
} info_t;
#define INFO_INITIALIZATION \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \, 0, 0, 0}
typedef struct builtin
{
	int(*function)(info_t *);
	char *type;
} builtin_tab;
int is_command(info_t *, char *);
int hsh(info_t *, char **);
int e_putchar(char);
char *duplicate_char(char *, int, int);
void find_command(info_t *);
void fork_command(info_t *);
char *find_path(info_t *, char *, char *);
int find_builtin(info_t);
void err_puts(char *);
int puts_fd(char *string, int file_des);
int loop_hsh(char **);
int _putfd(char c, int file_des);
int _strcmp(char *, char *);
int _strlen(char *string);
char *_strcat(char *, char *);
char *start(const char *, const char *);
char *_strdup(const char *);
char *_strcpy(char *, char *);
int _putchar(char);
void _puts(char *);
char _strtow(char *, char *);
char new_strtow(char *, char);
char *_strchr(char *, char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
int b_free(void **);
void _realloc(void *, unsigned int, unsigned int);
void _free(char **);
char *_memset(char *, char, unsigned int);
int _atoi(char *string);
int _delimiter(char c, char *delimiter);
int is_alpha(int);
int interact(info_t *info);
void rem_comment(char *);
int _print_d(int, int);
char convert_int(long int, int, int);
int _err_atoi(char *);
void print_err(info_t *, char *);
int _cd(info_t *information);
int _help(info_t *information);
int _exit(info_t *information);
int _alias(info_t *information);
int _history(info_t *information);
int alias_unset(info_t *information, char *string);
int alias_set(info_t *information, char *string);
int _env(info_t *information);
char get_environ(info_t information, const char *var_name);
int env_unset(info_t *information);
int env_set(info_t *information);
int pop_env(info_t *information);
int build_hist(info_t *info_det, char *buffer, int count);
int wr_hist(info_t *info_det);
int rd_hist(info_t *info_det);
char *get_hist(info_t *info_det);
int renumber_hist(info_t *info_det);
void free_list(list_t **);
list_t *add_node(list_t **, const char *, int);
int del_node(list_t **. unsigned int);
list_t add_node_2(list_t **, const char *, int);
size_t print_list(const list_t *);
int rep_var(info_t *);
int rep_alias(info_t *);
int rep_str(char **, char *);
int is_chain(info_t *, char *, size_t *);
void is_chain2(info_t *, char *, size_t *, size_t, size_t);
ssize_t get_node(list_t *, list_t *);
size_t list_length(const list_t *);
list_t start_node(list_t *, char *, char);
char **string_list(list_t *);
#endif
