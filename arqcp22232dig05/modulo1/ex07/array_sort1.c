void array_sort1(int *vec, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[i] > vec[j]) {
                vec[j] += vec[i];
                vec[i] = vec[j] - vec[i];
                vec[j] -= vec[i];
            }
        }
    }
}
