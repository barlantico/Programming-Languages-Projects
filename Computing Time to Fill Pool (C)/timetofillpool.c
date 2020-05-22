 /*
  *  Program #1b
  *  Input of 3 floating point numbers from the command line
  *  as dimensions of a pool and calculates time it takes
  *  to fill with water in minutes.
  *  CS320-1
  *  9-4-2019
  *  @author  Brian Arlantico cssc0443
  */
#include <stdio.h>
#include <stdlib.h>
 
const float inputRate = 20; /* input rate given in pdf */
 
float calcTime(float vol);
 
int main(int argc, char *argv[])  {
    
    float l,w,h;
    float vol;
    float timeToFill;
 
    if (argc != 4) { /* error detection */
        printf("Usage: p1b length width height\n");
        return 0;
    }
 
    printf("Program #1, cssc0443, Brian Arlantico\n");
 
    l = atof(argv[1]); /*casts inputs of string to floating point values. */
    w = atof(argv[2]);
    h = atof(argv[3]);
 
    vol = l * w * h;
    timeToFill = calcTime(vol);
    printf("\nTime to fill a swimming pool %f by %f by %f with water", l,w,h);
    printf("\ninput rate of %f gallons per minute is %f minutes.\n", inputRate, timeToFill);
    return 0;
}
 
/*
 * Performs various calculations in order to compute timeToFill.
 * @param: float vol
 * return type: float time.
 */
float calcTime(float vol) {
    float time;
    float gallons = 7.8;
    gallons = gallons * vol;
    time = gallons / inputRate;
 
    return time;
 
}

