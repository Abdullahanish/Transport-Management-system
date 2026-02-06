#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// ===== Structures =====
struct Transport {
    int transportID;
    string companyName;
    string mode;
    string departure;
    string arrival;
    string departureTime;
    float priceperTicket;
    int totalSeats;
    int availableSeats;
};

struct Booking {
    int bookingId;
    string customerName;
    string phoneNumber;
    string companyName;
    string modeofTransport;
    string departure;
    string arrival;
    string departureTime;
    int numTickets;
    float priceperTicket;
    string travelDate;
};

// ===== Global Variables =====
Transport transports[50];
int transportCount = 0;
Booking bookings[100];
int bookingCount = 0;
int nextTransportId = 1;
int nextBookingId = 1;

// ===== Load Transports =====
void loadTransports() {
    ifstream file("Transports.txt");
    if (file.is_open()) {
        int maxId = 0;
        transportCount = 0;
        while (file >> transports[transportCount].transportID) {
            file.ignore();
            getline(file, transports[transportCount].companyName);
            getline(file, transports[transportCount].mode);
            getline(file, transports[transportCount].departure);
            getline(file, transports[transportCount].arrival);
            getline(file, transports[transportCount].departureTime);
            file >> transports[transportCount].totalSeats;
            file >> transports[transportCount].availableSeats;
            file >> transports[transportCount].priceperTicket;
            file.ignore();
            if (transports[transportCount].transportID > maxId)
                maxId = transports[transportCount].transportID;
            transportCount++;
        }
        file.close();
        nextTransportId = maxId + 1;
    }
}

// ===== Save Transports =====
void saveTransports() {
    ofstream file("Transports.txt");
    for (int i = 0; i < transportCount; i++) {
        file << transports[i].transportID << endl;
        file << transports[i].companyName << endl;
        file << transports[i].mode << endl;
        file << transports[i].departure << endl;
        file << transports[i].arrival << endl;
        file << transports[i].departureTime << endl;
        file << transports[i].totalSeats << endl;
        file << transports[i].availableSeats << endl;
        file << transports[i].priceperTicket << endl;
    }
    file.close();
}

// ===== Add Transport =====
void addTransport() {
    Transport t;
    t.transportID = nextTransportId++;
    cout << "Generated Transport ID: " << t.transportID << endl;
    cin.ignore();
    cout << "Enter Company Name: ";
    getline(cin, t.companyName);
    cout << "Enter Mode (Bus/Train): ";
    getline(cin, t.mode);
    cout << "Enter Departure Location: ";
    getline(cin, t.departure);
    cout << "Enter Arrival Location: ";
    getline(cin, t.arrival);
    cout << "Enter Departure Time (e.g., 10:00AM): ";
    getline(cin, t.departureTime);
    cout << "Enter Total Seats: ";
    cin >> t.totalSeats;
    t.availableSeats = t.totalSeats;
    cout << "Enter Price per Ticket: ";
    cin >> t.priceperTicket;

    transports[transportCount++] = t;

    saveTransports();
    cout << "Transport added successfully!\n";
    system("pause");
}

// ===== Update Transport =====
void updateTransport() {
    int id;
    cout << "Enter Transport ID to update: ";
    cin >> id;
    int found = 0;
    for (int i = 0; i < transportCount; i++) {
        if (transports[i].transportID == id) {
            cin.ignore();
            cout << "Enter New Company Name: ";
            getline(cin, transports[i].companyName);
            cout << "Enter New Mode: ";
            getline(cin, transports[i].mode);
            cout << "Enter New Departure: ";
            getline(cin, transports[i].departure);
            cout << "Enter New Arrival: ";
            getline(cin, transports[i].arrival);
            cout << "Enter New Departure Time: ";
            getline(cin, transports[i].departureTime);
            cout << "Enter New Total Seats: ";
            cin >> transports[i].totalSeats;
            transports[i].availableSeats = transports[i].totalSeats;
            cout << "Enter New Price per Ticket: ";
            cin >> transports[i].priceperTicket;
            saveTransports();
            cout << "Transport updated successfully!\n";
            found = 1;
            break;
        }
    }
    if (!found) cout << "Transport not found!\n";
    system("pause");
}

// ===== Show Transports =====
void showTransports() {
    cout << "\n===============================================================================================================\n";
    cout << "| ID | Company       | Mode   | Departure | Arrival | Time     | Price | Available Seats |\n";
    cout << "---------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < transportCount; i++) {
        cout << "| "
             << setw(2) << transports[i].transportID << " | "
             << setw(13) << transports[i].companyName << " | "
             << setw(6) << transports[i].mode << " | "
             << setw(9) << transports[i].departure << " | "
             << setw(7) << transports[i].arrival << " | "
             << setw(8) << transports[i].departureTime << " | "
             << setw(5) << transports[i].priceperTicket << " | "
             << setw(15) << transports[i].availableSeats << " |\n";
    }
    cout << "===============================================================================================================\n";
}

// ===== Load Bookings =====
void loadBookings() {
    ifstream infile("Bookings.txt");
    if (infile.is_open()) {
        int maxId = 0;
        bookingCount = 0;
        while (infile >> bookings[bookingCount].bookingId) {
            infile.ignore();
            getline(infile, bookings[bookingCount].customerName);
            getline(infile, bookings[bookingCount].phoneNumber);
            getline(infile, bookings[bookingCount].companyName);
            getline(infile, bookings[bookingCount].modeofTransport);
            getline(infile, bookings[bookingCount].departure);
            getline(infile, bookings[bookingCount].arrival);
            getline(infile, bookings[bookingCount].departureTime);
            infile >> bookings[bookingCount].numTickets;
            infile >> bookings[bookingCount].priceperTicket;
            infile.ignore();
            getline(infile, bookings[bookingCount].travelDate);
            if (bookings[bookingCount].bookingId > maxId)
                maxId = bookings[bookingCount].bookingId;
            bookingCount++;
        }
        infile.close();
        nextBookingId = maxId + 1;
    }
}

// ===== Save Bookings =====
void saveBookings() {
    ofstream outfile("Bookings.txt");
    for (int i = 0; i < bookingCount; i++) {
        outfile << bookings[i].bookingId << endl;
        outfile << bookings[i].customerName << endl;
        outfile << bookings[i].phoneNumber << endl;
        outfile << bookings[i].companyName << endl;
        outfile << bookings[i].modeofTransport << endl;
        outfile << bookings[i].departure << endl;
        outfile << bookings[i].arrival << endl;
        outfile << bookings[i].departureTime << endl;
        outfile << bookings[i].numTickets << endl;
        outfile << bookings[i].priceperTicket << endl;
        outfile << bookings[i].travelDate << endl;
    }
    outfile.close();
}

// ===== Add Booking =====
void addBooking() {
    system("cls");
    cout << "========== Book a Ticket ==========\n";
    showTransports();

    Booking b;
    b.bookingId = nextBookingId++;
    cout << "Generated Booking ID: " << b.bookingId << endl;
    cin.ignore();
    cout << "Enter Customer Name: ";
    getline(cin, b.customerName);
    cout << "Enter Phone Number: ";
    getline(cin, b.phoneNumber);

    int selectedID, found = 0;
    cout << "Enter Transport ID: ";
    cin >> selectedID;

    for (int i = 0; i < transportCount; i++) {
        if (transports[i].transportID == selectedID) {
            b.companyName = transports[i].companyName;
            b.modeofTransport = transports[i].mode;
            b.departure = transports[i].departure;
            b.arrival = transports[i].arrival;
            b.departureTime = transports[i].departureTime;
            b.priceperTicket = transports[i].priceperTicket;

            cout << "Available Seats: " << transports[i].availableSeats << endl;
            cout << "Enter Number of Tickets: ";
            cin >> b.numTickets;
            if (b.numTickets > transports[i].availableSeats) {
                cout << "Not enough seats!\n";
                return;
            }
            transports[i].availableSeats -= b.numTickets;
            saveTransports();
            found = 1;
            break;
        }
    }

    if (!found) {
        cout << "Transport ID not found.\n";
        return;
    }

    cin.ignore();
    cout << "Enter Travel Date: ";
    getline(cin, b.travelDate);

    bookings[bookingCount++] = b;
    saveBookings();
    cout << "Booking done! Total Fare: " << b.numTickets * b.priceperTicket << endl;
    system("pause");
}

// ===== View Bookings =====
void viewBookings() {
    cout << "\n==============================================================================================================================\n";
    cout << "| ID | Name | Phone | Company | Mode | From | To | Time | Tickets | Fare | Date |\n";
    cout << "------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < bookingCount; i++) {
        cout << "| "
             << setw(2) << bookings[i].bookingId << " | "
             << setw(4) << bookings[i].customerName << " | "
             << setw(10) << bookings[i].phoneNumber << " | "
             << setw(7) << bookings[i].companyName << " | "
             << setw(4) << bookings[i].modeofTransport << " | "
             << setw(5) << bookings[i].departure << " | "
             << setw(4) << bookings[i].arrival << " | "
             << setw(5) << bookings[i].departureTime << " | "
             << setw(7) << bookings[i].numTickets << " | "
             << setw(4) << bookings[i].priceperTicket << " | "
             << setw(5) << bookings[i].travelDate << " |\n";
    }
    cout << "==============================================================================================================================\n";
    system("pause");
}

// ===== Customer Cancel Booking =====
void customerCancelBooking() {
    int id;
    string phone;
    cout << "Enter Booking ID to cancel: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Phone Number: ";
    getline(cin, phone);
    int found = 0;

    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingId == id && bookings[i].phoneNumber == phone) {
            for (int j = 0; j < transportCount; j++) {
                if (bookings[i].companyName == transports[j].companyName &&
                    bookings[i].modeofTransport == transports[j].mode &&
                    bookings[i].departure == transports[j].departure &&
                    bookings[i].arrival == transports[j].arrival) {
                    transports[j].availableSeats += bookings[i].numTickets;
                    break;
                }
            }
            for (int j = i; j < bookingCount - 1; j++)
                bookings[j] = bookings[j + 1];
            bookingCount--;
            saveTransports();
            saveBookings();
            cout << "Booking cancelled & seats restored!\n";
            found = 1;
            break;
        }
    }

    if (!found) cout << "Booking not found or phone incorrect.\n";
    system("pause");
}

// ===== View Stats =====
void viewStats() {
    cout << "\n==== Booking Statistics ====\n";
    cout << "Total Bookings: " << bookingCount << endl;
    int totalTickets = 0;
    float totalRevenue = 0;
    for (int i = 0; i < bookingCount; i++) {
        totalTickets += bookings[i].numTickets;
        totalRevenue += bookings[i].numTickets * bookings[i].priceperTicket;
    }
    cout << "Total Tickets Sold: " << totalTickets << endl;
    cout << "Total Revenue: $" << totalRevenue << endl;
    system("pause");
}

// ===== Admin Panel =====
void adminPanel() {
    int choice = 0;
    do {
        system("cls");
        cout << "\n==== Admin Panel ====\n";
        cout << "1. View All Bookings\n";
        cout << "2. Cancel Booking\n";
        cout << "3. Add/Update Transport\n";
        cout << "4. View Statistics\n";
        cout << "5. Exit to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) viewBookings();
        else if (choice == 2) customerCancelBooking();
        else if (choice == 3) {
            int sub;
            cout << "1. Add Transport\n2. Update Transport\n";
            cin >> sub;
            if (sub == 1) addTransport();
            else if (sub == 2) updateTransport();
        }
        else if (choice == 4) viewStats();
    } while (choice != 5);
}

// ===== Customer Panel =====
void customerPanel() {
    int choice = 0;
    do {
        system("cls");
        cout << "\n==== Customer Panel ====\n";
        cout << "1. Book Ticket\n2. View My Bookings\n3. Cancel My Booking\n4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) addBooking();
        else if (choice == 2) viewBookings();
        else if (choice == 3) customerCancelBooking();
    } while (choice != 4);
}

// ===== Main =====
int main() {
    loadTransports();
    loadBookings();
    int role = 0;
    do {
        system("cls");
        cout << "\n==== Travel Booking System ====\n";
        cout << "1. Admin\n2. Customer\n3. Exit\n";
        cout << "Choice: ";
        cin >> role;

        if (role == 1) {
            string pwd;
            cout << "Enter Admin Password: ";
            cin >> pwd;
            if (pwd == "admin123") adminPanel();
            else { cout << "Wrong password!\n"; system("pause"); }
        } else if (role == 2) customerPanel();
    } while (role != 3);

    return 0;
}

