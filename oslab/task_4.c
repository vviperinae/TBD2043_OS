/*
Step 1: Inside the structure declare the variables.
Step 2: Declare the variable i,j as integer,totwtime and totttime is equal to zero. 
Step 3: Get the value of 'n' assign pid as I and get the value of p[i].btime.
Step 4: Assign p[0] wtime as zero and tot time as btime and inside the loop calculate wait time and turnaround time.
Step 5: Calculate total wait time and total turnaround time by dividing by total number of process.
Step 6: Print total wait time and total turnaround time. 
Step 7: Stop the program.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;    // Process ID
    int btime;  // Burst Time
    int wtime;  // Waiting Time
} sp;

int main() {
    int i, j, n;
    int tbm = 0, totwtime = 0, totttime = 0;
    sp *p, t;

    printf("\nSJF Scheduling (Non-Preemptive)\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory for n processes
    p = (sp*)malloc(n * sizeof(sp));

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
        p[i].wtime = 0;
    }

    // Sort processes by burst time (ascending)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].btime > p[j].btime) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }

    printf("\nProcess\tBurstTime\tWaitingTime\tTurnAroundTime\n");

    // Calculate waiting and turnaround times
    for (i = 0; i < n; i++) {
        p[i].wtime = tbm;           // waiting time = total burst time before
        tbm += p[i].btime;          // update total burst time
        int tat = p[i].wtime + p[i].btime;  // turnaround time = waiting + burst

        totwtime += p[i].wtime;
        totttime += tat;

        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime, tat);
    }

    printf("\nTotal Waiting Time: %d", totwtime);
    printf("\nAverage Waiting Time: %.2f", (float)totwtime / n);
    printf("\nTotal Turnaround Time: %d", totttime);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totttime / n);

    free(p);
    return 0;
}
