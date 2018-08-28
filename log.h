#include <errno.h>

extern enum verbosity_level
{
	V_ERR = 0,
	V_WARN,
	V_INFO,
	V_DBG
} verbosity;


#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x
#ifdef DEBUG
#define DBG(fmt, ...) LOG(V_DBG, "[DEBG] " fmt, ##__VA_ARGS__)
#define LOG_PREFIX "[" __FILE__ ":" STRINGIFY(__LINE__) "] "
#else
#define DBG(fmt, ...)
#define LOG_PREFIX ""
#endif

#define DBGPTR(p) DBG("%s=%p", #p, (void *)p)

#define LOG(verb, fmt, ...) do{if(verbosity>=verb){printf(LOG_PREFIX fmt "\n", ##__VA_ARGS__);}}while(0)
#define INFO(fmt, ...) LOG(V_INFO, "[INFO] " fmt, ##__VA_ARGS__)
#define WARN(fmt, ...) LOG(V_WARN, "[WARN] " fmt, ##__VA_ARGS__)
#define ERR(fmt, ...) LOG(V_ERR, "[ERR ] " fmt, ##__VA_ARGS__)

#define PERROR(str) ERR("%s: %s", str, strerror(errno));
#define CHECK(x) ({\
long _tmp = (x);\
DBG("%s = %lu", #x, _tmp);\
_tmp;})
