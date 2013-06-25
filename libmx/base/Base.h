#ifndef _BASE_H_
#define _BASE_H_

#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <vector>
#include <map>

#define LIBMX_API

#define USING_MX_NAMESPACE  using namespace mx;
#define BEG_MX_NAMESPACE namespace mx{
#define END_MX_NAMESAPCE }

#define SAVE_DELETE(x)  {				\
							delete x;	\
							x = NULL;	\
						}

#define SAVE_FREE(x)	{				\
							free(x);	\
							x = NULL;	\
						}

#define MX_MIN(x,y) ((x) < (y) ? (x) : (y))
#define MX_MAX(x,y) ((x) > (y) ? (x) : (y))

#endif
