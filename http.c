#include <stdio.h>
#include <string.h>

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


int main() {
    char uri[] = "http://www.mysite.com/path";
    char * host,* path;
    parse_url(uri,&host,&path);

    printf("HOST : %s \nPATH: %s \n",host,path);
    return 0;
}
