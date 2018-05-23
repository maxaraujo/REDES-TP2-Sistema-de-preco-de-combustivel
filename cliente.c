#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

/*
** REDES DE COMPUTADORE 2018/1 - Trabalho prático 2 
** Maximilliam Alex de Araujo
** Pratica com biblioteca socket utilizando protocolo UDP (IPv4 e  IPv6)
*/

/*
** Constantes
*/
#define LARGURA_BUFFER 100
#define NUM_DE_PARAMETROS 3
#define ENDERECO_VALIDO 1

/*
** Recebe como parâmetro <ip/nome> <porta>
** Exemplo: ./cliente ::1 9999
*/
void main(int argc, char *argv[])
{
	/*
	** Variáveis e estruturas de dados
	*/
	int sd, validador, porta;
	char servidor[NETDB_MAX_HOST_NAME_LENGTH];
	char buffer[LARGURA_BUFFER];
	struct in6_addr servidoraddr;
	struct addrinfo dicas, *res = NULL;

	/*
	** Loop para facilitar a limpeza de erros
	*/
	do
	{
		if(argc != NUM_DE_PARAMETROS)
		{
			printf("Digite todos os parâmetro. Ex.: ./cliente <ip/nome> <porta>!\n");
			return 0;
		};

		strcpy(servidor, argv[1]);
		porta = atoi(argv[2]);

		memset(&dicas, 0x00, sizeof(dicas));
		dicas.ai_flags = AI_NUMERICSERV;
		dicas.ai_family = AF_UNSPEC;
		dicas.ai_socktype = SOCK_DGRAM;

		/*
		** Preenchendo a estrutura do cabeçalho IPv4 ou IPv6
		*/
		validador = inet_pton(AF_INET, servidor, &servidoraddr);
		if(validador == ENDERECO_VALIDO)
		{
			dicas.ai_family = AF_INET;
			dicas.ai_flags |= AI_NUMERICHOST;
		}else{
			validador = inet_pton(AF_INET6, servidor, &servidoraddr);
			if(validador == ENDERECO_VALIDO){
				dicas.ai_family = AF_INET6;
				dicas.ai_flags |= AI_NUMERICHOST;
			};
		};
		/*
		** Se algo deu errado no preechimento, é suposto que o endereço é inválido
		*/
		validador = getaddrinfo(servidor, porta, &dicas, &res);
		if(validador != 0)
		{
			printf("Problema ao identificar o servidor. Erro: %s\n", gai_strerror(validador));
			if(validador == EAI_SYSTEM){
				perror("getaddrinfo() failed");			
			};
			return 0;
		};

		
	};
}

