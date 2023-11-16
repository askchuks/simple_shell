#ifndef ALPHA_H
#define ALPHA_H
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
#define UNSIGNED 2
#define LOWERCASE 1
#define UPPERCASE 2
#define HISTORY_FILE ".shell_history"
#define HISTORY_MAX 5120
#define GETLINE 0
#define STRTOK 0
extern char **env;
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
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \, 0, 0, 0}
typedef struct builtin
{
	int(*function)(info_t *);
	char *type;
} builtin_tab;
int _cmd(info_t *information, char *path);
int hsh(info_t *information, char **av);
int err_putchar(char c);
char *duplicate_char(char *pathstring, int begin, int stop);
void find_command(info_t *information);
void fork_command(info_t *information);
char *find_path(info_t *information, char *pathstring, char *command);
int find_builtin(info_t *information);
void err_puts(char *string);
int puts_fd(char *string, int file_des);
int loop_hsh(char **);
int get_line(info_t *information, char **pointer, size_t *len);
ssize_t input_buffer(info_t *information, char **buffer, size_t *length);
ssize_t get_input(info_t *information);
ssize_t read_buffer(info_t *information, char *buffer, size_t *n);
int put_fd(char c, int file_des);
int main(int argc, char **argv);
int _strcmp(char *string1, char *string2);
size_t _strlen(char *string);
char *_strcat(char *dest, char *src);
char *starts_with(const char *hay_st, const char *n);
char *_strdup(const char *string);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
void _puts(char *string);
char **_strtow(char *string, char *c);
char **__strtow(char *string, char c);
char *_strchr(char *, char);
char *_strncpy(char *dest, char *src, int i);
char *_strchr(char *string, char c);
char *_strncat(char *dest, char *src, int i);
int __free(void **pointer);
void *re_alloc(void *pointer, unsigned int previous_size, unsigned int new_size);
void __ffree(char **p);
char *_memset(char *c, char d, unsigned int n);
int _atoi(char *string);
int _delimiter(char c, char *delimiter);
int _alpha(int i);
int interact(info_t *information);
void rem_comment(char *buffer);
int _print_d(int user_input, int file_des);
char *_itoa(long int number, int a, int flag);
int _err_atoi(char *c);
void print_err(info_t *information, char *c);
int _cd(info_t *information);
int _help(info_t *information);
int __exit(info_t *information);
int _alias(info_t *information);
int _history(info_t *information);
int printAlias(list_t *node);
int alias_unset(info_t *information, char *string);
int alias_set(info_t *information, char *string);
int _env(info_t *information);
char get_environ(info_t information, const char *var_name);
int env_unset(info_t *information);
int env_set(info_t *information);
int pop_env(info_t *information);
int err_putchar(char c);
int build_hist(info_t *information, char *buffer, int count);
int wr_hist(info_t *information);
int rd_hist(info_t *information);
char *get_hist(info_t *info_det);
int rename_hist(info_t *information);
void free_list(list_t **head_pointer);
list_t *add_node(list_t **begin, const char *string, int number);
int del_node(list_t **begin, unsigned int index);
char *get_env(info_t *, const char *);
char **get_environment(info_t *information);
int set_env(info_t *information, char *variable, char *value);
int unset_env(info_t *info, char *variable);
list_t *add_node2(list_t **begin, const char *string, int number);
size_t print_list(const list_t *a);
int replace_variable(info_t *information);
int replacealias(info_t *information);
int replace_str(char **previous, char *current);
int _chain(info_t *information, char *buffer, size_t *p);
void check_chain(info_t *information, char *buffer, size_t *p, size_t i, size_t length);
ssize_t get_nodeindex(list_t *begin, list_t *current_node);
size_t list_length(const list_t *a);
list_t *node_starts_with(list_t *current_node, char *prefix, char s);
char **list_to_str(list_t *begin);
void info_set(info_t *information, char **c);
void clear_information(info_t *information);
void free_information(info_t *information, int i);
void sa_handler(__attribute__((unused))int n);
#endif
