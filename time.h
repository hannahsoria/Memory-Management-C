/**
 * 
 * Hannah Soria
 * time.h
 * 5/2/24
 * header file for timing properties
 * 
*/

#ifndef TIME_H
#define TIME_H
double time_sec();
#endif
#include <time.h>
#include <sys/time.h>

double time_sec(){
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

