// Copyright 2021 Nikitin Kirill
// Group: 3821B1PR2

/*
���������� ������.
����������� ��������� ���������, ���������� � ���������� ����������.
����������� ����� �������� ��� ��� � �����, ��� � ��� ����� ������������ ����.
�� ��������� ���� ��� � �� ������ ������� � ����� ����. ����� ���������
�������� ������������ �� ����� ������� ����� ���� � �������.
�������� ��� � ����, � ����� �������� ����������, ������� �� �� �����.
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int GenerateRandomNumber(int max, int min);
int** setMemory(int** matrix, int n, int m);
void printMatrix(int** matrix, int n, int m);
int** multMatrixOnNumber(int** matrix, int n, int m, int* value);
void fillArrayRandValues(int** matrix, int n, int m, int max, int min);
void freeMemory(int** matrix, int n, int m);
int** createMatrix(int** matrix, int n, int m, int max, int min, char name);
int** multTwoMatrix(int** matrix_A, int** matrix_B, int n, int k, int m);
int** additionTwoMatrix(int** matrix_A, int** matrix_B, int n, int m);
int** MatrixTransported(int** matrix, int m, int n);
int** multVectorOnNumber(int** matrix, int n, int m, int* value);
int** multTwoVectors(int** vector_A, int** vector_B, int n, int m);
void inputData(int* min, int* max);
void inputSizeMatrix(int* N, int* M, int* K);
void inputSizeVector(int* N, int* M);

int main() {
    int** matrix_A = NULL, ** matrix_B = NULL, ** result = NULL, ** vector_A = NULL, ** vector_B = NULL, ** vector_C = NULL;
    int N = 0, M = 0, K = 0, I = 0, J = 0;
    int max = 0, min = 0, value = 0;

    srand((unsigned)time(NULL));

    printf("Enter sizes of matrix ( A[N,M] B[M,K] ) : ");
    inputSizeMatrix(&N, &M, &K);
    printf("Enter minimum and maximum of numbers: ");
    inputData(&min, &max);
    printf("\n");

    matrix_A = createMatrix(matrix_A, N, M, max, min, 'A');
    printf("\n");
    matrix_B = createMatrix(matrix_B, M, K, max, min, 'B');
    value = GenerateRandomNumber(max, min);

    // ��������� ������� �� �����
    result = setMemory(result, N, M);
    result = multMatrixOnNumber(matrix_A, N, M, &value);
    printf("\nMatrix Ax%d =\n", value);
    printMatrix(result, N, M);
    freeMemory(result, N, M);

    // ���������������� �������
    result = setMemory(result, M, N);
    result = MatrixTransported(matrix_A, M, N);
    printf("\nMatrix AT =\n");
    printMatrix(result, M, N);
    freeMemory(result, M, N);

    // ��������� ���� ������
    result = setMemory(result, N, K);
    result = multTwoMatrix(matrix_A, matrix_B, N, K, M);
    printf("\nMatrix AxB =\n");
    printMatrix(result, N, K);
    freeMemory(result, N, K);

    // �������� ���� ������
    if (N == M && M == K) {
        result = setMemory(result, N, M);
        result = additionTwoMatrix(matrix_A, matrix_B, N, M);
        printf("\nMatrix A+B =\n");
        printMatrix(result, N, M);
        freeMemory(result, N, K);
    }
    else printf("\nInput different sizes of matrix, addition of matrixes is impossible\n");

    freeMemory(matrix_A, N, M);
    freeMemory(matrix_B, M, K);

    int elemQuantity;
    int vectorVariant = 0;
    printf("\nInput the number of the vector's elements : ");
    scanf_s("%d", &elemQuantity);
    if (elemQuantity > 0) {
        printf("\nChoose the vector : 1. Vector - bar\n\t\t    2. Vector - line\n\n");
        printf("Your choice is : ");
        scanf_s("%d", &vectorVariant);
        switch (vectorVariant) {
        case 1:
            N = elemQuantity;
            M = 1;
            vector_A = createMatrix(vector_A, N, M, max, min, 'A');
            printf("\n");
            M = elemQuantity;
            N = 1;
            vector_B = createMatrix(vector_B, N, M, max, min, 'B');
            printf("\n");
            I = elemQuantity;
            J = 1;
            vector_C = createMatrix(vector_C, I, J, max, min, 'C');
            break;
        case 2:
            M = elemQuantity;
            N = 1;
            vector_A = createMatrix(vector_A, N, M, max, min, 'A');
            printf("\n");
            N = elemQuantity;
            M = 1;
            vector_B = createMatrix(vector_B, N, M, max, min, 'B');
            printf("\n");
            J = elemQuantity;
            I = 1;
            vector_C = createMatrix(vector_C, I, J, max, min, 'C');
            break;
        default: 
            printf("You've entered the variant that doesn't exist.\n");
            break;
        }
    }
    else printf("Vector's elements must be > 0\n\n");
    
    // ��������� ������� �� �����
    value = GenerateRandomNumber(max, min);
    printf("\nVector A*%d = ", value);
    result = setMemory(result, M, N);
    result = multVectorOnNumber(vector_A, M, N, &value);
    printMatrix(result, M, N);
    freeMemory(result, M, N);

    if (vectorVariant == 1) {
        // ��������� ���� ��������
        result = setMemory(result, M, N);
        result = multTwoVectors(vector_A, vector_B, M, N);
        printf("\nVector AxB =\n");
        printMatrix(result, M, N);
        freeMemory(result, M, N);

        // �������� ��������
        result = setMemory(result, M, N);
        result = additionTwoMatrix(vector_A, vector_C, M, N);
        printf("\nMatrix A+B =\n");
        printMatrix(result, M, N);
        freeMemory(result, M, N);

        // �������� ���� ���������� ������
        freeMemory(vector_A, elemQuantity, 1);
        freeMemory(vector_B, 1, elemQuantity);
        freeMemory(vector_C, elemQuantity, 1);
    }
    else {
        // ��������� ���� ��������
        result = setMemory(result, N, M);
        result = multTwoVectors(vector_B, vector_A, N, M);
        printf("\nVector AxB =\n");
        printMatrix(result, N, M);
        freeMemory(result, N, M);

        // �������� ��������
        result = setMemory(result, M, N);
        result = additionTwoMatrix(vector_A, vector_C, M, N);
        printf("\nMatrix A+B =\n");
        printMatrix(result, M, N);
        freeMemory(result, M, N);

        // �������� ���� ���������� ������
        freeMemory(vector_A, 1, elemQuantity);
        freeMemory(vector_B, elemQuantity, 1);
        freeMemory(vector_C, 1, elemQuantity);
    }
    return 0;
}

/// <summary>
/// ��������� ���������� ����� �� ���������� ���������
/// </summary>
/// <param name="Max">- ������������ ���������� �������� �������</param>
/// <param name="Min">- ����������� ���������� �������� �������</param>
/// <returns>��������������� ��������� ��������</returns>
int GenerateRandomNumber(int max, int min) {
    int value = min + rand() % (max - min + 1);
    return value;
}

/// <summary>
/// ��������� ���������� ������� ������ 
/// </summary>
/// <param name="matrix">- �������</param>
/// <param name="n">- ���������� �����</param>
/// <param name="m">- ���������� ��������</param>
/// <returns>�������</returns>
int** setMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

/// <summary>
/// ��������� ���������� ������� ������ 
/// </summary>
/// <param name="matrix">- �������</param>
/// <param name="n">- ���������� �����</param>
/// <param name="m">- ����������� ��������</param>
void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/// <summary>
/// ��������� ������� �� �����
/// </summary>
/// <param name="matrix">- �������</param>
/// <param name="n">- ���������� �����</param>
/// <param name="m">- ��������� ��������</param>
/// <param name="value">- ����� (�����) �� ������� ���������� �������</param>
/// <returns>���������</returns>
int** multMatrixOnNumber(int** matrix, int n, int m, int* value) {
    int** res = NULL;
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * (*value);
        }
    }
    return res;
}

/// <summary>
/// ���������� ������� ���������� �������
/// </summary>
/// <param name="matrix">- �������</param>
/// <param name="n">- ���������� �����</param>
/// <param name="m">- ���������� ��������</param>
/// <param name="max">- ������������ ���������� �������� �������</param>
/// <param name="min">- ����������� ���������� �������� �������</param>
void fillArrayRandValues(int** matrix, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = GenerateRandomNumber(max, min);
        }
    }
}

/// <summary>
/// ������� ������
/// </summary>
void freeMemory(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

/// <summary>
/// �������� � ���������� �������
/// </summary>
/// <param name="matrix">- �������</param>
/// <param name="n">- ���������� �����</param>
/// <param name="m">- ���������� ��������</param>
/// <param name="max">- ������������ ���������� �������� �������</param>
/// <param name="min">- ����������� ���������� �������� �������</param>
/// <param name="name">- ������������ ������� (A ��� B)</param>
/// <returns>�������</returns>
int** createMatrix(int** matrix, int n, int m, int max, int min, char name) {
    matrix = setMemory(matrix, n, m);
    fillArrayRandValues(matrix, n, m, max, min);
    printf("Matrix %c =\n", name);
    printMatrix(matrix, n, m);
    return matrix;
}

/// <summary>
/// ��������� ���� ������
/// </summary>
/// <param name="matrix_A"></param>
/// <param name="matrix_B"></param>
/// <param name="n"></param>
/// <param name="k"></param>
/// <param name="m"></param>
/// <returns>���������</returns>
int** multTwoMatrix(int** matrix_A, int** matrix_B, int n, int k, int m) {
    int** res = NULL;
    res = setMemory(res, n, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = 0;
            for (int l = 0; l < m; l++) {
                res[i][j] += matrix_A[i][l] * matrix_B[l][j];
            }
        }
    }
    return res;
}

/// <summary>
/// �������� ���� ������
/// </summary>
/// <param name="matrix_A">- ������� A</param>
/// <param name="matrix_B">- ������� B</param>
/// <param name="n">- ���-�� �����</param>
/// <param name="m">- ���-�� ��������</param>
/// <returns>���������</returns>
int** additionTwoMatrix(int** matrix_A, int** matrix_B, int n, int m) {
    int** res = NULL;
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
    return res;
}

/// <summary>
/// ���������������� �������
/// </summary>
/// <param name="matrix"></param>
/// <param name="m">- ���-�� �����</param>
/// <param name="n">- ���-�� ��������</param>
/// <returns>����������������� �������</returns>
int** MatrixTransported(int** matrix, int m, int n) {
    int** res = NULL;
    res = setMemory(res, m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}

/// <summary>
/// ��������� ������� �� �����
/// </summary>
/// <param name="matrix">- ������</param>
/// <param name="n">- ���������� �����</param>
/// <param name="m">- ��������� ��������</param>
/// <param name="value">- ����� (�����) �� ������� ���������� ������</param>
/// <returns>���������</returns>
int** multVectorOnNumber(int** matrix, int n, int m, int* value) {
    int** res = NULL;
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * (*value);
        }
    }
    return res;
}

/// <summary>
/// ��������� ���� ��������
/// </summary>
/// <param name="matrix_A"></param>
/// <param name="matrix_B"></param>
/// <param name="n"></param>
/// <param name="k"></param>
/// <param name="m"></param>
/// <returns>���������</returns>
int** multTwoVectors(int** vector_A, int** vector_B, int n, int m) {
    int** res = NULL;
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = 0;
            for (int l = 0; l < m; l++) {
                res[i][j] += vector_A[i][l] * vector_B[l][j];
            }
        }
    }
    return res;
}

/// <summary>
/// ���� ������������ � ������������� �������� ��� ������ � ��������
/// </summary>
/// <param name="min">- ������������ ���������� ��������</param>
/// <param name="max">- ����������� ���������� ��������</param>
void inputData(int* min, int* max) {
    scanf_s("%d %d", min, max);
}

/// <summary>
/// ���� ������� �������
/// </summary>
void inputSizeMatrix(int* N, int* M, int* K) {
    scanf_s("%d %d %d", N, M, K);
}

/// <summary>
/// ���� ������� �������
/// </summary>
/// <param name="N"></param>
/// <param name="M"></param>
/// <param name="K"></param>
void inputSizeVector(int* N, int* M) {
    scanf_s("%d %d", N, M);
}