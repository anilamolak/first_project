#include <Arduino_FreeRTOS.h>

// Task function prototypes
void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);

void setup() {
  // Set pin modes
  pinMode(8, OUTPUT); // LED1
  pinMode(9, OUTPUT); // LED2

  // Create tasks
  xTaskCreate(TaskBlink1, "Blink 1", 128, NULL, 1, NULL);
  xTaskCreate(TaskBlink2, "Blink 2", 128, NULL, 1, NULL);
}

void loop() {
  // Empty – FreeRTOS takes control
}

// Task to blink LED1
void TaskBlink1(void *pvParameters) {
  while (1) {
    digitalWrite(8, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(8, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

// Task to blink LED2
void TaskBlink2(void *pvParameters) {
  while (1) {
    digitalWrite(9, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(9, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
