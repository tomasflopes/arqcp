int g_n;
int g_v[100];

int average(int n1, int n2) { return (n1 + n2) / 2; }

int average_array(int v[], int n) {
    if (n <= 0) return 0;
    long int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += v[i];
    }

    return sum / n;
}

int average_global_array() { return average_array(g_v, g_n); }
