#include"../includes/date.h"
#include <sys/stat.h>
#include <ctype.h> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int get_file_by_date(char * value, path_list * pl){
//printf("Searching for file with size %s bytes.\n", value);
    int i = 0;
    int len = strlen(value);
    int signe = 0;
    time_t curr_time = time( &curr_time);

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
                return 1;
            }
            break;
    }
    
    int date_obj = get_date(value);
    //printf("Signe : %d\n",signe);
    if (date_obj == -1) {
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
                time_t file_time = st.st_mtime;
                switch (signe)
                {
                case 1 :
                    if (!((difftime(curr_time,file_time)) > date_obj)) {
                            delete_path(pl, path);
                            incr = 0;
                    }
                    break;

                case -1 :
                    if (!((difftime(curr_time,file_time)) <= date_obj)) {
                            delete_path(pl, path);
                            incr = 0;
                        }
                    break;
                
                default:
                    if (!((difftime(curr_time,file_time)) <= date_obj)) {
                            delete_path(pl, path);
                            incr = 0;
                        }
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

int get_date(char * value){
    int size = 0;
    int mult = 1;
    int len = strlen(value);
    int i = 0;

    char str[2] = "\0";

    switch (value[len-1])
    {
    case 's':
        break;
    case 'm':
        mult = 60;
        break;
    case 'h':
        mult = 3600;
        break;
    case 'j':
        mult = 3600*24;
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
