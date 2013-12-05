#include "para_callback.h"

void repeat_three_times(callback_t f, void *para)
{
    f(para);
    f(para);
    f(para);
}
