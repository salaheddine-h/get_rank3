#ifndef RIP_H
#define RIP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void  solve(char *str, int pos, int open , int to_remove, char *temp, int temp_pos);
void  print_solution(char *str);
int get_min_remove(char *str);

#endif


