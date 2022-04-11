#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int queue[100], q_front = 0, q_end = 0;
int RR()
{
    int n, quant;
    int queue[100], q_front = 0, q_end = 0;
    printf("Enter no of processes: ");
    scanf("%d", &n);
    printf("\nEnter time quantum: ");
    scanf("%d", &quant);
    int at[n], bt[n], bt_comp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ct[n], tat[n], wt[n];
    char p[n][3];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter arrival time and burst time:");
        scanf("%d %d", &at[i], &bt[i]);
        strcpy(p[i], "\n");
        p[i][0] = 'P';
        p[i][1] = i + '1';
        p[i][2] = '\0';
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                char tmp[] = "\0";
                strcpy(tmp, p[j]);
                strcpy(p[j], p[j + 1]);
                strcpy(p[j + 1], tmp);
            }
        }
    }

    int cpu_timer = 0;
    int count_comp = 0;
    fflush(stdout);
    printf("\n\nGantt Chart :- ");
    fflush(stdout);
    while (1)
    {
        for (int i = 0; i < n; i++)
            if (at[i] == cpu_timer)
                queue[q_end++] = i;

        if (q_end != q_front)
        {
            if ((bt_comp[queue[q_front]] % quant == 0 && bt_comp[queue[q_front]] != 0) && bt_comp[queue[q_front]] != bt[queue[q_front]])
            {
                ct[queue[q_front]] = cpu_timer;
                fflush(stdout);
                printf("%d %s %d\t", cpu_timer - quant, p[queue[q_front]], ct[queue[q_front]]);
                fflush(stdout);
                queue[q_end++] = queue[q_front];
                q_front++;
            }
            if (bt_comp[queue[q_front]] == bt[queue[q_front]])
            {
                fflush(stdout);
                printf("%d %s %d\t", ct[queue[q_end - 1]], p[queue[q_front]], cpu_timer);
                fflush(stdout);
                ct[queue[q_front]] = cpu_timer;
                q_front++;
                count_comp++;
                if (count_comp == n)
                    goto abc;
            }
            bt_comp[queue[q_front]]++;
        }
        if (count_comp == n)
            break;
        cpu_timer++;
    }
