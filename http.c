#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include<unistd.h>


#define MAX_GET_SIZE 255
#define MAX_BUF_SIZE 255
#define HTTP_PORT 80
#define CRLF "\r\n"
/**
 * Parse the url and assign the host to the host pointer
 * and the path to the path pointer.
 * @param uri the complete URI
 * @param host the host buffer
 * @param path the path buffer
 */
int parse_url( char *uri, char **host, char **path )
{
    char * pos_it = strstr(uri,"//");
    if (pos_it == NULL) return -1;
    *host = pos_it + (sizeof(char) * 2);
    pos_it = strchr(*host,'/');
    if (pos_it == NULL) {
        *path = NULL;
    }else {
        *pos_it = '\0';
        *path = pos_it + sizeof(char);
    }
    return 0;
}

int http_get(int fd_conn,const char * host, const char * path) {
    static char command[MAX_GET_SIZE];
    sprintf(command,"GET /%s HTTP/1.1\r\n",path);
    if ((send(fd_conn,command,strlen(command),0)) == -1) {
        printf("errno :%d",errno);
    }
    sprintf(command, "Host: %s\r\n",host);
    if (send(fd_conn,command,strlen(command),0) == -1) return -1;

    sprintf(command,"Connection: close\r\n\r\n");
    if (send(fd_conn,command, strlen(command),0) == -1) return -1;

    return 0;
}

void display_result(int fd_conn) {
    int received = 0;
    static char recv_buff[MAX_BUF_SIZE + 1] = {0};
    while ((received = recv(fd_conn, recv_buff, MAX_BUF_SIZE, 0)) > 0) {
        recv_buff[received] = '\0';
        printf("%s",recv_buff);
    }

    printf("\n");
}

int main() {
    char uri[] = "http://httpforever.com/";
    char * host,* path;
    parse_url(uri,&host,&path);

    char * proxy_host, *proxy_user, *proxy_pass;
    int proxy_port, ind;
    struct hostent * server_info = gethostbyname(host);
    struct sockaddr_in host_address;
    host_address.sin_family = AF_INET;
    host_address.sin_port = htons(HTTP_PORT);

    memcpy(&host_address.sin_addr,server_info->h_addr_list[0],sizeof(struct in_addr)) ;
    if (server_info == NULL) return -1;

    int conn_fd = socket(PF_INET,SOCK_STREAM,0);
    connect(conn_fd,( struct sockaddr*) &host_address,sizeof(host_address));
    if (!conn_fd) return EXIT_FAILURE;

    http_get(conn_fd,host,path);
    display_result(conn_fd);
    printf("HTML printing closed");

    return 0;
}
