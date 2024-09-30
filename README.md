# K-Means Clustering Algorithm Implementation

**Introduction**

This repository contains an implementation of the K-Means Clustering algorithm using C++. The purpose of the algorithm is to partition a dataset into clusters, where each cluster is represented by its centroid. This implementation uses Tokura distance, a weighted Euclidean distance, to measure similarity between data points and centroids.

**Features:**
1. Reads input data from a CSV file.
2. Initializes centroids randomly from the dataset.
3. Assigns each data point to the nearest centroid.
4. Recomputes centroids based on cluster assignments.
5. Iterates until convergence based on distortion.
6. Writes the final centroids (codebook) to a CSV file.
   

**Initialization:**

The code defines constants such as the number of rows, columns, and clusters (k), as well as storage arrays for data, centroids, and cluster assignments.
Random initial centroids are chosen from the dataset.

**Distance Calculation (Tokura Distance):**

A function named tokura_distance calculates the weighted squared Euclidean distance between a data point and a centroid using predefined Tokura weights. This distance is used to assign each data point to its nearest centroid.

**K-Means Algorithm:**

The k_means function is the main driver of the algorithm. It repeats the following steps:
Assigns each data point to the nearest centroid.
Recomputes the centroids by averaging the points in each cluster.
Calculates the total distortion (sum of distances between data points and centroids) to monitor convergence.

**Distortion Calculation:**

The distortion is a metric used to determine the "tightness" of the clusters. The algorithm stops iterating once the difference in distortion between successive iterations is below a threshold (0.00001).

**Input Data:**

The input dataset is read from a CSV file using the read_csv_to_float_array function. The data must be formatted with rows representing data points and columns representing features.

**Output:**

The final centroids (codebook) are written to a CSV file using the write_codebook function.

**Prerequisites:**
1. A C++ compiler (such as GCC or Visual Studio).
2. A dataset in the form of a CSV file (for this code, it's expected to be named Universe.csv).

**Steps to run :**

Clone or Download the repository
Run using Vscode 2010
OR
Run 244101064_Kmeans_Assignment5.cpp using 

`g++ 244101064_Kmeans_Assignment5.cpp -o kmeans`

`./kmeans`

**Customization:**

**Adjusting k (Number of Clusters):**

Modify the value of k at the beginning of the code to change the number of clusters.

**Changing Dataset Dimensions:**

If your dataset has different row and column sizes, update the constants row_length and col_length accordingly.

**Using a Different Distance Metric:**

You can replace the Tokura distance calculation in tokura_distance with any other distance metric such as standard Euclidean distance.


License: Vasu Kara (IIT GUWAHATI)

This project is licensed under the MIT License.

Author:
[VASU KARA]
