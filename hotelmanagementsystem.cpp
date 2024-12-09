#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to hold customer information
struct Customer {
    string name;
    string phone;
};

// Structure to hold room information
struct Room {
    int roomNumber;
    bool isOccupied;
    Customer currentCustomer;
    double ratePerNight;
};

// Class to handle the hotel management system
class HotelManagementSystem {
private:
    vector<Room> rooms;

public:
    HotelManagementSystem(int numRooms, double ratePerNight) {
        for (int i = 0; i < numRooms; ++i) {
            rooms.push_back({i + 1, false, {"", ""}, ratePerNight});
        }
    }

    void showAvailableRooms() {
        cout << "Available Rooms:\n";
        for (const auto& room : rooms) {
            if (!room.isOccupied) {
                cout << "Room " << room.roomNumber << ", Rate: $" << room.ratePerNight << "\n";
            }
        }
    }

    void checkIn(const string& name, const string& phone, int roomNumber) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (room.isOccupied) {
                    cout << "Room " << roomNumber << " is already occupied.\n";
                } else {
                    room.isOccupied = true;
                    room.currentCustomer = {name, phone};
                    cout << "Customer " << name << " checked into room " << roomNumber << ".\n";
                }
                return;
            }
        }
        cout << "Room " << roomNumber << " does not exist.\n";
    }

    void checkOut(int roomNumber) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (room.isOccupied) {
                    cout << "Customer " << room.currentCustomer.name << " checked out from room " << roomNumber << ".\n";
                    room.isOccupied = false;
                    room.currentCustomer = {"", ""};
                } else {
                    cout << "Room " << roomNumber << " is already empty.\n";
                }
                return;
            }
        }
        cout << "Room " << roomNumber << " does not exist.\n";
    }

    void showBilling(int roomNumber, int nights) {
        for (const auto& room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (room.isOccupied) {
                    double totalBill = nights * room.ratePerNight;
                    cout << "Billing for room " << roomNumber << ": $" << fixed << setprecision(2) << totalBill << "\n";
                } else {
                    cout << "Room " << roomNumber << " is not occupied.\n";
                }
                return;
            }
        }
        cout << "Room " << roomNumber << " does not exist.\n";
    }
};

int main() {
    HotelManagementSystem hms(10, 100.0); // 10 rooms, $100 per night

    hms.showAvailableRooms();

    hms.checkIn("John Doe", "123-456-7890", 1);
    hms.checkIn("Jane Smith", "987-654-3210", 2);

    hms.showBilling(1, 3); // Billing for room 1 for 3 nights

    hms.checkOut(1);
    hms.showAvailableRooms();

    return 0;
}
