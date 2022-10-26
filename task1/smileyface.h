#ifndef SMILEYFACE_H
#define SMILEYFACE_H

#include <stdio.h>
#include <ctime>

enum class smileyface //possible errors
{
    nice,   //success
    opent = -1,  //open error
    readnt = -2, //read error
    stoopid = -3,   //memory error;
    iwanttodie = -4, //whatever else error

};
#endif