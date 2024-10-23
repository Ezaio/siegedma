#ifndef ESP_H
#define ESP_H

void renderESP();  // Function to render the ESP

void drawOutline(float x, float y, float width, float height, float color[3]);
void drawHealthBar(float x, float y, float width, float height, int currentHealth, int maxHealth, float color[3]);

#endif

