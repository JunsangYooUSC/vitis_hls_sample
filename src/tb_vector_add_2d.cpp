int main() {
    DTYPE A[ROWS][COLS];
    DTYPE B[ROWS][COLS];
    DTYPE C[ROWS][COLS];

    // Initialize arrays
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            A[i][j] = i + j;     // Example values
            B[i][j] = (i + 1) * (j + 1);
        }
    }

    // Call the vector_add_2d function
    vector_add_2d(A, B, C);

    // Print results
    std::cout << "Resultant Matrix C:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
