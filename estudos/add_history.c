#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>


// 1. readline(): Esta função é utilizada para ler uma linha de entrada do usuário a partir do terminal. Ela aguarda até que o usuário insira uma linha de texto e pressione Enter, e em seguida, retorna essa linha como uma string.
// 2. add_history(const char *line): Adiciona uma linha ao histórico de comandos do GNU Readline. Isso permite que comandos anteriores possam ser acessados usando as teclas de seta para cima e para baixo quando interagindo com a linha de comando.
// 3. rl_clear_history(): Limpa o histórico de comandos mantido pelo GNU Readline. Isso remove todos os comandos do histórico, deixando-o vazio.
// 4. rl_on_new_line(): Informa ao GNU Readline que a linha atual foi finalizada e que o cursor deve ser movido para uma nova linha. Isso sinaliza o fim da linha atual e permite que o Readline inicie uma nova linha para a entrada do usuário.
// 5. rl_replace_line(const char *text, int clear_undo): Substitui a linha atual de entrada do usuário por uma nova linha especificada. Essa função é útil para modificar dinamicamente a linha de entrada, por exemplo, para implementar recursos de autocompletar ou fornecer feedback dinâmico.
// 6. rl_redisplay(): Atualiza a exibição da linha de entrada no terminal. Esta função é usada após qualquer modificação na linha de entrada para garantir que as alterações sejam refletidas imediatamente na tela do usuário.


int	main(void)
{
	// char	*str;

	// add_history("aaaaaaaa");
	// printf("teste");
	// rl_on_new_line();
	// rl_on_new_line();
	// rl_on_new_line();
	// sleep(3);
	// return (0);
}