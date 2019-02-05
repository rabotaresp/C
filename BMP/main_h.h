#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
#include <time.h>

//WORD — 16-битное беззнаковое целое
static unsigned short read_u16(FILE *fp)
{
    unsigned char b0, b1;
 
    b0 = getc(fp); // 1-st Byte
    b1 = getc(fp);
 
    return ((b1 *256) + b0);
}
 
//DWORD — 32-битное беззнаковое целое
static unsigned int read_u32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;
 
    b0 = getc(fp); // 1-st Byte
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);
 
    return ((((((b3 *256) + b2) *256) + b1) *256) + b0);
}
 
//LONG — 32-битное целое со знаком
static int read_s32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;
 
    b0 = getc(fp); // 1-st Byte
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);
 
    return ((int)(((((b3 *256) + b2) *256) + b1) *256) + b0);
}
 
//WORD — 16-битное беззнаковое целое 
static void write_u16(unsigned short input, FILE *fp)
{
    putc(input, fp);
    putc((input /256) % 256, fp);
}
//DWORD — 32-битное беззнаковое целое 
static void write_u32(unsigned int input, FILE *fp)
{
    putc(input, fp);
    putc((input /256) % 256, fp);
    putc((input /256/256) % 256, fp);
    putc((input /256/256/256) % 256, fp);
}
 
//LONG — 32-битное целое со знаком
static void write_s32(int input, FILE *fp)
{
    putc(input, fp);
    putc((input /256) % 256, fp);
    putc((input /256/256) % 256, fp);
    putc((input /256/256/256) % 256, fp);
}
#endif
