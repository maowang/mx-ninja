#include "hash.h"

unsigned int times33(const char *data, unsigned int size) {
	unsigned int hash = 0;
	while (size) {
		hash = 33 * hash + *data++;
		size--;
	}
	return hash;
}

unsigned int sdbm(const char *data, unsigned int size) {
	unsigned int hash = 0;
	while (size) {
		hash = *data++ + (hash << 6) + (hash << 16) - hash;
		size--;
	}
	return hash;
}
