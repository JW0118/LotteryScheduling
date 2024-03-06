# LotteryScheduling
Program that assigns processes lottery tickets and selects a random winner.

This program will use a lottery sorting algorithm to determin the next proccess to be executed. On compilation the user will be prompted to enter the number of processes. This is extra and I was just playing around with the code. When the user enters however many processes they would like to run the program will pass that into a for loop that initiates the processes and assigns them their PID/ticket values. The assignment was unclear on the ammount of tickets each process should have so I just went with 5 but this can easily be changed.

To assign the random ticket values I used the rand() function. Since rand() does not change on recompilation I included the #time<time.h> header along with srand(time(0)). This makes the rand() function dependent on the time and each time the program is compiled it will give different numbers.

For the range of numbers used I just went with 1-100. This will cause issues if the user wants to run alot of processes because there is a higher probability of duplicate tickets with more and more processes.

After the processes all have their ticket values the program will then call the printTickets() function which will go through each process and pass them to the printInfo() function. This function prints out the id of each process and the tickets that are assigned to them. This again was unnecessary but I used it to help with ensureing proper function of the program.

Next the program will select the lotory winner. Calling the selectLotoWinner() function this choses a random process to win. the program then prints out the lottery winners id and then finds the winning ticket from the winner.
