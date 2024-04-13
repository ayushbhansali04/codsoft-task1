//TASK 5 MOVIE TICKECT BOOKING SYSTEM

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

const int NUM_ROWS = 5;
const int NUM_COLS = 10;

class MovieTicketBookingSystem {
private:
    std::vector<std::vector<bool>> seatAvailability;
    double ticketPrice;

public:
    MovieTicketBookingSystem(double price) : ticketPrice(price) {
        seatAvailability.resize(NUM_ROWS, std::vector<bool>(NUM_COLS, true));
    }

    void displayMovieListing() const {
        std::cout << "Movie Listings:" << std::endl;
        // Display movie listings here
    }

    void displaySeatingChart() const {
        std::cout << "Seating Chart:" << std::endl;
        // Display seating chart here
    }

    bool isSeatAvailable(int row, int col) const {
        return seatAvailability[row][col];
    }

    bool bookSeat(int row, int col) {
        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS || !isSeatAvailable(row, col)) {
            std::cout << "Invalid seat selection. Please try again." << std::endl;
            return false;
        }

        seatAvailability[row][col] = false;
        std::cout << "Seat booked successfully!" << std::endl;
        return true;
    }

    double calculateTotalCost(int numTickets) const {
        return numTickets * ticketPrice;
    }
};

int main() {
    double ticketPrice;
    int numTickets;

    // Get ticket price from the user
    std::cout << "Enter ticket price: $";
    std::cin >> ticketPrice;

    // Create the movie ticket booking system
    MovieTicketBookingSystem bookingSystem(ticketPrice);

    // Display movie listings
    bookingSystem.displayMovieListing();

    // Display seating chart
    bookingSystem.displaySeatingChart();

    // Get seat selection and make a booking
    int selectedRow, selectedCol;
    std::cout << "Enter row and column for seat selection (e.g., 1 5): ";
    std::cin >> selectedRow >> selectedCol;

    // Validate and book the seat
    while (!bookingSystem.bookSeat(selectedRow - 1, selectedCol - 1)) {
        // Clear input buffer in case of invalid input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter row and column for seat selection (e.g., 1 5): ";
        std::cin >> selectedRow >> selectedCol;
    }

    // Get the number of tickets for the booking
    std::cout << "Enter the number of tickets: ";
    std::cin >> numTickets;

    // Calculate and display the total cost
    double totalCost = bookingSystem.calculateTotalCost(numTickets);
    std::cout << "Total cost for " << numTickets << " tickets: $" << std::fixed << std::setprecision(2) << totalCost << std::endl;

    return 0;
}