#include <stdlib.h>
#include <stdio.h>
#ifdef DEBUG
# define DEBUG_PRINT(text)  cout << text << endl;
#else
# define DEBUG_PRINT(text) do {} while (0)
#endif
