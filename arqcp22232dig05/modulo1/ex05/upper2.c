void upper2(char *str) {
    int i = 0;
    while (str[i] != 0) {
        if ('a' <= *(str + i) && *(str + i) <= 'z') *(str + i) -= 'a' - 'A';
        i++;
    }
}
