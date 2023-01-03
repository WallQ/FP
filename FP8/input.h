#ifndef INPUT_H
#define INPUT_H

#define INVALID_INPUT_MESSAGE "The entered value is invalid."

int getInt(int minValue, int maxValue, char *message);
float getFloat(float minValue, float maxValue, char *message);
double getDouble(double minValue, double maxValue, char *message);
char getChar(char *message);
void getString(char *string, unsigned int size, char *message);

#endif