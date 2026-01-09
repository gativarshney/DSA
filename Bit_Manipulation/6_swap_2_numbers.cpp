pair<int, int> get(int a, int b) {
    pair<int, int> p;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
}

// Without using any third variable