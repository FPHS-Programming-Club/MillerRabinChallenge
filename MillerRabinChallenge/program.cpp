#include <chrono>
#include <inttypes.h>
#include <io.h>
#include <iostream>
#include "miller_rabin.h"

// DO NOT EDIT THIS FILE!!!
// This file contains the testing scripts for the program.
// The file you should edit is "fibonacci.cpp"
using namespace std;
using namespace std::chrono;
typedef time_point<high_resolution_clock, nanoseconds> mr_time_point;

void put_result(int64_t number, bool result, double time);

void single_run(int64_t number);
void ranged_run(int64_t run_start, int64_t run_end);

int main(int argc, const char** argv)
{
    if (argc == 3)
    {
        int64_t min = strtoll(argv[1], nullptr, 10);
        int64_t max = strtoll(argv[2], nullptr, 10);
        ranged_run(min, max);
    }
    else if (argc == 2)
    {
        int64_t number = strtoll(argv[1], nullptr, 10);
        single_run(number);
    }
    else
    {
        const char* number_str = new char[64];
        int str_len = 64;
        int _;
        printf("Enter number to evaluate, or 'r' to specify a range of numbers.\n > ");
        _ = scanf_s("%s", number_str, str_len);
        if (number_str[0] == 'r' && number_str[1] == '\0')
        {
            int64_t min, max;
            printf("Min > ");
            _ = scanf_s("%lld", &min);
            printf("Max > ");
            _ = scanf_s("%lld", &max);
            ranged_run(min, max);
        }
        else single_run(strtoll(number_str, nullptr, 10));
        delete[] number_str;
    }

    return 0;
}

void single_run(int64_t number)
{
    // Evaluate a single number.
    printf("Evaluating...");

    mr_time_point start = high_resolution_clock::now(), end;
    bool prime = is_prime(number);
    end = high_resolution_clock::now();

    double time_sec = (end - start).count() * 1e-9;
    if (prime) printf(" \x1b[1;32mPRIME\x1b[0m %.6f sec.\n", time_sec);
    else printf(" \x1b[1;31mNOT PRIME\x1b[0m %.6f sec.\n", time_sec);

    put_result(number, prime, time_sec);
}

void ranged_run(int64_t run_start, int64_t run_end)
{
    // Evaluate a group of numbers, from `runStart` to `runEnd`.
    printf("Evaluating...\n");

    mr_time_point start, end;
    bool prime;
    double time_sec;
    for (int64_t num = run_start; num <= run_end; num++)
    {
        printf("%lld...", num);

        start = high_resolution_clock::now();
        prime = is_prime(num);
        end = high_resolution_clock::now();

        time_sec = (end - start).count() * 1e-9;
        if (prime) printf(" \x1b[1;32mPRIME\x1b[0m %.6f sec.\n", time_sec);
        else printf(" \x1b[1;31mNOT PRIME\x1b[0m %.6f sec.\n", time_sec);

        put_result(num, prime, time_sec);
    }
}

void put_result(int64_t number, bool result, double time)
{
    // Put a result in the debug file. Don't worry, this isn't included
    // when calculating the time.
    constexpr const char* FILE_PATH = "timings.csv";

    FILE** output = new FILE*();
    if (_access(FILE_PATH, 0) == 0)
    {
        fopen_s(output, FILE_PATH, "a");
        if (*output == nullptr) return;
        fprintf(*output, "%lld,%s,%f\n", number, result ? "true" : "false", time);
        fclose(*output);
    }
    else
    {
        fopen_s(output, FILE_PATH, "a");
        if (*output == nullptr) return;
        fprintf(*output, "Number,Result,Time\n%lld,%s,%f\n", number, result ? "true" : "false", time);
        fclose(*output);
    }
}
