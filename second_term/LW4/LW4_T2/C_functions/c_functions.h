#include "../String/String.h"
#include "../Iterators/Iterator.h"
#include <iostream>

extern String& Strcpy(String& s1, const String& s2);

extern String& Strncpy(String& s1, String& s2, size_t n);
extern String& Strcat(String& s1, String& s2);

extern String& Strncat(String& s1, String& s2, size_t n);

extern int Strcmp(String& s1, String& s2);

extern int Strncmp(String& s1, String& s2, size_t n);
extern String&& Strtok(String& s1, String& s2) ;

extern int Memcmp(const void *s1, const void *s2, size_t n);
extern void *Memcpy(void *s1, const void *s2, size_t n);
extern void *Memmove(void *s1, const void *s2, size_t n);

extern void *Memset(void *s, int c, size_t n) ;

extern String&& Strerror(int errnum) ;

extern size_t Strlen(String& s);
