#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TOKENS_BUFFER_SIZE 64
#define LINE_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

extern char **environ;
/**
 * struct builtins - Has builtins and associated functions
 * @arg: Builtins name
 * @builtin: Matching builtin functions
 */
typedef struct builtins
{
	char *arg;
	void (*builtin)(char **args, char *line, char **env);
} builtins_t;

void shell(int ac, char **av, char **env);
char *_getline(void);
char **split_line(char *line);
int execute_prog(char **args, char *line, char **env, int flow);
int check_for_builtins(char **args, char *line, char **env);
int launch_prog(char **args);
void exit_shell(char **args, char *line, char **env);
void env_shell(char **args, char *line, char **env);
int _strcmp(char *s1, char *s2);
char *find_path(char *args, char *tmp, char *er);
char *search_cwd(char *filename, char *er);
int bridge(char *check, char **args);
void prompt(void);
int builtins_checker(char **args);
char *save_path(char *tmp, char *path);
char *read_dir(char *er, struct dirent *s, char *fi, int l, char *p, char *t);
char *_getenv(char *env);
char *_strstr(char *haystack, char *needle);
int _strlen(char *s);
void env(char **env);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void prompt(void);
char *get_line(void);
char **split_line(char *line);
char *get_env(char **env);
char *pathCat(char *dir, char *av);
char **dirTok(char **env);
void loop(char **env);
char *checkPath(char **dir, char *command);
int execute(char *fullPath, char **command);
int exit_sh(char **command);
int cd(char **command);
int printenv(char **command);
int checkBuiltins(char *combine, char **command);
void handler(int sig);
void buffers1(char *line, char **command);
void buffers2(char **dir, char *combine);
void buffers3(char **tokens, char *buf);
void buffers4(char **tok, char *buf2);
void buffers5(char *dup);

#endif
