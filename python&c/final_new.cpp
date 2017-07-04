#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <time.h>

int main(void)
{
	FILE* BTB; //blood type database
	BTB = fopen("btb.txt","r");
	double old_chart[2][6]; //AA, Ai, BB, Bi, ii, AB x:male, y:female
	double birth_rate, death_rate;
	int years;
	int population = 1000000;
	int population_m = 500000;
	int population_f = 500000;
	int couples;
	std::random_device rd;
	std::default_random_engine generator( rd() );
	fscanf(BTB, "%lf %lf", &birth_rate, &death_rate);
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 6; j++)
		{
			fscanf(BTB, "%lf", &old_chart[i][j]);
		}
	printf("%lf %lf\n", birth_rate, death_rate);
	fclose(BTB);
	printf("Please specify the number of years.\n");
	scanf("%d", &years);
	for(int r = 0; r < years; r++)
	{
		int population_m2 = population_m;
		int population_f2 = population_f;
		couples = population * birth_rate;
		int death_population_m = population_m * death_rate;
		int death_population_f = population_f * death_rate;
		int calc[2][6] = {{0}};
		std::uniform_int_distribution<int> dist(0, population);
		for(int i = 0; i < couples; i++) //birth
		{
			int male, female;
			int random_int = dist(generator);
			if(random_int < old_chart[0][0] * population)
				male = 0;
			else if(random_int < (old_chart[0][0] + old_chart[0][1]) * population)
				male = 1;
			else if(random_int < (old_chart[0][0] + old_chart[0][1] + old_chart[0][2]) * population)
				male = 2;
			else if(random_int < (old_chart[0][0] + old_chart[0][1] + old_chart[0][2] + old_chart[0][3]) * population)
				male = 3;
			else if(random_int < (old_chart[0][0] + old_chart[0][1] + old_chart[0][2] + old_chart[0][3] + old_chart[0][4] ) * population)
				male = 4;
			else
				male = 5;
			int random_int_1 = dist(generator);
			if(random_int_1 < old_chart[1][0] * population)
				female = 0;
			else if(random_int_1 < (old_chart[1][0] + old_chart[1][1]) * population)
				female = 1;
			else if(random_int_1 < (old_chart[1][0] + old_chart[1][1] + old_chart[1][2]) * population)
				female = 2;
			else if(random_int_1 < (old_chart[1][0] + old_chart[1][1] + old_chart[1][2] + old_chart[1][3]) * population)
				female = 3;
			else if(random_int_1 < (old_chart[1][0] + old_chart[1][1] + old_chart[1][2] + old_chart[1][3] + old_chart[1][4] ) * population)
				female = 4;
			else
				female = 5;
			int from_male, from_female;
			std::uniform_int_distribution<int> dist2(0, 1);
			int gene_m = dist2(generator);
			int gender = dist2(generator);
			if(male == 0)
				from_male = 0;
			else if(male == 1)
				if(gene_m == 0)
					from_male = 0;
				else
					from_male = 2;
			else if(male == 2)
				from_male = 1;
			else if(male == 3)
				if(gene_m == 0)
					from_male = 1;
				else
					from_male = 2;
			else if(male == 4)
				from_male = 2;
			else
				if(gene_m == 0)
					from_male = 0;
				else
					from_male = 1;
			//female
			int gene_f = dist2(generator);
			if(female == 0)
				from_female = 0;
			else if(female == 1)
				if(gene_f == 0)
					from_female = 0;
				else
					from_female = 2;
			else if(female == 2)
				from_female = 1;
			else if(female == 3)
				if(gene_f == 0)
					from_female = 1;
				else
					from_female = 2;
			else if(female == 4)
				from_female = 2;
			else
				if(gene_f == 0)
					from_female = 0;
				else
					from_female = 1;
			if(from_male == 0)
			{
				if(from_female == 0)
				{
					if(gender == 0)
						calc[0][0]++;
					else
						calc[1][0]++;
				}
				else if(from_female == 1)
				{
					if(gender == 0)
						calc[0][5]++;
					else
						calc[1][5]++;
				}
				else if(from_female == 2)
				{
					if(gender == 0)
						calc[0][1]++;
					else
						calc[1][1]++;
				}
			}
			else if(from_male == 1)
			{
				if(from_female == 0)
				{
					if(gender == 0)
						calc[0][5]++;
					else
						calc[1][5]++;
				}
				else if(from_female == 1)
				{
					if(gender == 0)
						calc[0][2]++;
					else
						calc[1][2]++;
				}
				else if(from_female == 2)
				{
					if(gender == 0)
						calc[0][3]++;
					else
						calc[1][3]++;
				}
			}
			else if(from_male == 2)
			{
				if(from_female == 0)
				{
					if(gender == 0)
						calc[0][1]++;
					else
						calc[1][1]++;
				}
				else if(from_female == 1)
				{
					if(gender == 0)
						calc[0][3]++;
					else
						calc[1][3]++;
				}
				else if(from_female == 2)
				{
					if(gender == 0)
						calc[0][4]++;
					else
						calc[1][4]++;
				}
			}
		}
		int birth_m, birth_f;
		birth_m = calc[0][0] + calc[0][1] + calc[0][2] + calc[0][3] + calc[0][4] + calc[0][5];
		birth_f = calc[1][0] + calc[1][1] + calc[1][2] + calc[1][3] + calc[1][4] + calc[1][5];
		int pop[2][6];
		for(int i = 0; i < 6; i++)
			pop[0][i] =
				old_chart[0][i] * population_m;
		for(int i = 0; i < 6; i++)
			pop[1][i] = old_chart[1][i] * population_f;
		while(death_population_m > 0)
		{
			std::uniform_int_distribution<int> de_dist(0, population_m2);
			int random_int = de_dist(generator);
			if (random_int < pop[0][0])
				pop[0][0]--;
			else if(random_int < pop[0][0] + pop[0][1])
				pop[0][1]--;
			else if(random_int < pop[0][0] + pop[0][1] + pop[0][2])
				pop[0][2]--;
			else if(random_int < pop[0][0] + pop[0][1] + pop[0][2] + pop[0][3])
				pop[0][3]--;
			else if(random_int < pop[0][0] + pop[0][1] + pop[0][2] + pop[0][3] + pop[0][4])
				pop[0][4]--;
			else
				pop[0][5]--;
			population_m2--;
			death_population_m--;
		}
		while(death_population_f > 0)
		{
			std::uniform_int_distribution<int> de_dist(0, population_f2);
			int random_int = de_dist(generator);
			if (random_int < pop[1][0])
				pop[1][0]--;
			else if(random_int < pop[1][0] + pop[1][1])
				pop[1][1]--;
			else if(random_int < pop[1][0] + pop[1][1] + pop[1][2])
				pop[1][2]--;
			else if(random_int < pop[1][0] + pop[1][1] + pop[1][2] + pop[1][3])
				pop[1][3]--;
			else if(random_int < pop[1][0] + pop[1][1] + pop[1][2] + pop[1][3] + pop[1][4])
				pop[1][4]--;
			else
				pop[1][5]--;
			population_f2--;
			death_population_f--;
		}
		for(int i = 0; i < 2; i++)
			for(int k = 0; k < 6;k++)
			{
				if(i == 0)
					old_chart[i][k] = (double)(calc[i][k] + pop[i][k]) / (double)(population_m2 + birth_m);
				else
					old_chart[i][k] = (double)(calc[i][k] + pop[i][k]) / (double)(population_f2 + birth_f);
				//printf("i = %d, k = %d, calc[i][k] = %d, pop[i][k] = %d\n", i, k, calc[i][k], pop[i][k]);
			}
		//printf("population_m2: %d,birth_m: %d\n", population_m2, birth_m);
		//printf("population_f2: %d,birth_f: %d\n", population_f2, birth_f);
		population_m = population_m2 + birth_m;
		population_f = population_f2 + birth_f;
		population = population_m + population_f;
		//printf("calc sum = %lf\n", calc_sum);
		printf("Year %d\n", r + 1);
		for(int i = 0; i < 2; i++)
		{
			for(int k = 0; k < 5;k++)
				printf("%lf ", old_chart[i][k]);
			printf("%lf\n", old_chart[i][5]);
		}
	}
	/*for(int i = 0; i < 2; i++)
	{
		for(int k = 0; k < 5;k++)
			printf("%lf ", old_chart[i][k]);
		printf("%lf\n", old_chart[i][5]);
	}*/
	return 0;
}
