#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int d;     // d counter for dimensions
    int i;     // counter
    int n;     // total values of n
    int a = 1; // use for rand
    int dim; // dimensions
    int range; //the range of values
    srand(time(NULL));

    printf("\n Choose the amount of elements you wish to cluster:");
    scanf("%d", &n);
    printf("\n Choose the amount of dimensions:");
    scanf("%d", &dim);
    printf("\n Choose the range of n values:" );
    scanf("%d",&range);

    double **GenerateValues; // Array of values n
    GenerateValues = calloc(n, sizeof(double));
    for (d = 0; d < n; d++)
        GenerateValues[d] = calloc(dim, sizeof(double *));

    for (i = 0; i < n; i++)
        for (d = 0; d < dim; d++)
            GenerateValues[i][d] = i + 1;

    FILE *Generator;
    Generator = fopen("DataLinear.csv", "w"); // Write because it is a generator obv
    for (i = 0; i < n; i++){
        for (d = 0; d < dim; d++){
        fprintf(Generator, "%lf", GenerateValues[i][d]);
       if(d < dim-1)
        fprintf(Generator,", ");
      }
        fprintf(Generator,"\n");
      }



    fclose(Generator);
    for(i = 0; i < n; i++)
    free(GenerateValues[i]);
    free(GenerateValues);

    double **GenerateRandomValues; // Array of Random values n
    GenerateRandomValues = calloc(n, sizeof(double));
    for (d = 0; d < n; d++)
        GenerateRandomValues[d] = calloc(dim, sizeof(double *));

    for (i = 0; i < n; i++)
        for (d = 0; d < dim; d++)
        GenerateRandomValues[i][d] = ((rand() % (range - a + 1)) + a);

    FILE *Generator2;
    Generator2 = fopen("DataRandom.csv", "w"); // Write because it is a generator obv
    for (i = 0; i < n; i++)
    {
      for (d = 0; d < dim; d++){
            fprintf(Generator2, "%lf", GenerateRandomValues[i][d]);
            if(d < dim-1)
            fprintf(Generator2, ", ");
          }
          fprintf(Generator2, "\n");
}

    fclose(Generator2);
 for(i = 0; i < n; i++)
    free(GenerateRandomValues[i]);
    free(GenerateRandomValues);

    return 0;
}

