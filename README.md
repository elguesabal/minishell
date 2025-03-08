# Minishell

- [Sobre o Projeto](#sobre-o-projeto)
- [Funcionalidades Implementadas](#funcionalidades-implementadas)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Como Compilar e Executar](#como-compilar-e-executar)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Comandos Implementados](#comandos-implementados)
- [Autores](#autores)

## Sobre o Projeto

O **Minishell** é uma implementação simplificada do shell do Unix. O objetivo do projeto é entender melhor como funciona um interpretador de comandos, replicando algumas funcionalidades do Bash. Este projeto foi desenvolvido em dupla.

## Funcionalidades Implementadas

- Execução de comandos binários do sistema (como `ls`, `echo`, `cat`)
- Implementação de comandos built-in (`cd`, `pwd`, `export`, `unset`, `env`, `exit`)
- Manipulação de variáveis de ambiente
- Redirecionamento de entrada (`<`) e saída (`>`, `>>`)
- Suporte a pipes (`|`) para encadear comandos
- Tratamento de sinais (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`)
- Implementação de um prompt interativo

## Tecnologias Utilizadas

- **Linguagem:** C
- **Bibliotecas:** `stdio`, `stdlib`, `unistd`, `readline/readline`, `readline/history`, `fcntl`, `sys/wait`, `sys/stat`, `signal`
- **Sistema:** Unix/Linux

## Como Compilar e Executar

### Requisitos

- Sistema baseado em Unix (Linux ou macOS)
- `gcc` instalado
- `readline` instalada

### Compilando o Minishell

```sh
make
```

### Executando o Minishell

```sh
./minishell
```

![Image](https://github.com/user-attachments/assets/cd1ed05e-4729-44bd-9526-2f2679a890ce)

## Estrutura do Projeto

```
minishell/
├── argument_management # Diretório com funções de parsing
├── assistant           # Diretório com funções auxiliares
├── commands            # Diretório com os comandos built-in
├── Makefile            # Script de compilação
├── minishell.c         # Arquivo contendo função main
└── minishell.h         # Arquivo de cabeçalho
```

## Comandos Implementados

- `echo` - Exibe uma mensagem na saída padrão
- `cd` - Muda de diretório
- `pwd` - Exibe o diretório atual
- `export` - Define variáveis de ambiente
- `unset` - Remove variáveis de ambiente
- `env` - Lista as variáveis de ambiente
- `exit` - Sai do shell

## Autores

- [@José Antonio](https://github.com/elguesabal)
- [@Wellington Franco](https://github.com/wellFranco)
