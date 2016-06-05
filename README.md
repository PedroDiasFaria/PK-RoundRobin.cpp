# PK-RoundRobin.cpp
RoundRobin Scheduling in C++ - Politechnika Krakowska Project 

##1 - Description
This project consists on the implementation of the Round-robin algorithm, one of the most known process scheduling algorithms, on C++ language. <br/>
On this program, it can be observed a little Gantt chart on how the processes are scheduled, taking in account their Burst Time, Arrival Time and the Time Quantum of the scheduling. It also displays some statistics like the Average Waiting and TurnAround times, as well the respective times on each process chosen as input. <br/>

##2 - Interface
It is displayed a small and simple interface when executing the program. <br/>
Will be asked the inputs in the following order: <br/>
1. Number of processes to schedule; <br/>
2. Burst and Arrival time for each process; <br/>
3. Time Quantum for the scheduling. <br/>
<img src="https://github.com/PedroDiasFaria/PK-RoundRobin.cpp/blob/master/rrinterface1.png"/> <br/>

After the inputs, it will be displayed the Gantt chart and a small Statistics table: <br/>
<img src="https://github.com/PedroDiasFaria/PK-RoundRobin.cpp/blob/master/rrinterface2.png"/> <br/>
(Example used from https://pt.wikipedia.org/wiki/Round-robin) 
