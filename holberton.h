#ifndef shelly
#define shelly
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define EXT 0
#define BUILT 1

/**
 * struct bash - structure that contains all relevant data on runtime
 * @args: argument vector
 * @id: id token (0- intern or 1 - extern)
 * @cont: status of the shell
 * @name: name
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for shell_project
 */
typedef struct bash
{
	char **args;
	int id;
	int cont;
	char *name;
	struct bash *next;
} bash_shell;

/**
* struct builtins - type of builtins
*
* @built: command
* @f: the function assoiated
*/
typedef struct builtins
{
	char *built;
	int (*f)(bash_shell *h);
} builtin;

/**
* struct aliases - type of builtins
*
* @name: command
* @value: the function assoiated
* @next: next
*/
typedef struct aliases
{
	char *name;
	char *value;
	struct aliases *next;
} alias;
char **empty_path(void);
int setpid(int *pid);
int _atoi(char *s);
int setstatus(int *stat);
char *print_number(int n);
char *crear_name(char  *name);
int have_alias(char *buf, int i);
void buffer_filter(char **buffer, ssize_t *p);
void _replacealias(alias *ali, char *newbuf, int *pos);
alias *_isalias(char *buf, int *i);
void _ignorecomments(char *buf, int *i);
void _replacevar(char *buf, char *newbuf, int *i, int *pos);
int _isespcialchr(char c);
int istoken(char c);
void print_all_alias(void);
int print_one_alias(char *name);
int _strcmp(char *s1, char *s2);
alias *setalias(char **tokens);
alias *buscar_alias(alias *head, char *name);
int _have_value(char *arg);
char **token_alias(char *alias);
int _quote_end(char *s1);
char *_concat(char **args, int *pos, int size);
int _alias(bash_shell *h);
alias *add_alias(alias **head, char *name, char *value);
char *get_map(char *buf);

/* Array of pointers to environment strings*/
extern char **environ;

int _setenviron(bash_shell *h);
int _unsetenv(bash_shell *h);
int _strlen(char *str);
char  *getvaderdir(void);
int chtopreviousdir(void);
char *_getenvvar(char *varname);
char **_setenv(char *varname, char *valor);
int buscar(char **environ, char *varname);
char **getrealenv(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_getline(ssize_t *pos, char *pathname);
bash_shell *add_node(bash_shell **head, char **args, int id, int cont, char *n);
bash_shell *_getargs(char *buf, ssize_t *pos, char *name);
char **fill_nodes(char *buf, int sp, ssize_t *pos, int *paux);
int clfun(char **arg);
int look(char *fun);
void prompt(void);
int _readandcpy(char *fr, char *to, char *buf);
char *getvar(char *varname, char *buf);
void freecommand(bash_shell *h);
void getentorno(void);
void funexc(bash_shell *h);
void _extern(bash_shell *h);
void _built(bash_shell *h);
int salir(bash_shell *h);
int _history(bash_shell *h);
int _env(bash_shell *h);
int _help(bash_shell *h);
int _cd(bash_shell *h);
void handle_signal(int s);
int numdirectories(char *path);
int _strlen2(char *s);
char *currentpath(void);
char *dirandcommand(char *crtdir, char *aux, char *com);
int search_file_env(bash_shell *h);
void imprimir_error_env(bash_shell *h);
char *clpath(char *path);
int absolutepath(char *path);
char *filtro1(char *path);
char *filtro2(char *filter);
int aredots(char *path, int pos, int size);
int lukeSkywalker(void);
int darthVader(void);
void imprimir_error_setenv(bash_shell *h);
void imprimir_error_unsetenv(bash_shell *h);
void imprimir_error_setenv(bash_shell *h);
void imprimir_errores_history(bash_shell *h);
void imprimir_errores_help(bash_shell *h);
void imprimir_errores_cd(bash_shell *h);
char *getpath(void);
char **notfoundvar(char **env, char **cpyenv, char *newvar);
void imprimir_error(bash_shell *h);
int justhelp(char *pathandfile, int l, char *filejusthelp);
void printhelp_text(char **filenames, int *posi, char *pathandfile);
int nextdir(char *filter, int i);
int _isespecialchr(char c);
int _atoi(char *c);

#endif
