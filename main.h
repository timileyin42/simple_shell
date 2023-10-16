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
 * struct command_s - singly linked list
 * @args: argument
 * @id: id token (0- intern or 1 - extern)
 * @cont: cont
 * @name: name
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for shell_project
 */
typedef struct command_s
{
	char **args;
	int id;
	int cont;
	char *name;
	struct command_s *next;
} command_t;

/**
* struct builtins - type of builtins
*
* @built: command
* @f: the function assoiated
*/
typedef struct builtins
{
	char *built;
	int (*f)(command_t *h);
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
int _alias(command_t *h);
alias *add_alias(alias **head, char *name, char *value);
char *get_map(char *buf);

/* Array of pointers to environment strings*/
extern char **environ;

int _setenviron(command_t *h);
int _unsetenv(command_t *h);
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
command_t *add_node(command_t **head, char **args, int id, int cont, char *n);
command_t *_getargs(char *buf, ssize_t *pos, char *name);
char **fill_nodes(char *buf, int sp, ssize_t *pos, int *paux);
int clfun(char **arg);
int look(char *fun);
void prompt(void);
int _readandcpy(char *fr, char *to, char *buf);
char *getvar(char *varname, char *buf);
void freecommand(command_t *h);
void getentorno(void);
void funexc(command_t *h);
void _extern(command_t *h);
void _built(command_t *h);
int salir(command_t *h);
int _history(command_t *h);
int _env(command_t *h);
int _help(command_t *h);
int _cd(command_t *h);
void handle_signal(int s);
int numdirectories(char *path);
int _strlen2(char *s);
char *currentpath(void);
char *dirandcommand(char *crtdir, char *aux, char *com);
int search_file_env(command_t *h);
void imprimir_error_env(command_t *h);
char *clpath(char *path);
int absolutepath(char *path);
char *filtro1(char *path);
char *filtro2(char *filter);
int aredots(char *path, int pos, int size);
int lukeSkywalker(void);
int darthVader(void);
void imprimir_error_setenv(command_t *h);
void imprimir_error_unsetenv(command_t *h);
void imprimir_error_setenv(command_t *h);
void imprimir_errores_history(command_t *h);
void imprimir_errores_help(command_t *h);
void imprimir_errores_cd(command_t *h);
char *getpath(void);
char **notfoundvar(char **env, char **cpyenv, char *newvar);
void imprimir_error(command_t *h);
int justhelp(char *pathandfile, int l, char *filejusthelp);
void printhelp_text(char **filenames, int *posi, char *pathandfile);
int nextdir(char *filter, int i);
int _isespecialchr(char c);
#endif
