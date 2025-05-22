# 🧭 Shortest Possible Route Detection System

A project developed between **February 2024 – April 2024** that implements advanced algorithms to determine the most efficient round-trip route for visiting multiple cities — addressing the well-known **Travelling Salesman Problem (TSP)**. The system focuses on achieving a strong balance between **solution quality** and **computational efficiency**, making it applicable in real-world logistics and routing systems.

## 📌 Problem Statement

Determine the shortest possible route that visits a set of cities exactly once and returns to the origin city, minimizing the total travel distance.

## 🚀 Key Features

- 🔁 **Round-trip Route Planning**  
  Determines an optimized round-trip covering all cities.

- 🧠 **Smart Algorithm Integration**  
  Combines **Christofides Algorithm** (approximation) with **Genetic Algorithm** (optimization).

- ⚙️ **Efficient & Adaptable**  
  Balances route quality with execution speed — ideal for practical deployment scenarios.

## 🧪 Algorithms Used

- **Greedy Algorithm**: For initial baseline performance.
- **Christofides Algorithm**:  
  - Provides a route within **1 to 1.5 times the optimal solution**.
  - Ensures a near-optimal starting point with polynomial time complexity.
- **Genetic Algorithm**:  
  - Performs further optimization on the Christofides path.  
  - Evolved the population for **100 generations** to refine the solution further.

## 🛠️ Tech Stack

- **Language**: Python
- **Libraries**: NumPy, NetworkX, Matplotlib (for visualization), custom TSP solver modules

## 📈 Results

- Christofides Algorithm provided high-quality initial paths.
- Genetic Algorithm optimization reduced the average route distance significantly.
- Final solution was competitive, often falling within **5–10% of the theoretical optimum**.

## 🧠 Applications

- Logistics and Delivery Routing
- Sales Route Optimization
- Robotics Path Planning
- Network Routing
