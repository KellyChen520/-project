
#include <iostream>
#include <cmath>
using namespace std;

float totalLineRisk (int bombNum, int Xstart, int Xend, int Ystart, int Yend, int *X, int *Y, int *R, int *P);
int main()
{
	//turnTimes�Ӱj��
	for(int k = 1; k <= turnTimes; k++) //�� k �� 
	{
		int* turnPlace = new int[2*k+1];
		for(int i = 0; i < 2*k+1; i++) //��k������I�� X�y�� = turnPlace[2(k-1)],Y�y�� = turnPlace[2(k-1)+1] 
			turnPlace[i] = -1;
		//function find
		for(int times = 1; times <= k; times++)
		{
			for(int y = circleMinY; y <= circleMaxY; y++)
			{
				for(int x = circleMinX; x <= circleMaxX; x++)
				{
					if(inD[y][x] == 1)
					{
						turnPlace[2*times-2] = x;
						turnPlace[2*times-1] = y;
						//risk function(����I(x,y))
						//�smin risk,x,y				
					}
				} 
			} 
		}		
	} 
	
		
	
	
	return 0;
	
)


	
void find(int k,int turntimes,int **inD,int circleMinX,int circleMaxX,
				int circleMinY,,int circleMaxY,int* turnPlace)
{//��k�� 	
	if(k>turntimes)
		return 0;
	for(int y = circleMinY; y <= circleMaxY; y++)
	{
		for(int x = circleMinX; x <= circleMaxX; x++)
		{
			if(inD[y][x] == 1)
			{
				turnPlace[2*k-2] = x;
				turnPlace[2*k-1] = y;
						//risk function(����I(x,y))
						//�smin risk,x,y
				find(k+1,turntimes,inD,circleMixX, circleMaxX, circleMixY circleMaxY, turnPlace);
				
			}
		} 
	}
	 
	
}



