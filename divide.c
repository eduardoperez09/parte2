int divide(int a, int b) {
    if (b == 0) {
        write(2, "Error: Division by zero\n", 25);
        return 0;
    }
    return a / b;
}
