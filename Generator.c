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

    float *GenerateValues; // Array of values n
    GenerateValues =(float *) calloc(n*dim, sizeof(float));


    for (i = n; i--;)
        for (d = dim; d--;)
            GenerateValues[i*dim + d] = i + 1;

    FILE *Generator;
    Generator = fopen("DataLinear.csv", "w"); // Write because it is a generator obv
    for (i = n; i--;)
    {
        for (d = dim; d--;)
        {
        fprintf(Generator, "%lf", GenerateValues[i*dim + d]);
       if(d > 0)
        fprintf(Generator,", ");
      }
        fprintf(Generator,"\n");
      }



    fclose(Generator);
    free(GenerateValues);

    float *GenerateRandomValues; // Array of Random values n
    GenerateRandomValues =(float *) calloc(n*dim, sizeof(float));


    for (i = n; i--;)
        for (d = dim; d--;)
        GenerateRandomValues[i*dim + d] = ((rand() % (range - a + 1)) + a);

    FILE *Generator2;
    Generator2 = fopen("DataRandom.csv", "w"); // Write because it is a generator obv
    for (i = n; i--;)
    {
      for (d = dim; d--; ){
            fprintf(Generator2, "%lf ", GenerateRandomValues[i*dim + d]);

          }
          fprintf(Generator2, "\n");
}

    fclose(Generator2);
    free(GenerateRandomValues);

    return 0;
}
