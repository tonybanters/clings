// Exercise 059: Temperature Converter - Practical Functions
//
// Convert between Fahrenheit and Celsius!
//
// Formulas:
//   C = (F - 32) * 5/9
//   F = C * 9/5 + 32
//
// Easy exercise with just 2 bugs!
//
// EXPECTED: 32°F = 0.0°C
// EXPECTED: 100°F = 37.8°C
// EXPECTED: 0°C = 32.0°F
// EXPECTED: 100°C = 212.0°F
// HINT: Fix integer division, formula order

#include <stdio.h>

float fahrenheit_to_celsius(float f) {
    // TODO: Fix this!
    return (f - 32) * 5 / 9;
}

float celsius_to_fahrenheit(float c) {
    return c * 9.0 / 5.0 + 32;
}

int main(void) {
    printf("32°F = %.1f°C\n", fahrenheit_to_celsius(32));
    printf("100°F = %.1f°C\n", fahrenheit_to_celsius(100));

    printf("0°C = %.1f°F\n", celsius_to_fahrenheit(0));
    // TODO: Fix this!
    printf("100°C = %.1f°F\n", celsius_to_fahrenheit(0));

    return 0;
}
