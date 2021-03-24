#include <stdio.h>
#include <stdlib.h>


#define N 10  // Do NOT change this line!

struct points_def
{
  int x;
  int y;
};
typedef struct points_def point;

void fill(char filename[], point P[])
{

  FILE *ifp = NULL;
  ifp = fopen(filename, "r");  
  char buf[5];

      if(ifp == NULL)
      {
        printf("Sorry, the file did not open properly...Exiting\n");
        exit(1);
      }
      
  for(int i = 0; i < N; i++)
  {
    fscanf(ifp, "%d", &P[i].x);
    fscanf(ifp, "%d", &P[i].y);
  }

  fclose(ifp);
}

int getdist(point p, point q)
{

  int k = ((q.x - p.x)*(q.x - p.x)) + ((q.y - p.y)*(q.y - p.y));
 
    return k; 

}

void closest(point P[], int G[2*N][2*N])
{

  int closest = getdist(P[0], P[1]); 
  point a; 
  point b;

  for(int i = 0; i < N; i++)
  {
    for(int j = (i+1); j < N; j++)
    {
      if(getdist(P[i], P[j]) < closest)
      {
        closest = getdist(P[i], P[j]);
        a.x = P[i].x; 
        a.y = P[i].y;
        b.x = P[j].x;
        b.y = P[j].y;
      }
    } 
  }

  G[a.y][a.x] = 'X';
  G[b.y][b.x] = 'X';

}

void grid(point P[], int G[2*N][2*N])
{
  
  for(int i = 0; i < N; i++)
  {
    G[P[i].y][P[i].x] = '*';
  }

  closest(P, G);

}

void printpoints(char filename[], point P[])
{

  FILE *ofp = NULL;
  ofp = fopen(filename, "w"); 
     if(ofp == NULL)
     {
        printf("Sorry, the file did not open properly...Exiting\n");
        exit(1);     
     }

   for(int i = 0; i < N; i++)
  {
    fprintf(ofp, "%d: (%2d, %d)\n", i, P[i].x, P[i].y);
  }

  fclose(ofp);

}

void printgridxy(char filename[], int G[2*N][2*N])
{

  FILE *ofp = NULL;
  ofp = fopen(filename, "a");

  fprintf(ofp, "--------------------------------------------------\n");

  for(int i = (2*N-1); i > 0; i--)
  {
    for(int j = 0; j < (2*N); j++)
    {
      if(G[i][j] == 0)
      {
        fprintf(ofp, "  "); 
      }
      else
      {
        fprintf(ofp, "%c ", G[i][j]);
      }
    }
      
          fprintf(ofp, "\n"); 
  }

  fprintf(ofp, "--------------------------------------------------");

  fclose(ofp);

}


int main(int argc, char *argv[])
{
/*
	Do not change anything in main!  Also do not change the #define
	at the top of the program.

	There is one exception to this, you may change the "type" for the
	structure you made if you don't use my naming scheme.
*/
	if (argc != 3)
	{
		printf("Syntax Error: ./a.out <infile> <outfile>\n");
		exit(1);
	}

	point P[N];  //  <-- This is the only line you are allowed to change.
	int G[2*N][2*N] = {0};

	fill(argv[1], P);
	grid(P, G);
	printpoints(argv[2], P);
	printgridxy(argv[2], G);



  return 0;
}
