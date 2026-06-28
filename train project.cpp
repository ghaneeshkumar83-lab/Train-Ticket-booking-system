#include <stdio.h>
#include <string.h>

#define MAX 50   // Maximum number of tickets

// Structure to store passenger details
struct Ticket {
    int id;
    char name[50];
    int age;
    char trainName[50];
    int seatNo;
};

struct Ticket tickets[MAX];
int count = 0;   // Number of tickets booked

// Function to book a ticket
void bookTicket() {
    if (count >= MAX) {
        printf("Booking full! No more tickets available.\n");
        return;
    }

    tickets[count].id = count + 1;
    printf("Enter passenger name: ");
    scanf("%s", tickets[count].name);
    printf("Enter age: ");
    scanf("%d", &tickets[count].age);
    printf("Enter train name: ");
    scanf("%s", tickets[count].trainName);
    tickets[count].seatNo = count + 1;

    printf("Ticket booked successfully! Ticket ID: %d, Seat No: %d\n",
           tickets[count].id, tickets[count].seatNo);
    count++;
}

// Function to cancel a ticket
void cancelTicket() {
    int id;
    printf("Enter Ticket ID to cancel: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < count; i++) {
        if (tickets[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Ticket ID not found!\n");
        return;
    }

    // Shift tickets to fill the gap
    for (int i = found; i < count - 1; i++) {
        tickets[i] = tickets[i + 1];
    }
    count--;

    printf("Ticket with ID %d cancelled successfully!\n", id);
}

// Function to display all booked tickets
void displayTickets() {
    if (count == 0) {
        printf("No tickets booked yet.\n");
        return;
    }

    printf("\n--- Booked Tickets ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Age: %d | Train: %s | Seat: %d\n",
               tickets[i].id, tickets[i].name, tickets[i].age,
               tickets[i].trainName, tickets[i].seatNo);
    }
    printf("----------------------\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nTrain Ticket Booking System\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Tickets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: displayTickets(); break;
            case 4: printf("Exiting... Thank you!\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

