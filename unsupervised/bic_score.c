#include <stdio.h>
#include <math.h>

static void calculate_centroid(float *centroid, float *points[], int n_dims, int *cluster_idxs, int n_points_cluster) {
    float mean_for_dim[n_dims];
    memset(mean_for_dim, 0, n_dims);
    for (int i = 0; i < n_points_cluster; i++) {
        for (int j = 0; j < n_dims; j++) {
            mean_for_dim[j] += points[i][j];
        }
    }
}

double bic_score(float *points[], int n_dims, int n_samples, int *labels[], int n_clusters) {

    double score = 0.0;
    double log_likelihood = 0.0;
    int n_parameters = (n_clusters - 1) + (n_dims * n_clusters) + 1;

    printf("\
    [*] Computing BIC Score (Bayesian Information Criterion) \n\
    [*] Data: \n\
    \tNumber of points: %i \n\
    \tNumber of clusters: %i \n\
    \tNumber of dimensions: %i \n\
    \tNumber of parameters: %i \n", n_samples, n_clusters, n_dims, n_parameters);

    for (int i = 0; i < n_clusters; i++) {
        int cluster_idxs[n_samples];
        int n_points_cluster = 0;
        //Get the indexs of the samples of the current cluster
        for (int j = 0; j < n_samples; j++) {
            if (labels[j] == i) {
                cluster_idxs[n_points_cluster] = j;
                n_points_cluster++;
            }
        }
        // Calculare Centroid
        float centroid[1][n_dims];
        calculate_centroid(&centroid, points, n_dims, cluster_idxs, n_points_cluster);
    }
    printf("[*] BIC Score -> %.6f \n", score);
    return score;
}