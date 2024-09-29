int sort_without_reps(int *src, int n, int *dest) {
    int dest_len = 0;
    char duplicate;

    // copy elements to dest array without duplicates
    for (int i = 0; i < n; i++) {
        duplicate = 0;
        for (int j = 0; !duplicate && j < i; j++) {
            if (src[i] == dest[j]) duplicate = 1;
        }
        if (!duplicate) dest[dest_len++] = src[i];
    }

    // sort dest
    for (int i = 0; i < dest_len - 1; i++) {
        for (int j = i + 1; j < dest_len; j++) {
            if (dest[i] > dest[j]) {
                dest[j] += dest[i];
                dest[i] = dest[j] - dest[i];
                dest[j] -= dest[i];
            }
        }
    }

    // -6 4 3 7 3 1
    // -6 4 5 6

    return dest_len;
}
