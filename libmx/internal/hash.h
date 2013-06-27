#ifndef _HASH_C_H_
#define _HASH_C_H_

#ifdef __cplusplus
extern "C" {
#endif

unsigned int times33(const char *data, unsigned int size);

unsigned int sdbm(const char *data, unsigned int size);

#ifdef __cplusplus
	}
#endif

#endif
