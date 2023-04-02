#ifndef GRAPHCAIRO_MTR_H
#define GRAPHCAIRO_MTR_H

#include <stdbool.h>

bool gc_open(void);
void gc_close(void);
void gc_parsearg(char* arg);
void gc_redraw(void);

#endif
