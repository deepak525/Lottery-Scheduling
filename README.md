# Lottery-Scheduling
# Problem:
In the problem we have to assign one or more lottery tickets to each of the process.
A lottery ticket is chosen at random, and the process holding that ticket gets the CPU. The BTV
operating system implements lottery scheduling by holding a lottery 50 times each second, with
each lottery winner getting 20 milliseconds of CPU time (20 milliseconds × 50 = 1 second)

# Solution: 
According to the problem, first we allocate Burst time and Priority for each process.
One or more lottery ticket is assigned to each of the process. Assign more tickets to the higher
priority process. The probability of completion of process with more number of tickets increases.
Random ticket is generated and process having the ticket gets the CPU for the specified quantum
time. After the quantum time, the running process is preempted and another random ticket is
generated. Now the process with the ticket gets the CPU. This process will continue until all the
processes are completed.

# Main Concept:
Give more lottery ticket to the higher priority process.
