


#include <stddef.h>
#include <stdio.h>
#include <string.h>

int parse_url( char *uri, char **host, char **path )
{
    char * pos;
    pos = strstr(uri,"//");
    if (!pos) {
        return -1;
    }
    *host = pos + 2;
    pos = strchr(*host,'/');
    if (!pos) {
        *path = NULL;
    }else {
        *pos = '\0';
        *path = pos + 1;
    }
    return 0;
}


int main() {
    char uri[] = "http://www.company.com/index.html";
    char * host,* path;
    printf("size : %d",sizeof(char));
    parse_url(uri,&host,&path);
    return 0;
}
