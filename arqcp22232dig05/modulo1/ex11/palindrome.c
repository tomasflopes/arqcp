int is_valid_char(char c) {
    return ('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') ||
           ('a' <= c && c <= 'z');
}

int is_capital_letter(char c) { return 'A' <= c && c <= 'Z'; }

int palindrome(char *str) {
    short length = 0, valid_count = 0;
    while (str[length] != 0) {
        if (is_valid_char(str[length])) valid_count++;
        length++;
    }

    if (valid_count == 0) return 0;

    int left = 0;
    int right = length - 1;

    do {
        while (!is_valid_char(str[left])) left++;
        while (!is_valid_char(str[right])) right--;

        char c_left =
            is_capital_letter(str[left]) ? str[left] + 'a' - 'A' : str[left];
        char c_right =
            is_capital_letter(str[right]) ? str[right] + 'a' - 'A' : str[right];

        if (left < right) {
            if (c_left != c_right) return 0;
            left++;
            right--;
        }
    } while (left < right);

    return 1;
}
