int where_is(char *str, char c, int *p) {
    int count = 0, i = 0;

    // iterate through the string until the end
    while (str[i] != 0) {
        // if the ascii value is the same as c, then add its index to the array
        if (str[i] == c) p[count++] = i;
        i++;
    }

    return count;
}
