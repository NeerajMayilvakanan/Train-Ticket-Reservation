# Train-Ticket-Reservation
A console-based Railway Reservation System in C that supports train management, seat booking, cancellation, tatkal reservations, and day-wise tracking using file handling and linked lists for dynamic data storage.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [File Structure](#file-structure)
- [System Requirements](#system-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Functions](#functions)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

This system is designed to manage train details and ticket reservations efficiently. It uses a file-based approach, where train data, availability, and booking information are stored in text files. The system can:

- Add new train details.
- Update seat availability for each train.
- Track ticket bookings for various categories (e.g., AC, Tatkal, etc.).
- Manage ticket counts for different days.

The system utilizes linked lists for dynamically managing train details and seat availability, which allows for efficient traversal and modification of data.

---

## Features

- **Train Details Management:** Add and store information about trains, including train numbers, names, departure times, destination times, and distances.
- **Seat Availability:** Manage availability for different classes (e.g., AC, PR, NA, Tatkal) and track bookings for these classes.
- **Ticket Booking:** Handle bookings for different categories such as senior citizens, pregnant women, and regular passengers.
- **Multiple Day Support:** The system can handle data for multiple days (Day 1 to Day 6) with separate files for each day.
- **Data Persistence:** All train details and ticket bookings are saved to text files for long-term storage.
- **Dynamic Memory Management:** Uses linked lists to store and manage train data dynamically, making it scalable.

---

## File Structure

The project uses several text files for storing data:

- `train_det.txt`: Contains the basic details of each train (train number, name, departure time, destination, etc.).
- `seat_avail.txt`: Stores seat availability and pricing information for each train (e.g., AC, PR, Tatkal).
- `day_X.txt`: Stores ticket bookings for each day (Day 1 to Day 6). Each file holds booking information for a specific day.
- `count_dayX.txt`: Tracks ticket counts for each day, including total tickets sold and ticket prices.
- `total.txt`: Holds metadata such as the total number of trains, serial numbers, and ticket numbers.

**Example File Structure:**
- total.txt
- train_det.txt
- seat_avail.txt
- day_1.txt
- day_2.txt
- day_3.txt
- day_4.txt
- day_5.txt
- day_6.txt
- count_day1.txt
- count_day2.txt
- count_day3.txt
- count_day4.txt
- count_day5.txt
- count_day6.txt


---

## System Requirements

- **C Compiler:** This project is written in C. You will need a C compiler like GCC to compile and run the code.
- **Operating System:** The program should work on any system that supports C, including Windows, Linux, and macOS.

---

## Installation

Clone the repository:
git clone <repository-url>

Navigate to the project directory:
cd train-ticket-booking-system

Compile the code using a C compiler (e.g., GCC):
gcc -o train_booking train_booking.c

Run the compiled program:
./train_booking

---

## Usage

The system provides several functions for managing train details and booking tickets.

- **Add Train Details:** The user can add new train details, including information like train number, name, departure time, and seat availability.
- **Read Data:** The system loads existing data from text files to track seat availability and ticket bookings.
- **Ticket Booking:** Users can book tickets for different categories, and the system will update the available seats accordingly.


The system will ask for inputs related to train details, seat availability, and ticket booking. After each action, the data is saved to the respective text files.

---

## Functions

The system includes the following main functions:

### 1. `write_data()`
- Adds new train details and seat availability data to the respective files.
- Updates the seat availability for each class (AC, PR, Tatkal).

### 2. `read_data()`
- Reads and loads train details, seat availability, and ticket booking information from various files.
- Manages daily ticket count data.

### 3. `train_writ()`
- Writes the updated train details to files.

### 4. `add_train_details()`
- Allows the addition of a new train to the system with the necessary details (train number, name, departure time, etc.).

---

## Contributing

We welcome contributions! If you'd like to help improve this project, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-name`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add feature'`).
5. Push to the branch (`git push origin feature-name`).
6. Create a pull request.

Please ensure that your code adheres to the project's coding style and includes tests for any new functionality.

---

## License

This project is licensed under the **MIT License**.  
See the `LICENSE` file for more details.
