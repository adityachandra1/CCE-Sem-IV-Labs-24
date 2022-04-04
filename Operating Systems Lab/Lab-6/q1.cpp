#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Q
{
    int q[1000];
    int front, rear;
public:
    Q( )
    {
        front = rear = -1;
    }

    bool isEmpty( )
    {
        if( front == rear)
            return true;
        return false;
    }

    void enQ( int element )
    {
        if( rear != 999)
            q[ ++rear ] = element;
    }

    int deQ()
    {
        if( ! isEmpty() )
            return q[ ++front ];
    }

};

void display( int arrival_time[ ], int burst_time[ ], int waiting_time[ ], int turn_around_time[ ], int number_of_processes )
{
    cout<<"\n\nProcess\tArrival time\tBurst time\tWaiting time\tTurn around time\n";

    float average_waiting_time = 0, average_turn_around_time = 0;

    for( int i = 1; i <= number_of_processes; i++ )
    {
        cout<<i<<"\t\t"<<arrival_time[ i ]<<"\t\t"<<burst_time[ i ]<<"\t\t"<<waiting_time[ i ]<<"\t\t"<<turn_around_time[ i ]<<endl;

        average_turn_around_time += turn_around_time[ i ];
        average_waiting_time += waiting_time[ i ];
    }

    cout<<"\n\nAverage waiting time: "<<( average_waiting_time / (float)(number_of_processes) )<<endl;
    cout<<"\nAverage turn around time: "<<( average_turn_around_time / (float)(number_of_processes) )<<endl;
}


void Selection_Sort( int arrival_time[ ], int burst_time[ ], int number_of_processes)
{
    for (int i = 1; i < number_of_processes; i++)
    {
        int smallest = i;
        for (int j = i + 1; j <= number_of_processes; j++)
        {
            if (arrival_time[j] < arrival_time[smallest])
                smallest = j;
        }

        // swap arrival time and burst time of smallest element with ith element

        int temp = arrival_time[i];
        arrival_time[i] = arrival_time[smallest];
        arrival_time[smallest] = temp;

        temp = burst_time[i];
        burst_time[i] = burst_time[smallest];
        burst_time[smallest] = temp;
    }
}

void RoundRobin( int arrival_time[ ], int burst_time[ ], int number_of_processes, int time_quantum )
{
    Q ready_queue;
    //created a dummy object to act as the ready queue

    int clock_time = 0;
    //physical clock

    int remaining_time[ number_of_processes + 1 ], waiting_time[ number_of_processes + 1 ], turn_around_time[ number_of_processes + 1 ];
    bool visited[ number_of_processes + 1 ];

    //initialize the arrays and also find the process number that arrives first
    int first_arrived_process = -1;

    for( int i = 1; i <= number_of_processes; i++ )
    {
        waiting_time[ i ] = turn_around_time[ i ] = 0;
        remaining_time [ i ] = burst_time[ i ];
        visited[ i ] = false;

        if( first_arrived_process == -1 || arrival_time[ i ] < arrival_time[ first_arrived_process ] )
            first_arrived_process = i;
    }

    //add the process that arrived first to the queue and mark it as visited
    ready_queue.enQ( first_arrived_process );
    visited[ first_arrived_process ] = true;

    //loop until ready queue is empty
    while( ! ready_queue.isEmpty() )
    {
        /*

        - In each iteration, remove a process from the ready queue,
        and run it till either the time quantum expires, or the
        process finishes it's remaining time.

        - Update the clock time accordingly.

        - Then add all the processes to the ready queue, that have arrived on
        or before the current clock time and have not been visited yet.

        - Also add the current running process, if it hasn't finished executing.

        */


        int running_process = ready_queue.deQ( );

        bool to_add_current_process = false;

        cout<<clock_time<<"\t"<<running_process<<"\t";

        if( remaining_time[ running_process ] > time_quantum )
        {
            remaining_time[ running_process ] -= time_quantum;

            clock_time += time_quantum;

            /*
              - Since this process has not finished executing,
              we have to add it to the ready queue.

              - We do so after we add the remaining processes,
                that arrived while the current process was running.

            */

            to_add_current_process = true;
        }

        else
        {
            clock_time += remaining_time[ running_process ];

            remaining_time[ running_process ] = 0;

            waiting_time[ running_process ] = clock_time - arrival_time[ running_process ] - burst_time[ running_process ];
            turn_around_time[ running_process ] = waiting_time[ running_process ] + burst_time[ running_process ];
        }

        cout<<clock_time<<"\t";

        for( int i = 1; i <= number_of_processes; i++ )
        {

            if( ( arrival_time[ i ] <= clock_time ) && ( visited[ i ] == false ) )
            {
                ready_queue.enQ( i );
                visited[ i ] = true;
            }
        }

        if( to_add_current_process ==  true )
            ready_queue.enQ( running_process );


    }

    //display the final result
    display( arrival_time, burst_time, waiting_time, turn_around_time, number_of_processes);
}
void function_for_rr()
{
     int number_of_processes = 6;

    cout<<"\nEnter the number of processes: ";
    cin>>number_of_processes;

    int time_quantum, arrival_time[ number_of_processes + 1 ], burst_time[ number_of_processes + 1 ];

    cout<<"\nEnter the details of each process:\n\n";

    for( int i = 1; i <= number_of_processes; i++ )
    {
        cout<<"Process P"<<i<<endl;

        cout<<"Enter the arrival time: ";
        cin>>arrival_time[ i ];

        cout<<"Enter the burst time: ";
        cin>>burst_time[ i ];
    }

    cout<<"Enter the time quantum: ";
    cin>>time_quantum;

    // Sort the processes according to their arrival times
    Selection_Sort(arrival_time, burst_time, number_of_processes);


    RoundRobin( arrival_time, burst_time, number_of_processes, time_quantum );
}
void function_for_prinon()
{
    int n;
    cout<<"\n Enter the number of processes\n";
    cin>>n;
           int queue[1000];
    cout<<"\n Start entering the process no. the arrival time and burst time and the priority of the processes\n";
    int process[n][5],wt[n]={0},bt[n]={0},ct[n]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>process[i][j];
        }
        process[i][4]=0;
    }
    int first=0;
    int pid;
    int time=0;
  int flag=0;
  int count=0;
    while(count<n)
    {
        int best=1000;
        for(int i=0;i<n;i++)
        {
            if(process[i][3]<best&&process[i][4]==0&&process[i][1]<=time)
            {
                //cout<<"Entered"<<"\n";
                best=process[i][3];
                pid=process[i][0];
            }
        }
        queue[first++]=pid;
        //cout<<"\n Exited"<<"\n";
        wt[pid-1]=time-process[pid-1][1];
        process[pid-1][4]=1;
        time=time+process[pid-1][2];
        count++;
        bt[pid-1]=process[pid-1][2];
        ct[pid-1]=time;
        /*for(int i=0;i<n;i++)
        {
            if(process[i][4]==1)
            {
                continue;
            }
            else
            {
                flag=1;
            }
            
        }
        if(flag==0)
        {
            break;
        }*/
    }
    cout<<"\n The processing queue\n";
    for(int i=0;i<first;i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<"\n";
    cout<<"\n Average Waiting Time\n";
    int x=0;

    for(int i=0;i<n;i++)
    {
      cout<<wt[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
      x=x+wt[i];
    }
    cout<<(float)x/n;

    cout<<"\n Average Turnaround Time\n";
    x=0;
    for(int i=0;i<n;i++)
    {
      cout<<wt[i]+bt[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        x=x+wt[i]+bt[i];
    }
    cout<<(float)x/n;
}
void function_for_SJFpre()
{
    int n;


    cout<<"Enter the number of processes: ";
    cin>>n;

    int p_id[n+1], a_t[n+1], b_t[n+1], w_t[n+1], ta_t[n+1];

    cout<<"Enter the arrival time and burst time of each process:\n";
    for(int i = 1 ; i <= n; i++ )
    {
        p_id[i] = i;
        cout<<"P"<<i<<":"<<endl;
        cout<<"Arrival time:";
        cin>>a_t[i];
        cout<<"Burst time:";
        cin>>b_t[i];
    }

    //selection_sort( n, p_id, a_t, b_t );

    int rem_time[n+1];
    for( int i=1; i <= n; i++)
        rem_time[i] = b_t[i];

    int clock_time = 0, completed_processes = 0, curr = 0, finish_time = 0, minn = INT_MAX;
    bool process_change = false;

    while(completed_processes != n)
    {

        for( int i = 1; i <= n; i++ )
        {
            if(( a_t[i] <= clock_time && rem_time[i] < minn && rem_time[i] > 0) )
            {

                process_change = true;
                minn = rem_time[i];
                curr = i;


            }
        }

        if( !process_change )
        {
            clock_time++;
            continue;
        }

        minn = --rem_time[curr];

        if( rem_time[curr] == 0 )
        {
            minn = INT_MAX;
            process_change = false;
            completed_processes++;
            finish_time = clock_time + 1;
            w_t[curr] = finish_time - a_t[curr] - b_t[curr];

            if( w_t[curr] < 0 )
                w_t[curr] = 0;

            ta_t[curr] = w_t[curr] + b_t[curr];
        }

        clock_time++;

    }

    int s = 0;
    cout<<"\n Average waiting time\n";
    for(int i = 1; i <= n; i++)
    {
        s += w_t[i];
        cout<<w_t[i]<<" ";

    }
    cout<<"\n"<<(float)s/n;
    s=0;
    cout<<"\n Average turnaround time\n";
    for(int i=1;i<=n;i++)
    {
        s+=w_t[i]+b_t[i];
        cout<<w_t[i]+b_t[i]<<" ";
    }
    cout<<"\n"<<(float)s/n<<"\n";
}

int main()
{
    int ch;
    cout<<"Welcome to the process scheduling\n";
    cout<<"1. SJF-Preemptive\n";
    cout<<"2. Round Robin\n";
    cout<<"3. Priority-Nonpreemptive\n";
    cin>>ch;
    switch(ch)
    {
        case 1: function_for_SJFpre();

          break;


          case 2: 
                    function_for_rr();

    break;

    case 3: function_for_prinon();
               break;
    default: cout<<"\n Wrong Input\n";
    }
    return 0;
}