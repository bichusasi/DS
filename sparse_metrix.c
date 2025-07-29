#include<stdio.h>

int main() {
    int i, j, k = 0,l=0,r,c;  
    int a[10][10], b[10][3],d[10][3],sum[10][3];
    
    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &r);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &c);

    
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                b[k][0] = i;         
                b[k][1] = j;        
                b[k][2] = a[i][j];   
                k++;  
            }
        }
    }
    
    printf("1st Sparse matrix representation:\n");
    printf("ROW\tCOLUMN\tVALUE\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }


     printf("Enter the elements of the 2nd matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (b[i][j] != 0) {
                d[l][0] = i;         
                d[l][1] = j;         
                d[l][2] = b[i][j];  
                l++;  
            }
        }
    }

     printf("2nd Sparse matrix representation:\n");
    printf("ROW\tCOLUMN\tVALUE\n");
    for (i = 0; i < l; i++) {
        printf("%d\t%d\t%d\n", d[i][0], d[i][1], d[i][2]);
    }


    int m = 0, n = 0, p = 0;
    while (m < k && n < l) {
        if (b[m][0] == d[n][0] && b[m][1] == d[n][1]) {
            sum[p][0] = b[m][0];  
            sum[p][1] = b[m][1]; 
            sum[p][2] = b[m][2] + d[n][2];  
            m++; n++; p++;
        } else if (b[m][0] < d[n][0] || (b[m][0] == d[n][0] && b[m][1] < d[n][1])) {
            sum[p][0] = b[m][0];
            sum[p][1] = b[m][1];
            sum[p][2] = b[m][2];
            m++; p++;
        } else {
            sum[p][0] = d[n][0];
            sum[p][1] = d[n][1];
            sum[p][2] = d[n][2];
            n++; p++;
        }
    }
     while (m < k) {
        sum[p][0] = b[m][0];
        sum[p][1] = b[m][1];
        sum[p][2] = b[m][2];
        m++; p++;
    }

    while (n < l) {
        sum[p][0] = d[n][0];
        sum[p][1] = d[n][1];
        sum[p][2] = d[n][2];
        n++; p++;
    }

    printf("Sparse matrix representation of the sum:\n");
    printf("ROW\tCOLUMN\tVALUE\n");
    for (i = 0; i < p; i++) {
        printf("%d\t%d\t%d\n", sum[i][0], sum[i][1], sum[i][2]);
    }



    return 0;
}