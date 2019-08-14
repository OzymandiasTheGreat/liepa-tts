#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LithUSS.h"


int init(const char * data, const char * voice) {
	loadLUSS();
	return initLUSS(data, voice);
};


int synth(char * text, short * out, size_t outSize, int speed, int tone) {
	size_t evSize = 10000;
	event* ev = (event*)malloc(evSize * sizeof(event));
	for (int i = 0; i < outSize; i++) out[i] = 0;
	return synthesizeWholeText(text, out, (unsigned int*) &outSize, ev, (int*) &evSize, speed, tone);
}


int toWav(size_t count, short * buff, char * filename) {
	return raw2wav(count, filename, buff);
}

void unload() {
	unloadLUSS();
}
