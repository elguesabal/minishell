#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <term.h>

// isatty ttyname ttyslot tcgetattr tcsetattr ioctl tgetent tgetflag tgetnum tgetstr tgoto tputs



// int	main(void)
// {
// 	if (isatty(STDOUT_FILENO))
// 		printf("A saida padrao esta associada a um terminal\n");
// 	else
// 		printf("A saida padrao nao esta associada a um terminal.\n");

// 	return (0);
// }





// int	main(void)
// {
// 	char	*name;

// 	name = ttyname(STDOUT_FILENO);

// 	printf("nome: %s\n", name);

// 	return (0);
// }





// int	main(void)	// NAO ENTENDI A FINALIDADE DESTA FUNCAO
// {

// 	printf("%d\n", ttyslot());

// 	return (0);
// }





// int	main(void)	// NAO ENTENDI A FINALIDADE DESTA FUNCAO
// {
// 	struct termios	attr;

// 	tcgetattr(STDOUT_FILENO, &attr);

//	 printf("Atributos atuais do terminal:\n");
//	 printf("c_iflag: 0x%08x\n", attr.c_iflag);
//	 printf("c_oflag: 0x%08x\n", attr.c_oflag);
//	 printf("c_cflag: 0x%08x\n", attr.c_cflag);
//	 printf("c_lflag: 0x%08x\n", attr.c_lflag);

// 	return (0);
// }





// int	main(void)	// NAO ENTENDI A FINALIDADE DESTA FUNCAO // SAPOHA AKI FEZ MERDA NO MEU TERMINAL
// {
// 	struct termios	attr;

// 	tcgetattr(STDOUT_FILENO, &attr);

// 	// attr.c_lflag &= ~(ICANON | ECHO);	// DESATIVA O MODO CANONICO E A ECOAGEM

// 	// attr.c_lflag |= ICANON;	// ATIVA O MODO CANONICO
// 	// attr.c_lflag |= ECHO;	// ATIVA A ECOAGEM

// 	tcsetattr(STDOUT_FILENO, TCSANOW, &attr);

// 	return (0);
// }





// int	main(void)	// EXPLORAR MAIS ESSA FUNCAO DPS
// {
// 	struct winsize	ws;

// 	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

//	 printf("numero de linhas do terminal: %d\n", ws.ws_row);
//	 printf("numero de colunas do terminal: %d\n", ws.ws_col);

// 	printf("latgura da janela em pixels: %d\n", ws.ws_xpixel);
// 	printf("altura da janela em pixels: %d\n", ws.ws_ypixel);

// 	return (0);
// }





// int	main(void)
// {
// 	char	term_buffer[1024];

// 	tgetent(term_buffer, getenv("TERM"));	// COMPILAR COM A FLAG -lcurses

// 	printf("term: %s\n", term_buffer);

// 	return (0);
// }





// int	main(void)
// {
// 	char	term_buffer[1024];

// 	tgetent(term_buffer, getenv("TERM"));	// COMPILAR COM A FLAG -lcurses

// 	if (tgetflag("colors") == 1)
// 		printf("Este terminal suporta cores\n");
// 	else
// 		printf("Este terminal nao suporta cores\n");

// 	if (tgetflag("hs") == 1)
// 		printf("Este terminal suporta controle de cursor\n");
// 	else
// 		printf("Este terminal nao suporta controle de cursor\n");

// 	if (tgetflag("rv") == 1)
// 		printf("Este terminal suporta reversão de vídeo\n");
// 	else
// 		printf("Este terminal nao suporta reversão de vídeo\n");

// 	if (tgetflag("us") == 1)
// 		printf("Este terminal suporta sublinhado de texto\n");
// 	else
// 		printf("Este terminal nao suporta sublinhado de texto\n");

// 	if (tgetflag("mb") == 1)
// 		printf("Este terminal suporta texto piscante\n");
// 	else
// 		printf("Este terminal nao suporta texto piscante\n");

// 	if (tgetflag("vi") == 1)
// 		printf("Este terminal suporta ocultar o cursor\n");
// 	else
// 		printf("Este terminal nao suporta ocultar o cursor\n");

// 	return (0);
// }





// int	main(void)
// {
// 	int	num_cols;

// 	num_cols = tgetnum("cols");	// COMPILAR COM A FLAG -lcurses

// 	printf("numero de colunas do terminal: %d\n", num_cols);

// 	return (0);
// }





// int	main(void)
// {
// 	char	term_buffer[1024];

// 	tgetent(term_buffer, getenv("TERM"));	// COMPILAR COM A FLAG -lcurses

// 	printf("sequencia de escape para texto vermelho: %s\n", tgetstr("setaf", NULL));

// 	return (0);
// }





// int	main(int argc, char **argv)
// {
// 	char	term_buffer[1024];

// 	tgetent(term_buffer, getenv("TERM"));

// 	printf("sequencia de escape para mover o cursor para (10, 5): %s\n", tgoto(tgetstr("cm", NULL), atoi(argv[1]), atoi(argv[2])));

// 	return (0);
// }





int	main(void)
{
	char	*term_buffer;

	tgetent(term_buffer, getenv("TERM"));	// COMPILAR COM A FLAG -lcurses

	tputs(tgetstr("clear", NULL), 1, putchar);

	return (0);
}