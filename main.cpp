//http://www.thecrazyprogrammer.com/2015/09/round-robin-scheduling-program-in-c.html
//        http://ducslectures.blogspot.com/p/write-program-to-implement-sjf_23.html

/*
 * Round-Robin Scheduling by Pedro Faria
 * Politechnika Krakowska im. Tadeusza Kościuszki
 * 1st Semester 2015/2016
 * Computer Science
 */

/*
 * Round-Robin Description:
 * https://en.wikipedia.org/wiki/Round-robin_scheduling
 */

#include<iostream>
#include<vector>
using namespace std;

class Process
{
public:
    int burst_time;
    int arrival_time;
    int turnAround_time;
    int waiting_time;
    int finish_time;
    int time_left;
    Process(int bt, int at);
};

Process::Process(int bt, int at) {
    burst_time = bt;
    arrival_time = at;
}


class RoundRobin
{
public:
    int nr_proc;
    int totalTurnAroundTime;
    int totalWaitTime;
    int totalProcessTime;
    int remain_processes;
    int flag = 0 ;
    vector<Process> processes;
    void inputData();
    void initRR();
    void displayTime();
    void computeRR();
};



void RoundRobin::inputData()
{
    cout<<"Enter number of processes\n";
    cin>>nr_proc;
    remain_processes = nr_proc;

    cout<<"Enter the Burst and Arrival times in order :\n";
    for(int i=0;i<nr_proc;i++){
        int bt, at;
        cout<<"Burst Time for P(" << i+1 <<"): ";
        cin>>bt;
        cout<<"Arrival Time for P(" << i+1 <<"): ";
        cin>>at;
        processes.push_back(Process(bt, at));
    }
}

void RoundRobin::initRR()
{
    totalProcessTime=0;
    totalWaitTime=0;
    totalTurnAroundTime=0;
    for(int i=0; i<nr_proc; i++)
    {
        processes[i].time_left=processes[i].burst_time;
        processes[i].finish_time=0;
        processes[i].waiting_time = 0;
        processes[i].turnAround_time = 0;
        totalProcessTime+=processes[i].burst_time;
    }
}

void RoundRobin::displayTime()
{

    cout<<"\n\nProcess\t|TurnAround Time|Waiting Time\n";
    cout<<"--------+---------------+-------------\n";
    for(int i=0;i<nr_proc;i++)
    {

        totalWaitTime+= processes[i].waiting_time;
        processes[i].turnAround_time= processes[i].waiting_time+processes[i].burst_time;
        totalTurnAroundTime+=processes[i].turnAround_time;
        cout<<"P("<< i+1 <<")\t|\t"<< processes[i].turnAround_time <<"\t|\t"<<  processes[i].waiting_time <<"\n";

    }
    cout<<"--------------------------------------\n\n";

    cout<<"Avg Waiting time = "<<(double)totalWaitTime/nr_proc<<endl;
    cout<<"Avg Turnaround time = "<<(double)totalTurnAroundTime/nr_proc<<endl;
    cout<<"Round Robin scheduling complete\n";
}

void RoundRobin::computeRR(){

    inputData();
    initRR();
    int currentTime;
    int i, j;
    int time_quantum;
    int dec = 0;
    cout<<"Enter the time quantum:\n";
    cin>>time_quantum;

    cout<<"\n--------------------------------------\n";
    cout<<"Gantt Chart\n ";
    cout<<"--------------------------------------\n";

    for(currentTime=0;currentTime<totalProcessTime;)
    {
        for(i=0;i<nr_proc;i++)
        {
            if(processes[i].arrival_time<=currentTime && processes[i].finish_time==0)
            {

                cout<<"("<<currentTime<<")|==P"<<(i+1)<<"==|";
                if(processes[i].time_left<time_quantum){
                    dec=processes[i].time_left;
                }
                else {
                    dec=time_quantum;
                }

                processes[i].time_left=processes[i].time_left-dec;

                if(processes[i].time_left==0)
                    processes[i].finish_time=1;

                for(j=0;j<nr_proc;j++)
                    if(j!=i && processes[j].finish_time==0 && processes[i].arrival_time<=currentTime)
                        processes[i].waiting_time+=dec;

                currentTime=currentTime+dec;

            }

        }

    }

    cout<<"("<<totalProcessTime<<")"<<endl;
    displayTime();
}

void rr2(){
    int count,j,n,time,remain,flag=0,time_quantum;
    int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
    printf("Enter Total Process:\t ");
    scanf("%d",&n);
    remain=n;
    for(count=0;count<n;count++)
    {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
        scanf("%d",&at[count]);
        scanf("%d",&bt[count]);
        rt[count]=bt[count];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d",&time_quantum);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(time=0,count=0;remain!=0;)
    {
        if(rt[count]<=time_quantum && rt[count]>0)
        {
            time+=rt[count];
            rt[count]=0;
            flag=1;
        }
        else if(rt[count]>0)
        {
            rt[count]-=time_quantum;
            time+=time_quantum;
        }
        if(rt[count]==0 && flag==1)
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
            wait_time+=time-at[count]-bt[count];
            turnaround_time+=time-at[count];
            flag=0;
        }
        if(count==n-1)
            count=0;
        else if(at[count+1]<=time)
            count++;
        else
            count=0;
    }
    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
}

int main()
{
    RoundRobin rr;
    rr.computeRR();

    rr2();
}