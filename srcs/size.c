#include"../includes/size.h"
#include <sys/stat.h>
#include <ctype.h> 

int get_file_by_size(char * value, path_list * pl) {
    //printf("Searching for file with size %s bytes.\n", value);
    int i = 0;
    int len = strlen(value);
    int signe = 0;
    if (len < 1) {
        return 1;
    }

    switch(value[0]) {

        case '+' :
            value++;
            signe = 1;
            break;
        case '-' :
            value++;
            signe = -1;
            break;
        default :
            if (!(isdigit(value[0]))) {
                printf("oh");
                return 1;
            }
            break;
    }
    
    int size = get_size(value);
    //printf("Signe : %d\n",signe);
    if (size == -1) {
        return 1;
    }
   
    
    while (i < pl->ptr) {
        int incr = 1;
        char * path = malloc(sizeof(char) * (strlen(pl->path_data[i])+1));
        strcpy(path,pl->path_data[i]);
        struct stat st;

        if (stat(path, &st) == 0) {
            if (S_ISREG(st.st_mode)) {

                stat(path, &st);
                off_t file_size = st.st_size;

                switch (signe)
                {
                case 0 :
                    if (!(size == file_size)) {
                            delete_path(pl, path);
                            incr = 0;
                        }
                    break;
                
                case 1 :
                    if (!(size < file_size)) {
                            delete_path(pl, path);
                            incr = 0;
                    }
                    break;

                case -1 :
                    if (!(size > file_size)) {
                            delete_path(pl, path);
                            incr = 0;
                        }
                    break;
                
                default:
                    return 1;
                    break;
                }

                
                }
            else {
                    delete_path(pl, path);
                    incr = 0;
            }
            
        }
        free(path);
        i+= incr;
    }
    if (pl->ptr > 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int get_size(char * value){
    int size = 0;
    int mult = 1;
    int len = strlen(value);
    int i = 0;

    char str[2] = "\0";

    switch (value[len-1])
    {
    case 'c':
        break;
    case 'k':
        mult = 1024;
        break;
    case 'M':
        mult = 1024*1024;
        break;
    case 'G':
        mult = 1024*1024*1024;
        break;
    
    default:
        if (!(isdigit(value[len-1]))) {
            return -1;
        }
        len += 1;
        break;
    }


    while(i<len-1) {
        if (isdigit(value[i])) {
            str[0] = value[i];
            int temp = atoi(str);
            for(int j = 0; j< (len-2)-i; j++) {
                temp *= 10;
            }
            size += temp;
        }
        else {
            return -1;
        }
        i++;
    }
    

    return size*mult;
}
