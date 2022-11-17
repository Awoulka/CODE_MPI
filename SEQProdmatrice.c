#include <stdio.h>
#include <sys/time.h>
#include <time.h> 
#include <math.h> // Parcequ'on appelle la fonction log
#define N 3

int main(int argc, char **argv) {

struct timeval start, end;
 
    
    
    //time_t begin = time(NULL);
    
  int m=3, n=3, p=3,q=3,i=0, j=0, k=0;
  //const int M_max=100, N_max=100;

  printf("Hello! Ce programme calcule le produit de deux matrices A et B entrees par l'utilisateur.\n");
  //printf("Entrez le nombre de lignes et de colonnes de la matrice A: ");
  //scanf("%d,%d", &m, &n);
  //printf(" mat A m=%d, n=%d\n", m,n);
double A[3][3] = {{1,2,3},{2,5,6},{2,3,7}}, B[3][3]= {{-1,6,7},{8,9,-7},{-6,5,2}},C[N][N];

//double A[5][5] = {{1,2,3,7,6},{2,5,6,5,8},{2,3,7,1,3},{1,4,3,2,4},{3,2,3,3,6}}, B[5][5]= {{-1,6,7,3,7},{8,9,-7,-9,-1},{-6,5,2,2,-1},{1,-2,3,-2,-5},{-1,2,1,2,-1}},C[N][N];
/*const int AM_max=m, AN_max=n;
  double A[AM_max][AN_max];

printf("Entrez le nombre de lignes et de colonnes de la matrice B: ");
  scanf("%d,%d", &p, &q);
  printf("mat B: p=%d, q=%d\n", p,q);

  const int BM_max=p, BN_max=q;
  double B[BM_max][BN_max], C[AM_max][BN_max];

  if(n!=p){printf("La multiplication de la matrice A par B est impossible car les dimensions sont incompatibles"); return 0;}
  else{
    printf("Chargement de la matrice A:\n");
    for(i=0; i<m;i++){
        for(j=0; j<n;j++){
        printf("Entrez la valeur de A[%d][%d]: ",i+1,j+1);
        scanf("%lf", &A[i][j]);
        }
        printf("\n");

    }

    printf("Chargement de la matrice B:\n");
    for(i=0; i<n;i++){
        for(j=0; j<q;j++){
        printf("Entrez la valeur de B[%d][%d]: ",i+1,j+1);
        scanf("%lf", &B[i][j]);
        }
        printf("\n");

    }
*/
    //Calcule  du produit AXB
    
    gettimeofday(&start, NULL);
    
    for(i=0; i<m;i++){
        for(j=0; j<q;j++){

            for(k=0; k<n;k++){
            C[i][j]+=A[i][k]*B[k][j];
            }
            printf("\n");

    }

    }
    
      gettimeofday(&end, NULL);

    //Affichage du produit AXB
    printf("Le produit AxB est: \n");

    for(i=0; i<m;i++){
        for(j=0; j<q;j++){


            printf("%.2f | ",C[i][j]);

            }
        printf("\n");
    }
    
  
    // time_t ends = time(NULL);
 
    long seconds = (end.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    printf("The elapsed time is %ld seconds and %ld micros\n", seconds, micros);
     //printf("The elapsed time is %ld seconds", (ends * 1000000 - begin * 1000000));

 // }



  return 0;
}
