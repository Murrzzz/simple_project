
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4

int main(){
	

	int A[2][4] = { {1, 1, 0, 1}, {2, 1, 1, 0} };
	int b[2] = {8, 10};
	int c[4] = {1, 1, 0, 0};
	int cb[2] = {c[3], c[2]};
	int B[2][1] = { {3}, {2} };
	int xb[2][1];
	int table[2][7];
	int i, j;
	int MIN = 0;

	printf("Table at itr = 0\n");
	printf("B \tCB \tXB \ty1 \ty2 \ty3 \ty4\n");

	//Table Generation
	for(i = 0; i < 2; i++)
		xb[i][0] = b[i];

	for(i = 0; i < 2; i++){
		table[i][0] = B[i][0];
		table[i][1] = cb[i];

		for(j = 0; j < 1; j++)
			table[i][2 + j] = xb[i][j];

		for(j = 0; j < N; j++)
			table[i][3 + j] = A[i][j];
	}

	for(i = 0; i < 2; i++){
		for(j = 0; j < 7; j++){
			printf("%f\t", (double) table[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Simplex Working....\n");

	int reached = 0;
	int itr = 1;
	int unbounded = 0;
	int alternate = 0;

	while(reached == 0){
		printf("Iteration: %d\n", itr);
		printf("B \tCB \tXB \ty1 \ty2 \ty3 \ty4\n");

		for(i = 0; i < 2; i++){
			for(j = 0; j < 7; j++){
				printf("%f\t", (double) table[i][j]);
			}
			printf("\n");
		}

		int rel_prof[N];
		i = 0;
		while(i < N){
			double sum = 0;
			for(j = 0; j < 2; j++)
				sum += table[j][1] * table[j][3 + i];
			rel_prof[i] = c[i] - sum;
			i++;
		}

		printf("rel profit: ");
		for(i = 0; i < N; i++)
			printf("%f,", (double) rel_prof[i]);
		printf("\n");

		i = 0;
		int b_var[2];
		for(i = 0; i < 2; i++)
			b_var[i] = table[i][0];

		while(i < N){
			int j = 0;
			int present = 0;
			while(j < 2){
				if(b_var[j] == i){
					present = 1;
					break;
				}
				j++;
			}
			if(present == 0){
				if(rel_prof[i] == 0){
					alternate = 1;
					printf("Case of Alternate found\n");
				}
			}
			i++;
		}
		printf("\n");
		int flag = 0;
		for(i = 0; i < N; i++){
			if(rel_prof[i] > 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			printf("All profits are <= 0, optimality reached\n");
			reached = 1;
			break;
		}
		int k;
		double max = rel_prof[0];
		for(i = 0; i < N; i++){
			if(rel_prof[i] > max){
				max = rel_prof[i];
				k = i;
			}
		}
		double min = 999999;
		int r = -1;
		for(i = 0; i < 2; i++){
			if(table[i][2] > 0 && table[i][3 + k] > 0){
				double val = table[i][2] / table[i][3 + k];
				if(val < min){
					min = val;
					r = i;
				}
			}
		}
		if(r == -1){
			unbounded = 1;
			printf("Case of Unbounded\n");
			break;
		}

		printf("pivot element index: %d %d\n", r, 3 + k);
		double pivot = table[r][3 + k];
		printf("pivot element: %f\n", pivot);
		for(i = 2; i < 7; i++)
			table[r][i] = table[r][i] / pivot;
		table[r][0] = k;
		table[r][1] = c[k];

		printf("\n\n");
		itr++;
	}


	printf("\n");
	printf("***************************************************************\n");
	if(unbounded == 1){
		printf("UNBOUNDED LPP\n");
		exit(0);
	}
	if(alternate == 1)
		printf("ALTERNATE Solution\n");

	printf("optimal table:\n");
	printf("B \tCB \tXB \ty1 \ty2 \ty3 \ty4\n");
	for(i = 0; i < 2; i++){
		for(j = 0; j < 7; j++){
			printf("%f\t", (double) table[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("value of Z at optimality: ");

	int basis[2];
	i = 0;
	double sum = 0;
	while(i < 2){
		sum += c[(int) table[i][0]] * table[i][2];
		char temp[10];
		sprintf(temp, "x%d", (int) table[i][0] + 1);
		basis[i] = atoi(temp);
		i++;
	}

	if(MIN == 1)
		printf("%f\n", -sum);
	else
		printf("%f\n", sum);
	printf("Final Basis: ");
	for(i = 0; i < 2; i++)
		printf("%d ", basis[i]);
	printf("\n");

	printf("Simplex Finished...\n");
	printf("\n");

	return 0;
}