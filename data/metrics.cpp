#include "metrics.h"
#include <string>

void Metrics::printMetrics() {
    cout << " \"" << from << "\" " << value; // _ "MetricName" double_value
}

string Metrics::getMetrics() {
    string value_x = to_string(value);
    size_t dotPos = value_x.find('.');
    if (dotPos != string::npos) {
        while (value_x.length() > dotPos + 1 && value_x.back() == '0')
            value_x.pop_back();

        if (value_x.back() == '.')
            value_x.pop_back();
    }
    return " \"" + from + "\" " + value_x; // Вывод: _ "MetricName" double_value
}

void Metrics::setMetrics(string from, float value) {
    this->from = from;
    this->value = value;
}

string Metrics::getFrom() {
    return from;
}

double Metrics::getValue() {
    return value;
}
