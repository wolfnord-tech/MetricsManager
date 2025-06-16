#ifndef TIMEDATA_H
#define TIMEDATA_H
#include <iostream>
using namespace std;

// Класс TimeData отвечает за объекты каждой метрики
class TimeData {
    private:
        string formatted_time; // Поле для хранения отформатированного времени
    public:
        TimeData() {
            formatted_time = "null";
        }

        const string& capture_current_time();

        const string& get_formatted_time() const;
};

#endif
