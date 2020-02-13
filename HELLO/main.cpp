#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
using namespace std;

void Prims(float W[][5], int **T, int N)
{
        int i, j, k;

        // array of nearest node
        int *nearNode = new int[N];

        // array of distance to nearest node
        float *minDist = new float[N];
        float min;

        // assume 0 as root node, set it as nearest node to all nodes

        for (i = 1; i < N; i++)
        {
		nearNode[i] = 0;

		// set distance of each node from [0]
		minDist[i] = W[i][0];
        }

        // loop for all (N-1) edges

        for (i = 0; i < N-1; i++)
        	{
    		 min = 999999;

     // find minimum distance
         	  for (j = 1; j < N; j++)
                  {
                  if (0 <= minDist[j] && minDist[j] < min)
                       {
		                min = minDist[j];
		                // k is closest node
		                k = j;
                        }
                  }   // update output array - link from nearNode to node

                  T[i][0] = nearNode[k];
                  T[i][1] = k;

                  // k is in the tree; set distance to -1
                  minDist[k] = -1;
                  // updates all node distances wrt new tree
                  #pragma omp parallel for

                  for (j = 1; j < N; j++)
                       {
                          if (W[j][k] < minDist[j])
 	                	{
		                      minDist[j] = W[j][k];
		                      nearNode[j] = k;
                             	}
                       } // for i
                      }
              return;
              free(nearNode); free(minDist);
}

int main()
{
//	double start_time = omp_get_wtime();
	float W[][5] = {{30, 999, 40, 999}, {999, 57, 999, 42}, {7, 999, 95, 999}, {999, 20, 999, 4}, {47, 999, 81, 999}};

	int N = 5;
	int **t = new int*;
	for(int i = 0; i < N; i++)
	{
		t[i] = new int;
	}

	Prims(W, t, N);

	for(int i = 0; i < N; i++)
	{
		cout << t[i][0] <<"\t" <<t[i][1] <<endl<<endl;
	}
	//	cout<< omp_get_wtime() - start_time<<"\n";
	return 0;
}

