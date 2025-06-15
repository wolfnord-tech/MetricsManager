#include "timedata.h"
#include <chrono>
#include <corecrt.h>
#include <iomanip>
#include <sstream>
using namespace std;

const string& TimeData::capture_current_time() {
    auto now = chrono::system_clock::now();
    auto now_us = chrono::time_point_cast<chrono::microseconds>(now);

    time_t t = chrono::system_clock::to_time_t(now);

    tm tm{};

    #if defined(_WIN32) || defined(_WIN64)
        localtime_s(&tm, &t);
    #else
        localtime_r(&t, tm);
    #endif

    auto us = now_us.time_since_epoch().count() % 1'000'000;
    int millis = us / 1000;

    stringstream ss;
    ss << put_time(&tm, "%Y-%m-%d %H:%M:%S") << "." << setw(3) << setfill('0') << millis;

    formatted_time = ss.str();

    return formatted_time;
}

const string& TimeData::get_formatted_time() const {
    return formatted_time;
}