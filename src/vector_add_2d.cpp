#include <ap_int.h>
#include <ap_fixed.h>
#include <hls_stream.h>
#include <iostream>

#define ROWS 4   // Number of rows
#define COLS 4   // Number of columns

typedef int DTYPE; // Define data type for array elements

void vector_add_2d(DTYPE A[ROWS][COLS], DTYPE B[ROWS][COLS], DTYPE C[ROWS][COLS]) {
#pragma HLS INTERFACE s_axilite port=return bundle=control
#pragma HLS INTERFACE m_axi depth=16 port=A bundle=gmem
#pragma HLS INTERFACE m_axi depth=16 port=B bundle=gmem
#pragma HLS INTERFACE m_axi depth=16 port=C bundle=gmem

    // Process rows
    for (int i = 0; i < ROWS; i++) {
#pragma HLS PIPELINE II=1 // Pipeline the row processing
        for (int j = 0; j < COLS; j++) {
#pragma HLS UNROLL factor=2 // Partially unroll the inner loop
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
