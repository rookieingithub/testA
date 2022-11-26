// wordcnt.c -- 统计字符,单词和行
#include <stdio.h>
#include <ctype.h>      // 为isspace()提供函数原型
#include <stdbool.h>    // 为bool,true和false提供定义

#define STOP '|'

int main(int argc, char const *argv[])
{
    char c;
    char prev;
    long n_chars = 0L;
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;
    bool inword = false;

    printf("Enter text to analyzed(| to terminate): \n");
    prev = '\n';
    while ((c = getchar()) != STOP)
    {
        n_chars++;
        if (c == '\n')
        {
            n_lines++;
        }
        if (!isspace(c) && !inword)
        {
            inword = true;
            n_words++;
        }
        if (isspace(c) && inword)
        {
            inword = false;
        }
        prev = c;
    }
    
    if (prev != '\n')
    {
        p_lines = 1;
    }
    printf("characters = %ld, word = %d,lines = %d, ", n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);

    return 0;
}
