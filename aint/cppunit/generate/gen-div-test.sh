#!/bin/sh

    ./gen-rand-1.py \
    | awk -v dd=\" '{ \
          cmd="echo " dd $1 " / " $2 dd " | bc"; \
          printf("%s %s ", $1, $2); \
          system(cmd); \
      }' \
    | awk -v dd=\" '{ \
          printf("%-33s / %-30s == %s;\n", "aint(" dd $1 dd ")", "aint(" dd $2 dd ")", "aint(" dd $3 dd ")"); \
      }'
# eof
