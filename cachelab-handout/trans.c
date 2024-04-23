/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int block_size=8;
    if (M == 32 && N == 32) {
        int i, j, ii;
        for (i = 0; i < N; i += block_size)
            for (j = 0; j < M; j += block_size)
                for (ii = i; ii < i + block_size && ii < N; ++ii) {
                    // unloop
                    int tmp0 = A[ii][j];
                    int tmp1 = A[ii][j+1];
                    int tmp2 = A[ii][j+2];
                    int tmp3 = A[ii][j+3];
                    int tmp4 = A[ii][j+4];
                    int tmp5 = A[ii][j+5];
                    int tmp6 = A[ii][j+6];
                    int tmp7 = A[ii][j+7];

                    B[j][ii] = tmp0;
                    B[j+1][ii] = tmp1;
                    B[j+2][ii] = tmp2;
                    B[j+3][ii] = tmp3;
                    B[j+4][ii] = tmp4;
                    B[j+5][ii] = tmp5;
                    B[j+6][ii] = tmp6;
                    B[j+7][ii] = tmp7;
                }
        return;
    }
    if (M == 64 && N == 64) {
        int i, j, ii, jj;
        for (i = 0; i < N; i += block_size)
            for (j = 0; j < M; j += block_size) {
                for (ii = i; ii < i + block_size/2 && ii < N; ++ii) {
                    // unloop
                    int tmp0 = A[ii][j];
                    int tmp1 = A[ii][j+1];
                    int tmp2 = A[ii][j+2];
                    int tmp3 = A[ii][j+3];

                    B[j][ii] = tmp0;
                    B[j+1][ii] = tmp1;
                    B[j+2][ii] = tmp2;
                    B[j+3][ii] = tmp3;
                }
                for (ii = i; ii < i + block_size/2 && ii < N; ++ii) {
                    // unloop
                    int tmp4 = A[ii][j+4];
                    int tmp5 = A[ii][j+5];
                    int tmp6 = A[ii][j+6];
                    int tmp7 = A[ii][j+7];

                    B[j][ii+4] = tmp4;
                    B[j+1][ii+4] = tmp5;
                    B[j+2][ii+4] = tmp6;
                    B[j+3][ii+4] = tmp7;
                }
                for (jj = j; jj < j + block_size/2 && jj < M; ++jj) {
                    // unloop
                    int tmp4 = B[jj][i+4];
                    int tmp5 = B[jj][i+5];
                    int tmp6 = B[jj][i+6];
                    int tmp7 = B[jj][i+7];

                    int tmp44 = A[i+4][jj];
                    int tmp55 = A[i+5][jj];
                    int tmp66 = A[i+6][jj];
                    int tmp77 = A[i+7][jj];

                    B[jj][i+4] = tmp44;
                    B[jj][i+5] = tmp55;
                    B[jj][i+6] = tmp66;
                    B[jj][i+7] = tmp77;

                    B[jj+4][i] = tmp4;
                    B[jj+4][i+1] = tmp5;
                    B[jj+4][i+2] = tmp6;
                    B[jj+4][i+3] = tmp7;
                }
                for (ii = i + block_size/2; ii < i + block_size && ii < N; ++ii) {
                    // unloop
                    int tmp4 = A[ii][j+4];
                    int tmp5 = A[ii][j+5];
                    int tmp6 = A[ii][j+6];
                    int tmp7 = A[ii][j+7];

                    B[j+4][ii] = tmp4;
                    B[j+5][ii] = tmp5;
                    B[j+6][ii] = tmp6;
                    B[j+7][ii] = tmp7;
                }
            }
        return;
    }
    if (M == 61 && N == 67) {
        block_size = 17;
    }
    int i, j, ii, jj;
        for (i = 0; i < N; i += block_size)
            for (j = 0; j < M; j += block_size)
                for (ii = i; ii < i + block_size && ii < N; ++ii)
                    for (jj=j; jj < j + block_size && jj < M; ++jj)
                        B[jj][ii] = A[ii][jj];
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

