#include "shell.h"

int main()
{
	ssize_t nread;	/*save the return valueo¿ of getline*/
	size_t len = 0; /*parametro necesario para funcion getline*/
	char *line;	/*acá se guarda lo que se ingreso por getline*/
	pid_t rfork;	/*valor de retorno de fork y de wait*/
	int status;

	/*si se recibio parametros asigna av a refav*/
	/*si no, ejecuta el prompt para que el usuario ingrese los parametros*/
	if (!isatty(0))
	{
		nread = getline(&line, &len, stdin);
		strtok(line, "\n\t\r");
		start_func(line);
	}
	else
	{
		signal(SIGINT, &handle_signal);
		do
		{
			printf("#cisfun$ ");
			nread = getline(&line, &len, stdin);
			/*End of file, condition*/
			if (nread == EOF)
			{
				eof_func('\n');
				free(line);
				exit(0);
			}
			rfork = fork();
			if (rfork == 0)
			{
				strtok(line, "\n\t\r");
				start_func(line);
			}
			else
			{
				wait(&status);
			}

		} while (nread != -1);
	}

	/*genera un arreglo 2D separando la cadena cibida en espacios*/

	return (0);
}
