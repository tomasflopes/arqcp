int count_words(char *str) {
    int count = (str[0] == ' ' || str[0] == '\0') ? 0 : 1;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0') count++;
        i++;
    }

    return count;
}
