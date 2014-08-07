#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>




#define BUFSIZE (256)
typedef struct CPU_TICK_T {
    unsigned int user_time;
    unsigned int sys_time;
    unsigned int nice_time;
    unsigned int idle_time;
    unsigned int wait_time;
    unsigned int irq_time;
    unsigned int softirq_time;
    unsigned int stl_time;
}CPU_TICK;

typedef struct CPU_OCCUPANCY{
    unsigned int cpu_time_total;
    CPU_TICK ticks; 
    float user_time_percentage;
    float sys_time_percentage;
    float idle_time_percentage;
}CPU_OCCUPANCY;

/*
typedef struct SYS_INFO_T {
    CPU_OCCUPANCY cpu_occupancy;

}SYS_INFO;
*/


int ae_cpu_occupancy_calcuate(CPU_OCCUPANCY *cpu_occupancy)
{
    unsigned int user_time =0;  
    unsigned int sys_time =0;  
    unsigned int cpu_total_time =0;

    user_time = cpu_occupancy->ticks.user_time + cpu_occupancy->ticks.nice_time;
    sys_time = cpu_occupancy->ticks.sys_time + cpu_occupancy->ticks.irq_time + cpu_occupancy->ticks.softirq_time;
    cpu_total_time = cpu_occupancy->cpu_time_total ;
        
    cpu_occupancy->user_time_percentage = ((float)user_time / cpu_total_time) * 100;
    cpu_occupancy->sys_time_percentage = ((float)sys_time / cpu_total_time) * 100;
    cpu_occupancy->idle_time_percentage = ((float)cpu_occupancy->ticks.idle_time/ cpu_total_time) * 100;

    /* printf("user time %d total time %d \n", user_time, cpu_total_time); */
    /* printf("1111percentage %f \n", cpu_occupancy->user_time_percentage); */
    return 0; 
}

unsigned int ae_cpu_total_time_get(CPU_TICK *ticks)
{
    FILE *file = NULL;
    char buf[BUFSIZE] = {0};
    unsigned int total_time = 0;
    char *s = NULL;

    file = fopen("/proc/stat", "r");
    if (file == NULL)
        printf("open /proc/stat file error \n");


    while(fgets(buf, sizeof(buf), file) != NULL) {
        s = strstr(buf, "cpu");
        if (s != NULL) {
            sscanf(buf, "%*s%u %u %u %u %u %u %u %u",\
                    &ticks->user_time,\
                    &ticks->sys_time,\
                    &ticks->nice_time,\
                    &ticks->idle_time,\
                    &ticks->wait_time,\
                    &ticks->irq_time,\
                    &ticks->softirq_time,\
                    &ticks->stl_time); 
            break;
        } else {
            continue;
        }
    }
    /*
    printf("%u %u %u %u %u %u %u %u \n",\
            ticks->user_time,\
            ticks->sys_time,\
            ticks->nice_time,\
            ticks->idle_time,\
            ticks->wait_time,\
            ticks->irq_time,\
            ticks->softirq_time,\
            ticks->stl_time); 
    */

    total_time = ticks->user_time
        + ticks->sys_time
        + ticks->nice_time
        + ticks->idle_time
        + ticks->wait_time
        + ticks->irq_time
        + ticks->softirq_time
        + ticks->stl_time;

    return total_time;

}

int ae_cpu_occupancy_get(CPU_OCCUPANCY* cpu_occupancy)
{
    cpu_occupancy->cpu_time_total =
        ae_cpu_total_time_get(&cpu_occupancy->ticks);
    ae_cpu_occupancy_calcuate(cpu_occupancy);
    printf("user percentage %f\n", cpu_occupancy->user_time_percentage);
    printf("sys percentage %f\n", cpu_occupancy->sys_time_percentage);
    printf("idle percentage %f\n\n", cpu_occupancy->idle_time_percentage);

    return 0;
}


int main(int argc, const char *argv[])
{
    CPU_OCCUPANCY cpu_occupancy;
    int iRet = -1;


    while(1) {
        iRet = ae_cpu_occupancy_get(&cpu_occupancy);
        if (iRet < 0)
            printf("aaa\n");
        sleep(3);
    }
    return 0;
}
