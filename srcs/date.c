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
            break;
    }
    int is_special;
    int date_obj = get_date(value, &is_special);
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
            if (S_ISREG(st.st_mode) || 1) {

                stat(path, &st);
                time_t file_time = st.st_mtime;
                if (is_special == 0) {                    
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
                    
                    if(strcmp(value,"yesterday") != 0) {
                        switch (signe){
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

                    } else {
                        int date_obj2 = 0;
                        int sp;
                        switch (signe){
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
                           date_obj2 = get_date("today",&sp);
                            if (!(((difftime(curr_time,file_time)) <= date_obj && (difftime(curr_time,file_time)) > date_obj2 ))) {
                                    delete_path(pl, path);
                                    incr = 0;
                                }
                            break;
                        }

                    }

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
        return 2;
    }
}

int get_date(char * value, int * is_special){
    int size = 0;
    int mult = 1;
    int len = strlen(value);
    int i = 0;
    time_t curr_time = time(NULL);
    struct tm *tm = localtime(&curr_time);
    char str[2] = "\0";

    if (strcmp(value, "today") == 0) {
        tm->tm_sec = 0;
        tm->tm_hour = 0;
        tm->tm_min = 0;

        *is_special = 1;
        return difftime(curr_time, mktime(tm));

    } else if (strcmp(value, "yesterday") == 0) {
        tm->tm_sec = 0;
        tm->tm_hour = 0;
        tm->tm_min = 0;
        int d_per_mo[12] = {31,28 + (tm->tm_year % 4 == 0),31,30,31,30,31,31,30,31,30,31} ;
        if(tm->tm_mday > 1) {
            tm->tm_mday -= 1;
            tm->tm_yday -=1;
            tm->tm_wday = (tm->tm_wday -1) % 7;
            *is_special = 1;
            return difftime(curr_time, mktime(tm));
        }
        else if (tm->tm_mon >0) {
            tm->tm_mon -=1;
            tm->tm_yday -=1;
            tm->tm_wday = (tm->tm_wday -1) % 7;
            tm->tm_mday = d_per_mo[tm->tm_mon];
            *is_special = 1;
            return difftime(curr_time, mktime(tm));
        }
        else {
            tm->tm_mon = 0;
            tm->tm_yday = 0;
            tm->tm_wday = (tm->tm_wday -1) % 7;
            tm->tm_mday = 31;
            *is_special = 1;
            return difftime(curr_time, mktime(tm));
        }

    } else if (strcmp(value, "now") == 0) {
        int old_min = tm->tm_min;
        tm->tm_min = (old_min - 2 ) % 60;
        if (old_min < 2) {
            if (tm->tm_hour > 0) {
                tm->tm_hour -=1;
            }
            else {
                tm->tm_sec = 0;
                tm->tm_hour = 0;
                tm->tm_min = 0;
            }
        }
        *is_special = 1;
        return difftime(curr_time, mktime(tm));

    } else if (strcmp(value, "this month") == 0) {
        tm->tm_sec = 0;
        tm->tm_hour = 0;
        tm->tm_min = 0;
        int old_mday = tm->tm_mday;
        tm->tm_mday= 1;
        tm->tm_yday -= (old_mday-1) ;
        tm->tm_wday = (tm->tm_wday - old_mday +1) % 7;
        *is_special = 1;
        return difftime(curr_time, mktime(tm));
    } 
    *is_special = 0;
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
