/**
 * @file log.h
 * @author wlanxww (xueweiwujxw@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LOG_H
#define LOG_H

#include <string.h>
#include <stdio.h>
#include <time.h>

extern char *get_local_time();

#define __LOCAL_TIME__ \
    get_local_time()

#define __FILENAME__ \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define logf_info(fmt, ...) \
    fprintf(stderr, "[%s] [info ] %s: %s: " fmt, __LOCAL_TIME__, __FILENAME__, __func__, ##__VA_ARGS__)
    // printf("[%s] [info ] %s: %s: " fmt, __LOCAL_TIME__, __FILENAME__, __func__, ##__VA_ARGS__)

#define logf_err(fmt, ...) \
    fprintf(stderr, "[%s] [error] %s: %s: %d: " fmt, __LOCAL_TIME__, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
    // printf("[%s] [error] %s: %s: %d: " fmt, __LOCAL_TIME__, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)

#define logf_warn(fmt, ...) \
    fprintf(stderr, "[%s] [warn ] %s: %s: %d: " fmt, __LOCAL_TIME__, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
    // printf("[%s] [warn ] %s: %s: %d: " fmt, __LOCAL_TIME__, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
#ifdef DEBUG
#define logf_debug(fmt, ...) \
    fprintf(stderr, "[%s] [debug] %s: %s: %d: " fmt, __LOCAL_TIME__, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
    // printf("[%s] [debug] %s: %s: %d: " fmt, __LOCAL_TIME__, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
#else
#define logf_debug(fmt, ...)
#endif

#endif