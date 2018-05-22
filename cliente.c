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

/*
** Recebe como parâmetro <ip/nome> <porta>
** Exemplo: ./cliente ::1 9999
*/
void main(int argc, char *argv[])
{
	/*
	** Variáveis e estruturas de dados
	*/
	int sd, rc;
	char servidor[NETDB_MAX_HOST_NAME_LENGTH];
	char buffer[LARGURA_BUFFER];
	struct sockaddr_in6 servidoraddr;
	int lservidoraddr = sizeof(servidoraddr);
	struct addrinfo hints, *res;

	/*
	** Loop para facilitar a limpeza de erros
	*/
	do
	{
		
	};
}

