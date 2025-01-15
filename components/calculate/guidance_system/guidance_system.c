/**
 * @file guidance_system.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-01-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <math.h>
#include <stdio.h>

// 定义系统矩阵和动力学系数（部分示例）
#define N 6 // 假设是一个6阶系统

// 这里假设系数存储在一个矩阵中，真实应用中可以从外部输入
double a[3][6] = {
    {    0.0012,       0,    -9.8017, -13.5167,  -1.6543,     0.0012},
    {   -0.0015, -5.5997,          0,  -26.593, -20.3008, 0.00055769},
    {5.0878e-07,       0, 0.00036316,   0.1976,   0.0211,    1.4e-06},
};

double a_24_ = 0, a_25_ = 0;

// 计算特征值（近似方法）
void compute_eigenvalues(double matrix[N][N]) {
    // 在实际应用中，这里可以用数值方法（如Jacobi方法、QR分解等）求解特征值
    // 由于没有库支持，我们这里简单输出一个示例
    double eigenvalues[N] = {0}; // 存储特征值
    // 示例值
    eigenvalues[0] = -0.1;
    eigenvalues[1] = -0.05;
    eigenvalues[2] = -0.02;
    eigenvalues[3] = 0.01; // 不稳定
    eigenvalues[4] = -0.03;
    eigenvalues[5] = -0.07;

    // 输出特征值
    printf("特征值：\n");
    for (int i = 0; i < N; i++) {
        printf("lambda[%d] = %.4f\n", i, eigenvalues[i]);
    }

    // 稳定性分析
    int stable = 1;
    for (int i = 0; i < N; i++) {
        if (eigenvalues[i] > 0) {
            stable = 0;
            break;
        }
    }

    if (stable) {
        printf("系统是稳定的。\n");
    } else {
        printf("系统是不稳定的。\n");
    }
}

int main() {
    compute_eigenvalues(a);

    return 0;
}
