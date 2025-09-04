/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colin_microshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:39:20 by copireyr          #+#    #+#             */
/*   Updated: 2025/03/11 11:39:34 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
 
static int  i;
 
void    err(char *msg, char *arg)
{
    write(STDERR_FILENO, "error: ", sizeof("error: "));
    while (*msg)
        write(STDERR_FILENO, msg++, 1);
    while (arg && *arg)
        write(STDERR_FILENO, arg++, 1);
    write(STDERR_FILENO, "\n", 1);
}
 
void    die(void)
{
    err("fatal", NULL);
    exit(1);
}
 
void     cd(char **argv)
{
    if (i != 2)
        err("cd: bad arguments", NULL);
    else if (chdir(argv[1]) == -1)
        err("cd: cannot change directory to ", argv[1]);
}
 
void    dup_and_close(int pipefd[2], int fd)
{
	dup2(pipefd[fd], fd);
	close(pipefd[0]);
	close(pipefd[1]);
}
 
void     run(char **argv, char **envp)
{
    bool has_pipe = argv[i] && !strcmp(argv[i], "|");
    int pipefd[2];

    if (has_pipe && pipe(pipefd) == -1)
        die();
    pid_t pid = fork();
    if (pid == -1)
        die();
    if (pid == 0)
    {
        argv[i] = NULL;
        if (has_pipe)
            dup_and_close(pipefd, STDOUT_FILENO);
        execve(*argv, argv, envp);
        err("cannot execute ", *argv);
        exit(1);
    }
    if (has_pipe)
        dup_and_close(pipefd, STDIN_FILENO);
    waitpid(pid, NULL, 0);
}
 
int     main(int argc, char **argv, char **envp)
{
    while (argc > 1 && argv[i])
    {
        argv += i + 1;
        i = 0;
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;
        if (i)
		{
			if (!strcmp(*argv, "cd"))
				cd(argv);
			else
				run(argv, envp);
		}
    }
}
