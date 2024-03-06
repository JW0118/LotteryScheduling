//Joshua Wells
//P676W568
//Programing assignment 2
//6Mar24

#include <iostream>
#include <vector>
#include <time.h>


class Process {
private:
	int id;
	std::vector<int> tickets;

public:
	Process(int pid) {
		id = pid;
		//creating 5 tickets for process (duplicates are possible which in real applications would cause issues)
		for (int i = 0; i < 5; ++i) {
			tickets.push_back(rand() % 100 + 1);
		}
	}
	//function to return the process id
	int getId() const {
		return id;
	}

	//function to print the ticket values out
	void printInfo() const {
		std::cout << "\nPID:\t" << id << ":\t Tickets: ";
		for (int i = 0; i < tickets.size(); i++) {
			std::cout << tickets[i];
			if (i != tickets.size() + 1) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	//function that selects winning ticket
	int getWinningTicket() const {
		int winningTicket = rand() % tickets.size();
		return tickets[winningTicket];
	}
};

class Scheduler {
private:
	std::vector<Process> processes;

public:
	void addProcess(const Process& process) {
		processes.push_back(process);
	}
	//function to go through each process and send them to printInfos()
	void printTickets() {
		for (auto& process : processes) {
			process.printInfo();
		}
	}
	//function that selects winner
	Process selectLotoWinner() const {
		return processes[rand() % processes.size()];
	}
};

int main() {
	int numProcesses;
	//asks user for number of processes in the system
	std::cout << "Enter the number of processes: ";
	std::cin >> numProcesses;

	Scheduler scheduler;

	//used this because i was getting the same values each time i ran the program
	srand(time(0));

	//For loop to create processes based on user input
	for (int i = 1; i <= numProcesses; ++i) {
		scheduler.addProcess(Process(i));
	}


	//printing out ticket values
	std::cout << "\nTickets for each process:" << std::endl;
	scheduler.printTickets();

	// selecting winner
	Process LotoWinner = scheduler.selectLotoWinner();

	//prints the winner and the winning ticket
	std::cout << "\nProces " << LotoWinner.getId() << " Wins the lottery with ticket: " << LotoWinner.getWinningTicket() << std::endl;
}
