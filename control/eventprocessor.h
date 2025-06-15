#ifndef EVENTPROCESSOR_H
#define EVENTPROCESSOR_H

#include <functional>
#include <iostream>
#include <queue>
#include <mutex>
using namespace std;

class EventProcessor {
    private:
        queue<function<void()>> event_queue; // Очередь событий
        mutex queue_mutex; // Защита очереди от гонки данных
    public:
        // Добавляем событие в очередь
        void AddEvent(function<void()> event);

        // Обработка всех событий в очереди
        void ProcessEvents();
};

#endif