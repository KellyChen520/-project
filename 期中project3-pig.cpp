/*
���]�@������I
�]�x�θ̪��C���I 
������׬O�_�W�L ���K�s�Ubool�� 
�_�h�⭷�I

for
���]�������I
�]bool = 1���I
...
���]�T 

�@����� (Risk0/w)+1������I

����`���� = risk+ w(k - 1)
if R-d > 0,risk = (R-distance)/R; else Risk=0
distance = sqrt()
*/
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	//cin
	int n = 0, m = 0; //��l�I0~n m�ӫ¯��I
	float w = 0, d = 0; //d�Z������ 
	cin >> n >> m >> w >> d;
	
	int *X = new int[m]; //�¯��I�y��X 
	for(int i = 0; i < m; i++)
		cin >> X[i];
	
	int *Y = new int[m]; //�¯��I�y��Y 
	for(int i = 0; i < m; i++)
		cin >> Y[i];
	
	int *R = new int[m]; //Radius 
	for(int i = 0; i < m; i++)
		cin >> R[i];
	
	int *P = new int[m]; //���I���� 
	for(int i = 0; i < m; i++)
		cin >> P[i];
	
	int Xs = 0, Ys = 0, Xt = 0, Yt = 0; //start(Xs, Ys) terminal(Xt, Yt) 
	cin >> Xs >> Ys >> Xt >> Yt;
	
	//��0����Irisk
	float risk0 = //totalLineRisk (m, Xs, Xt, Ys, Yt, X, Y, R, P);!!!!!!!!
	
	//����׽d��
	float midX = (Xs + Xt) / 2;
	float midY = (Ys + Yt) / 2;
	
	//inD��X�b���׽d�򤺪��I(���έ��n������I) 
	int circleMaxX = midX + d/2; //��Τ��umaxX�y�� 
	int circleMinX = midX - d/2; //��Τ��uminX�y��
	int circleMaxY = midY + d/2; //��Τ��umaxY�y��
	int circleMinY = midY - d/2; //��Τ��uminY�y��
	
	/*
	//�YmidX+d���p���I�A�h�L����i�� 
	if(midX + d/2 > circleMaxX)
		circleMaxX += 1;
	if(midY + d/2 > circleMaxY)
		circleMaxY += 1;
	*/
	
	//�T�{�S�W�X�x�}��� 
	if(circleMaxX > n)
		circleMaxX = n;
	if(circleMinX < 0)
		circleMinX = 0;
	if(circleMaxY > n)
		circleMaxY = n;
	if(circleMinY < 0)
		circleMinY = 0;
		
	//�ŧi�������I�O�_�b���׽d�򤺪��x�}inD 
	bool** inD = new bool* [circleMaxY + 1];
	for(int i = 0; i <= circleMaxY; i++)
	{
		inD[i] = new bool[circleMaxX + 1];
		for(int j = 0; j <= circleMaxX; j++)
			inD[i][j] = 0;
	}
	
	//�����Τ��C�@�I�O�_�b���׽d��d�� 
	for(int y = circleMinY; y <= circleMaxY; y++)
	{
		for(int x = circleMinX; x <= circleMaxX; x++)
		{
			if(sqrt(pow(x-Xs, 2) + pow(y-Ys, 2)) + sqrt(pow(Xt-x, 2) + pow(Yt-y, 2)) <= d)
				inD[y][x] = 1;
		} 
	} 
	/* 
	for(int y = circleMinY; y <= circleMaxY; y++)
	{
		for(int x = circleMinX; x <= circleMaxX; x++)
		{
			if(x == circleMaxX)
				cout << inD[y][x] <<"\n";
			else
				cout << inD[y][x] <<" ";	
		}
	} 
	*/
	
	int turnTimes = risk0;//����I���� 
	if(risk0 > 10)
	{
		if(w >= 1)
			turnTimes = risk0 / w + 1;
		else
			turnTimes = 150; //check!!
	}
	
		
		
	//risk[i]���i������I�ɪ��̤prisk
	float* risk = new float [];//problem!!
	for(int i = 0; i < risk0/w + 1; i++)
		risk[i] = -1;
	risk[0] = risk0; 
	//cout << risk[0];
	
	/*
	//�@������I 
	for(int y = circleMinY; y <= circleMaxY; y++)
	{
		for(int x = circleMinX; x <= circleMaxX; x++)
		{
			if(inD[y][x] == 1)
			{
				//risk function(����I(x,y))				
			}
		} 
	} */
	
	
	/* 
	int ansK = 0;
	int* ansXY = new int[2*turnTimes];
	
	//turnTimes�Ӱj��
	for(int k = 1; k <= turnTimes; k++) //�� k �� 
	{
		int* turnPlace = new int[2*k+5];
		turnPlace[0] = Xs, turnPlace[1] = Ys;
		turnPlace[2*k+2] = Xt,turnPlace[2*k+3] = Yt;
		for(int i = 2; i < 2*k+1; i++) //��k������I�� X�y�� = turnPlace[2k],Y�y�� = turnPlace[2k+1] 
			turnPlace[i] = -1;
		
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
	*/	
	 
	
	delete[] X;
	delete[] Y;
	delete[] R;
	delete[] P;
	delete[] risk;
	for(int i = 0; i < circleMaxY +1; i++)
		delete[] inD[i];
	
	return 0;
}

