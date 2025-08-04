# 🚗 Car Rental System (C Project)

## 📌 Description

This is a **console-based car rental management system** written in C. It simulates a rental company's internal system with two user roles:

- **Admin** (Root)
- **User** (Customer)

Each role has different functionalities related to **cost management**, **rental processing**, and **payment handling**.

---

## 👥 User Roles

### 👤 User (Customer)
Users can:
- **Sign up** and **log in**
- **Calculate rental cost** based on:
  - Age
  - Car engine size (cc)
  - Number of rental days
- **Choose a payment method** (card or cash)
- **Receive a detailed receipt**

### 🛠️ Admin (Root)
Admins can:
- **Log in with credentials**
- **Adjust insurance rate coefficients** for different engine sizes
- Allowed adjustments: **raise/lower by up to 10%**

---

## 🔑 Login Info

- **Admin Username:** `root`  
- **Admin Password:** `Root123`

User credentials are created during runtime via sign-up.

---

## 💡 Technologies & Features

- **Language:** C (Standard C libraries only)
- **String handling:** `string.h`
- **Console I/O**: `stdio.h`
- **Memory handling and exit management:** `stdlib.h`
- **Simple UI elements:** Console menus with ASCII layout
- **Security Notes:**
  - No real password encryption
  - No persistent storage (everything resets after program exit)

---

## 🧮 Rental Cost Calculation

Rental cost depends on:
- Engine size (≤1600cc, 1601–2000cc, >2000cc)
- Days (derived from a static string `'E22101'`, which is split and added: `0+1 = 1 day`)
- Age (affects insurance rate via coefficients)

Insurance Rate Coefficients:
- `r1` for 18–22 years
- `r2` for 23–30 years
- `r3` for 31+ years

---

## 💳 Payment Options

- **Cash:** No discount  
- **Card:** 15% discount + input card number (validated length only)

---

## 🧾 Receipt Includes

- Rental days, age, car engine size
- Base cost and insurance cost
- Discount applied (if any)
- Final total
- Credit card info (masked display)

---

   ```bash
   gcc -o car_rental car_rental.c
