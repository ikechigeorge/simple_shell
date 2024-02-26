#ifndef __MAIN_H__
#define __MAIN_H__

#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <stdio.h>
#include <stddef.h>

extern char **environ;

#define PROMPT_MSG "$ "
#define PROMPT_LEN 2

#define UNUSED(x) (void)(x)

#ifndef PATH_MAX /* PATH_MAX is defined in limits.h */
#define PATH_MAX 1024
#endif /* PATH_MAX */

/**
 * struct info - Stores shell data
 * @line: commands typed
 * @interactive: shell mode
 * @shell_name: name of the shell
 * @exit_code: exit code of the shell
 */
typedef struct info
{
	char *line;
	int interactive;
	char shell_name[5];
	int exit_code;
} info_t;

/**
 * struct cmd - command structure
 * @command: format specifier
 * @f: command function
 */
typedef struct cmd
{
	char *command;
	void (*f)(info_t *);
} command_t;

int _atoi(char *ptr);
void _env(info_t *shell);
int count_array_size(char **array);
int invalid_argv(char **arg, info_t *data);
void hangle_path_null(char *path, char **arg, info_t *data);
void _exec(info_t *data);
void print_exit_error(info_t *data, char *ptr);
void __exit(info_t *data);
pid_t _fork(void);
char *_getenv(char *var);
size_t get_new_size(size_t oldsize);
char *realloc_buffer(char *buff, size_t newsize);
ssize_t _getline(char **line_str, size_t *nd, FILE *st_ream);
int _isdigit(int ab);
int is_valid_number(const char *string);
char *_strcat(char *cont, char *string);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *cont, const char *string);
char *_strdup(const char *string);
int _strlen(const char *string);
int _strncmp(const char *string1, const char *string2, size_t num);
size_t _strspn(const char *string, const char *acc);
char *_strtok(char *string, const char *chr);
void **realloc_array(void **realoc, int *arraysize, int *argc, char *strcopy);
char **get_argv(char *string);
char *get_exec_path(char *prog);
int main(__attribute__((unused)) int argc, char **argv);
void free_multiple(int mem, ...);
void free_array(void **arr, int arraysize);
void *_malloc(size_t _memsize);
void *_realloc(void *str, size_t _memsize);
void prompt(info_t *shelldata);
void run_cmd(info_t *shelldata);
void (*select_cmd(char *_cmd))(info_t *);

#endif /* __MAIN_H__ */
