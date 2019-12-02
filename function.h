#pragma once

void setColor(int Bg, int Tex);
void cls(int time = 0);
int charToInt(char* arr);
void elementDelete(user*& arr, size_t size, size_t exclude);
void arReload(user*& arr, size_t size, size_t new_size);
void paintLine(char ch, int size);