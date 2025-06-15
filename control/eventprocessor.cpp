#include <iostream>
#include <future>
#include <vector>
#include <queue>
#include <mutex>
#include "eventprocessor.h"

using namespace std;

// Добавляем событие в очередь
void EventProcessor::AddEvent(function<void()> event) {
  lock_guard<mutex> lock(queue_mutex); // Блокировка мьютекса
  event_queue.push(event); // Безопасное добавление
} // Мьютекс автоматически освобождается здесь

// Обработка всех событий в очереди
void EventProcessor::ProcessEvents() {
  vector<future<void>> futures; // Контейнер для асинхронных задач

  {
    // Критическая секция
    lock_guard<mutex> lock(queue_mutex);

    // Извлекаем ВСЕ события из очереди
    while (!event_queue.empty()) {
      auto event = event_queue.front(); // Берем первое событие
      event_queue.pop();                // Удаляем из очереди

      // Запускаем в отдельном потоке
      futures.push_back(async(launch::async, event));
    }
  } // Мьютекс освобождается - очередь свободная для новых событий

  // Ожидаем завершения ВСЕХ запущенных задач
  for (auto &f : futures) {
    f.wait(); // Блокируем текущий поток до завершения
  }
}