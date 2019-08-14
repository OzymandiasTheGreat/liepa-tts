#include <stdlib.h>


int init(const char * data, const char * voice);
int synth(char * text, short * out, size_t outSize, int speed, int tone);
int toWav(size_t count, short * buff, char * filename);
void unload();
