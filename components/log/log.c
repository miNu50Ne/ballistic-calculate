/**
 * @file log.c
 * @author miNu0Ne (miNu50Ne@qq.com)
 * @brief
 * @version 0.1
 * @date 2025-01-14
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <time.h>

// 用于记录日志的函数
void log_message(FILE* log_file, const char* message) {
    // 获取当前时间
    time_t rawtime;
    struct tm* timeinfo;
    char time_buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // 格式化时间
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    // 将时间戳和消息写入日志文件
    fprintf(log_file, "[%s] %s\n", time_buffer, message);
}

// 用于将数据写入 CSV 文件
void log_data(FILE* csv_file, double data[], int data_size) {
    for (int i = 0; i < data_size; i++) {
        if (i == data_size - 1) {
            // 最后一个数据项后面不加逗号
            fprintf(csv_file, "%.4f\n", data[i]);
        } else {
            fprintf(csv_file, "%.4f\t", data[i]);
        }
    }
}
