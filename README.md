# "Bank-Sytem"

📋 Overview
This is a console-based Bank System written in C++ that allows bank staff to manage clients, perform basic banking operations, and store data persistently using files. It demonstrates key Object-Oriented Programming (OOP) concepts such as inheritance, encapsulation, and file handling.

## 🚀 Features

### 🧑‍💼 Client & Account Management

- Add, update, delete, and search for clients
- Deposit, withdraw, and transfer funds
- Show transaction history
- Filter/search clients
- Each client has a unique account number, PIN code, and balance

### 👤 User Management (Admins/Employees)

- Add new users (e.g., staff)
- Delete existing users
- Update user details
- Search for a user by username
- Show all system users
- Role-based access control via permissions

### 💱 Currency Management

- Add, update, and delete currencies
- Convert between currencies
- Transfer funds using different currencies
- Display available currencies with exchange rates

### 🔐 Security & Permissions

- Secure login system for users

- Permission-based access (e.g., some users can't delete clients)

- Admins can grant or restrict actions using bitwise flags

## 🛠️ Technologies Used

- C++
- OOP (Classes, Inheritance, Encapsulation)
- STL (vectors, strings)
- File handling

## ▶️ How to Run

### Option 1:Using Git

**1-Clone the repository:**

```bash
git clone https://github.com/Mazen-Eltelbany/Bank-System.git
Open the project in your preferred IDE or compile using:
```

**2-Navigate to the project:**

```bash
cd Bank-System
cd Bank-Sytem-files
```

3- **Compile:**
"If you don't have a g++ compiler download from this video"
<a href="https://youtu.be/GxFiUEO_3zM">The Installation guide</a>

```bash
g++ Bank-System.cpp -o BS
```

4- **Run:**

```bash
./ BS
```

### Option 2: Download As ZIP:

**1- Download the ZIP:**

- Go to the repo:Bank-System on GitHub
- Click the green "Code" button → Download ZIP
- Extract it anywhere on your computer

**2- Open The Folder:**

```bash
cd Bank-Sytem-Main
cd Bank-System-files
```

**3- Compile And Run:**

```bash
g++ Bank-System.cpp -o BS
./ BS
```

## Author

- 👤 Mazen Eltelbany
