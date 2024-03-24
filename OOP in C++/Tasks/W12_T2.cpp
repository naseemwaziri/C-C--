#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Event structure
struct Event {
    string name;
    string type;
    int availableTickets;
    double ticketPrice;
};

// Ticket structure
struct Ticket {
    string eventName;
    int seatNumber;
    double price;
};

// Function to display a list of events
void displayEvents(const vector<Event>& events) {
    cout << "Available Events:" << endl;
    cout << setw(20) << "Event Name" << setw(15) << "Event Type" << setw(20) << "Available Tickets" << setw(15) << "Ticket Price" << endl;
    for (const auto& event : events) {
        cout << setw(20) << event.name << setw(15) << event.type << setw(20) << event.availableTickets << setw(15) << event.ticketPrice << endl;
    }
    cout << endl;
}

// Function to handle ticket purchase
void purchaseTicket(vector<Event>& events, vector<Ticket>& purchasedTickets) {
    string eventName;
    cout << "Enter the name of the event you want to attend: ";
    getline(cin, eventName);

    // Find the event
    auto it = find_if(events.begin(), events.end(), [eventName](const Event& e) {
    return e.name == eventName;
    });

    if (it != events.end() && it->availableTickets > 0) {
        // Event found, proceed with ticket purchase
        Ticket ticket;
        ticket.eventName = eventName;
        ticket.seatNumber = rand() % 100 + 1;  // Generate a random seat number for simplicity
        ticket.price = it->ticketPrice;

        // Update available tickets
        it->availableTickets--;

        // Add the purchased ticket to the list
        purchasedTickets.push_back(ticket);

        cout << "Ticket purchased successfully. Seat Number: " << ticket.seatNumber << ", Price: " << ticket.price << endl;
    } else {
        cout << "Event not found or no available tickets." << endl;
    }
}

int main() {
    vector<Event> events = {
        {"Concert A", "Concert", 100, 50.0},
        {"Sports Game B", "Sports", 200, 30.0},
        {"Theater Performance C", "Theater", 150, 40.0}
    };

    vector<Ticket> purchasedTickets;

    while (true) {
        cout << "1. Display Events" << endl;
        cout << "2. Purchase Ticket" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();  // Consume the newline character

        switch (choice) {
            case 1:
                displayEvents(events);
                break;
            case 2:
                purchaseTicket(events, purchasedTickets);
                break;
            case 3:
                cout << "Exiting the program. Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
