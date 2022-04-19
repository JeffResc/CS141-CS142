#include <stdio.h>

/* My getfloat */
int getfloat(float *pn)
{
	/* Variables to store the character and sign (- or +) */
	int c, sign;
	/* Variable to store power */
	double pow;

	/* Skip whitespaces */
	while (isspace (c = getchar()))
		;

	/* Find if char is a number */
	if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.')
	{
		/* it's not a number */
		ungetc (c, stdin);
		return 0;
	}

	/* Original code from getint to get the sign */
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getchar();

	/* Get decimal of float */
	for (*pn = 0.0; isdigit(c); c = getchar())
		*pn = 10.0 * *pn + (c - '0');

	/* Get fraction of float */
	if (c == '.')
		c = getchar();
	for (pow = 1.0; isdigit(c); c = getchar())
	{
		*pn = 10.0 * *pn + (c - '0');
		pow *= 10.0;
	}

	/* Combine pn with the sign and power to get the finalized pn */
	*pn = sign * *pn / pow;

	/* If we have reached EOF then stop */
	if (c != EOF)
		ungetc (c, stdin);
	return c;
}

/* small driver to test getint, c thorpe, 1/25/21 */
int main()
{
	/* Create variables for our loop */
	int i, n;
	/* Create an array of floats to store the floats into */
	float array[100];

	/* Display a prompt to the user */
	printf("Enter floats followed by ctrl-D for the EOF character\n");

	/* Loop to collect the floats from the user */
	for (n = 0; n < 100 && getfloat(&array[n]) != EOF; n++)
		;

	/* Loop to display the floats back to ther user */
	printf("The numbers are:\n");
	for (i = 0; i < n; i++)
	{
		printf("%f\n", array[i]);
	}
}
