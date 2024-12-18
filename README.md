# K-Means Clustering Algorithm Implementation

**Author:** [VASU KARA] (IIT GUWAHATI)  
**License:** [MIT License](LICENSE)

---

## Introduction

This repository contains an implementation of the K-Means Clustering algorithm using C++. The purpose of the algorithm is to partition a dataset into clusters, where each cluster is represented by its centroid. This implementation uses the Tokura distance, a weighted Euclidean distance, to measure similarity between data points and centroids.

---

## Features

1. **Input Data from CSV:** Reads the dataset from a CSV file (`Universe.csv` by default).
2. **Random Initialization:** Initializes centroids randomly from the dataset.
3. **Cluster Assignment:** Assigns each data point to the nearest centroid.
4. **Centroid Recalculation:** Recomputes centroids based on cluster assignments.
5. **Convergence Criterion:** Iterates until convergence based on distortion.
6. **Output Codebook:** Writes the final centroids (codebook) to a CSV file.

---

## Initialization

The code defines constants such as:
- **row_length:** number of data points (rows in the CSV).
- **col_length:** number of features (columns in the CSV).
- **k:** number of clusters.

It also allocates storage arrays for:
- **Data:** Original dataset array.
- **Centroids:** Array of centroid coordinates.
- **Cluster Assignments:** Each data point’s assigned cluster.

The initial centroids are chosen randomly from the dataset.

---

## Distance Calculation (Tokura Distance)

A function named `tokura_distance` calculates the weighted squared Euclidean distance between a data point and a centroid using predefined Tokura weights. This distance metric determines cluster assignments. If you prefer, you can easily switch to another metric (like standard Euclidean distance) by adjusting this function.

---

## K-Means Algorithm

The `k_means` function is the main driver of the algorithm. It performs the following steps until convergence:

1. **Assignment Step:** Assign each data point to the nearest centroid based on Tokura distance.
2. **Update Step:** Recompute the centroids by taking the average of the data points in each cluster.
3. **Convergence Check:** Calculate the total distortion (sum of distances of all points to their centroids) and compare it with the previous iteration. If the change in distortion is below a certain threshold (`0.00001`), the algorithm stops.

---

## Distortion Calculation

**Distortion** is a measure of how "tight" the clusters are. After each iteration, the algorithm calculates the distortion. When the decrease in distortion between successive iterations is minimal (less than `0.00001`), the algorithm considers that it has converged.

---

## Input Data

The input dataset is read from a CSV file using the `read_csv_to_float_array` function. The CSV file should be formatted as:
- **Rows:** Data points
- **Columns:** Features

Update `row_length` and `col_length` in the code if your dataset differs in size.

---

## Output

The final centroids (often called the "codebook") are written to a CSV file using the `write_codebook` function. This provides a set of centroids representing each cluster.

---

## Prerequisites

1. **C++ Compiler:** A C++ compiler like GCC, Clang, or Visual Studio.
2. **Dataset:** A CSV file (`Universe.csv` by default) formatted as described above.

---

## Steps to Run

1. **Clone or Download the Repository.**
2. **Compile the code (e.g., using GCC):**
   ```bash
   g++ 244101064_Kmeans_Assignment5.cpp -o kmeans
