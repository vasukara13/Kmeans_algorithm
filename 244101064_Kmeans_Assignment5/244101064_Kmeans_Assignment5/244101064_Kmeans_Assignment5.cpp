// 244101064_Kmeans_Assignment5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


#define row_length 12
#define col_length 6340
#define csv_column 12
#define csv_rows 6340
#define k 8

float universe[csv_rows][csv_column];
float centroid[k][csv_column];
int cluster[csv_rows]={0};
int cluster_size[k]={0};

float tokura_distance(int index , float point[csv_column]){
    float dist=0;
    float tokura_weights[csv_column]={1.0,3.0, 7.0, 13.0, 19.0, 22.0, 25.0, 33.0, 42.0, 50.0, 56.0, 61.0};
    for(int i=0;i<csv_column;i++){
        float diff = point[i] - centroid[index][i]; 
        dist+=tokura_weights[i] * (diff * diff);
        //dist+= (point[i]-centroid[index][i])*(point[i]-centroid[index][i]);
    }
    return dist;
}

void update_centroids(){
    float updated_centroids[k][csv_column]={0.0};
    for(int cent=0;cent<k;cent++){
        for (int i=0;i<csv_column;i++){
            int count=0;
            for(int j =0;j<csv_rows;j++){
                if(cluster[j]==(cent+1)){
                    updated_centroids[cent][i]+=universe[j][i];
                    count++;
                }
            }

           // printf("%d\n",count);// should print same values csv_column times
			if(count!=0){
                //printf("new centroid %f\n",updated_centroids[cent][i]);
				updated_centroids[cent][i]/=count; // avg it
                centroid[cent][i]=updated_centroids[cent][i];
            }

        }
    }
    // resetting cluster
    for(int c=0;c<csv_rows;c++){
        cluster[c]=0;
	}
}


float distortion_calculator(){
    float avg_distortion[k]={0.0};
    float distortion=0.0;
        for(int c=0;c<k;c++){
            float dist=0.0;
            for(int u=0;u<csv_rows;u++){
                if (cluster[u]==(c+1)){
                    dist+=tokura_distance(c,universe[u]);
                }
            }
       
        avg_distortion[c]=dist;
            
        }
        distortion=0.0;
        for (int d = 0; d < k; ++d)
        {
            distortion+=avg_distortion[d];
        }
        distortion/=csv_rows;
        return distortion;
}

void k_means(){
    
    float prev_distortion=0;
    float distortion=99999;
    int iterations=0;
    while(abs(distortion-prev_distortion)>0.00001){

        if(iterations!=0){
            prev_distortion=distortion;
        }
        
		
        for(int i=0;i<csv_rows;i++){
            float dist[k];
            for(int j = 0;j<k;j++){

                dist[j]=tokura_distance(j,universe[i]);
                //printf("%f\n",dist[j]);

            }

            float min=99999999;
            int cluster_index=-1;

            for (int index = 0; index < k; ++index)
            {
                if(dist[index]<min){
                    cluster_index=(index+1); // check working
                    min=dist[index];
                }
                
            }
            cluster[i]=cluster_index;
           // printf("%d\n",cluster[i]);
        }
	


        
        for(int index=0;index<k;index++){
            cluster_size[index]=0.0;
            for(int size=0;size<csv_rows;size++){
                if(cluster[size]==(index+1)){
                    cluster_size[index]+=1;
                }
            }
            //printf("%d\n",cluster_size[index]);
        }

        // calculating distortion
        distortion=distortion_calculator();
        iterations++;
        printf("For iteration : %d distortion difference is : %f\n",iterations,abs(distortion-prev_distortion));
		update_centroids();
    }
}

void read_csv_to_float_array(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open the CSV file
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    char row[1024];
    int row_index = 0;
    while (fgets(row, sizeof(row), file) && row_index < csv_rows) {
            char *token = strtok(row, ",");
            int col_index = 0;
            while (token && col_index < csv_column) {
                universe[row_index][col_index] = atof(token);
                token = strtok(NULL, ",");
                col_index++;
            }
            row_index++;
        }

    fclose(file);  // Close the file
     
}


void random_centroid(int count, int lower, int upper) {
    int generated_count = 0;
    int numbers[k]={0};
    srand(time(NULL));
    while (generated_count < count) {
        int random_number = rand() % (upper - lower + 1) + lower; // Generate a random number within range
        numbers[generated_count] = random_number;
        generated_count++;
        
    }
    for (int i=0;i<k;i++){
        printf("Initial random centroid %d : %d\n",i,numbers[i]);
        for (int j = 0; j < csv_column; ++j)
        {       
            centroid[i][j]=universe[numbers[i]][j];
    }
}
    
}


void write_codebook() {
    // Open the file for writing
    FILE *fp = fopen("Final_codebook.csv", "w");

    if (fp == NULL) {
        printf("Error: Could not open file for writing\n");
        return;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < csv_column; j++) {
            fprintf(fp, "%lf", centroid[i][j]);
            if (j < csv_column - 1) {
                fprintf(fp, ",");  // Separate elements with a comma
            }
        }
        fprintf(fp, "\n");  // Move to the next line after each row
    }

    // Close the file
    fclose(fp);
    printf("Codebook written to successfully.\n");
}


int _tmain(int argc, _TCHAR* argv[]){
    int rows, cols;
    int initial_centroid[k];

 
    read_csv_to_float_array("Universe.csv");
    random_centroid(k,0,csv_rows);
	k_means();
    write_codebook();
    
    return 0;
}
