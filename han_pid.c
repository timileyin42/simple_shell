#include "holberton.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX 500


/**
 * setpid - set
 * @pid: pointer to status
 * Return: number of status
 */
int setpid(int *pid)
{
	static int _pid;
	static int flag;

	if (!pid && !flag)
	{
		_pid = fork();
		if (_pid == 0)
		{
			exit(0);
		}
		else
		{
			wait(NULL);
			_pid = _pid - 1;
		}
		flag = 1;
	}
	return (_pid);
}
