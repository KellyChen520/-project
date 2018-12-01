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
�ﵽ:
1.���^�Y 
2.����� ->if better,�٧� 
3.�D�I�� ���n�C�Ө� 
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

float straightLineRisk (int Xstart, int Xend, int Ystart, int Yend, int *X, int *Y, int *R, int *P, int m);
float newStart(int distance, float start, float end, float tempL);
float totalLineRisk(int *allPoints, int *X, int *Y, int *R, int *P, int m, int k, int turnTimes);
//void findMinCost(float d,int m, int w, int k,int turntimes,bool **inD, float lowcost, int circleMinX,int circleMaxX,int circleMinY,
//					int circleMaxY,int* turnPlace,int &ansturn,int *ansXY , float *distance, int* X, int* Y, int* R, int* P, int cut);
//bool repeat(int x,int y, int k, int *turnPlace, int turnTimes);
//bool turnback(int x, int y, int k, int* turnPlace, int turnTimes);
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
	
	int XX=Xs,YY=Ys;//�W�٭��ơA�ҥH�ڧ令XX & YY 
	
	//��0����Irisk
	float risk0 = straightLineRisk(Xs, Xt, Ys, Yt, X, Y, R, P, m);
	
	//���l�e�j 
	int cut = 0, cutX=0, cutY=0;
	if(abs(Xs - Xt) < abs(Ys - Yt))
		cut = abs(Xs - Xt) / 70;
	else 
		cut = abs(Yt - Ys) / 50;

	if(cut == 0);
		cut = 1;
	
	cutX = cut * ((Xt - Xs) / abs(Xt - Xs));
	cutY = cut * ((Yt - Ys) / abs(Yt - Ys));
	
	int turnTimes = risk0;//����I���� 
	if(risk0 > 10)
	{
		if(w >= 1)
			turnTimes = risk0 / w + 1;
		else
			turnTimes = 150; //check!!
	}
	
	
	int* turnPlace = new int[2 * turnTimes + 15]; //�s�_�IXY�B�U����IXY�B���IXY 
	turnPlace[0] = Xs, turnPlace[1] = Ys;
	turnPlace[2 * turnTimes + 2] = Xt, turnPlace[2 * turnTimes + 3] = Yt;
	for(int i = 2; i < 2*turnTimes + 2; i++) //��k������I�� X�y�� = turnPlace[2k],Y�y�� = turnPlace[2k+1] 
		turnPlace[i] = -1;//��l�� 
		
	int ansK = 0;//��X�� 
	/*int* ansXY = new int[2*turnTimes+4]; //�̫�n��X���y�� 
	for(int i = 0; i < 2*turnTimes+4; i++)
		ansXY[i] = -1; //-1����X */
		
	float lowCost = risk0;//lowcost�O�̧C�����I�A��l�Ʀ�risk0 
	/*float *distance = new float [turnTimes+1];
	for(int i = 0; i < turnTimes+1; i++)
		distance[i] = 0 ;*/

	//findMinCost(d, m, w, 1, turnTimes, inD, lowCost, circleMinX, circleMaxX, circleMinY, circleMaxY, turnPlace, 
	//			ansK, ansXY, distance, X, Y, R, cut);
	//�}�l 
	float ansDistance = 0;
	while ( ansK <= turnTimes )
	{
		float cost[3] = {-1, -1, -1};//��l�Ʀ�-1 
		float minCost = lowCost; //minCost �O�o�h�j��� �@�}�l���̧C���I 
		int xx[3] = {0};
		int yy[3] = {0};
		int path = 0;//�ڧ�X1,X2,x3 & Y1 Y2 Y3�ܦ��x�},���s�R�W��xx & yy ,path�N��ڭ̳̫�n������� 
		
		if(abs(XX - Xt) <= cut && abs(YY - Yt) <= cut)
	 		break;
	 	
		yy[0]=YY, 		   xx[0] = cutX + XX ;// type 1 
		yy[1] = YY + cutY, xx[1] = XX ; //type 2
		yy[2] = YY + cutY, xx[2] = XX + cutX;//type3
		
		for(int i = 0; i < 3; i++)
		{
			if(xx[i] > n)
				xx[i] = n;
			else if(xx[i] < 0)
				xx[i] = 0;
				
			if(yy[i] > n)
				yy[i] = n;
			else if(yy[i] < 0)
				yy[i] = 0;
		}

	
		for ( int i = 0 ; i < 3; i++ )//�T��type���]�@��
		{ 	
			//if((XX-Xt)/static_cast<float>(xx[i]-Xt) < 0 || (YY-Yt)/static_cast<float>(yy[i]-Yt) < 0)
			//	continue;
			
			if(sqrt(pow((yy[i] - Yt), 2) + pow((xx[i] - Xt), 2)) + //����I����I���Z�� + ����I��W�@������I���Z�� +�e���w���L���Z�� 
			sqrt(pow(yy[i] - turnPlace[2*ansK+1], 2) + pow((xx[i] - turnPlace[2*ansK]), 2)) + ansDistance <= d)
			{
				turnPlace[2*ansK + 2] = xx[i]; turnPlace[2*ansK + 3] = yy[i];
				cost[i] = totalLineRisk(turnPlace, X, Y, R, P, m, ansK + 1, turnTimes) + (ansK + 1) * w;
				//int *allPoints, int *X, int *Y, int *R, int *P, int m, int k, int turnTimes)
				//cout<<lowCost<<" "<<cost[i]<<endl;
			}
			
			if (cost[i] != -1 && cost [i] < minCost)
			{
				minCost = cost[i];
				path = i ;//�O�_�ӬO�������| 
			}	
		}
		
		//cout<<cost[0]<<" "<<cost[1]<<" "<<cost[2]<<endl;
		if(cost[0] == -1 && cost[1] == -1 && cost[2] == -1)//�W�L���|�W�� or �W�L���I X �� Y �y�� 
			break;
			
		if (minCost < lowCost) //��ܤT�����|���@������ �����٭n�p
		{ 
			turnPlace[2*ansK + 2] = xx[path]; turnPlace[2*ansK + 3] = yy[path];//�s�J����I�y��
			//cout<<xx[path]<<" "<<yy[path]<<endl;
			//�U���O��o������I��W������I���Z���s�JansDistance  
			ansDistance += sqrt(pow((turnPlace[2*ansK+3] - turnPlace[2*ansK+1]), 2) + pow((turnPlace[2*ansK+2] - turnPlace[2*ansK]), 2));
			lowCost = minCost; 
			ansK++;//��̧C�����I�ȩ�ilowCost, ��馸�ƥ[�@ 
			XX = xx[path];
			YY = yy[path];// �s�J����I�y�СA�U���j�骺�ɭ��~��� XX & YY 
		}
		else //���઺���I�̤p����
		{ 
			ansDistance += sqrt(pow(cutX, 2) + pow(static_cast<int>(cutX * (Yt - YY) / (Xt - XX)), 2));
			YY = YY + cutX * (Yt - YY) / (Xt - XX); //cutX�OX�����ܶq�A (Yt - YY)/(Xt-XX)�O�ײv 
			XX = XX + cutX;
			//cout<<XX<<" "<<YY;
		}
	}
	
	//���� 
	if(ansK == 0)
		cout << 0;
	else
	{
		cout << ansK <<" ";
		for(int i = 1; i <= ansK; i++)
		{
			if(i == ansK)
				cout << turnPlace[2 * i] << " " << turnPlace[2 * i + 1] ;
			else
				cout << turnPlace[2 * i] << " " << turnPlace[2 * i + 1] << " ";
		}
		 
	}
	delete[] X;
	delete[] Y;
	delete[] R;
	delete[] P;
	
	return 0;
}

//Function1:���u 
float straightLineRisk (int Xstart, int Xend, int Ystart, int Yend, int *X, int *Y, int *R, int *P, int m)
{
	float totalRisk = 0;
	float length = sqrt(pow(Xstart - Xend,2) + pow(Ystart - Yend,2));
		
	int times = static_cast<int>(length);   //����I�Ӽ� 
		
	if(times == length)
		times -= 1;
	 
	for(int t = 1; t <= times; t++)//dot num
	{
		float x = Xstart + (Xend-Xstart) / length * t;  //�U�@�Ӫ�x�y�� 
		float y = Ystart + (Yend-Ystart) / length * t;  //�U�@�Ӫ�y�y�� 
			
		for(int b = 0; b < m; b++)//bomb num
		{
			float d = sqrt(pow((x - X[b]), 2) + pow((y - Y[b]), 2));   //�����I�M���u���Z�� 
				
			if(R[b] - d > 0)
			{
				totalRisk += P[b] * (R[b] - d) / R[b];
			}			
		}
	}
	
	return totalRisk;
}

//Function2:��risk 
float totalLineRisk (int *allPoints, int *X, int *Y, int *R, int *P, int m, int k, int turnTimes)
{
	float eachPathRisk = 0;
	float totalRisk = 0;
	
	float Xnew = 0;   //�s���_�I��x�y�� 
	float Ynew = 0;   //�s���_�I��y�y��
	
	float Xstart = 0;
	float Ystart = 0;
	float Xend = 0;
	float Yend = 0;
	/*for(int qw=0;qw<=3;qw++)
			cout<<k<<"K "<<allPoints[2*qw]<<" "<<allPoints[2*qw+1]<<" ";
				cout<<endl;*/
	for(int i = 0; i <= 2 * k; i += 2)
	{
		float length = 0;
		if(i != 2*k)
	        length = sqrt(pow(allPoints[i] - allPoints[i+2],2) + pow(allPoints[i+1] - allPoints[i+3],2));
	    else
	        length = sqrt(pow(allPoints[i] - allPoints[2*turnTimes +2],2) + pow(allPoints[i+1] - allPoints[2*turnTimes +3],2));
	        
	    int times = static_cast<int>(length);   //�����I�Ӽ� 
	        
		if(i == 0 )
		{
			Xnew = allPoints[i];
			Ynew = allPoints[i+1];
			Xend = allPoints[i+2];
			Yend = allPoints[i+3];
		}
		else
		{
			Xstart = allPoints[i];
			Ystart = allPoints[i+1];
			if(i == 2*k)
			{
				Xend = allPoints[2*turnTimes +2];
				Yend = allPoints[2*turnTimes +3];
			}
			else
			{
				Xend = allPoints[i+2];
				Yend = allPoints[i+3];
			}
				

			float lengthInt = static_cast<float>(times);   
			float restLenghth = 1 - (length - lengthInt);   //�U�@�Ӱ_�I������I���Z�� 

            float tempL = sqrt(pow(Xstart - Xend, 2) + pow(Ystart - Yend, 2));
			Xnew = newStart(restLenghth, Xstart,  Xend, tempL);   //�s���_�I��x�y�� 
			Ynew = newStart(restLenghth, Ystart,  Yend, tempL);   //�s���_�I��y�y��
			//int distance, float start, float end, float tempL
		}

		if(times == length)
			times -= 1;
		

		if(Xnew != allPoints[0] && Ynew != allPoints[1])//�_�I
		{
			for(int b = 0; b < m; b++)//bomb num
			{
				float d = sqrt(pow((Xnew - X[b]), 2) + pow((Ynew - Y[b]), 2));   //�����I�M���u���Z�� 

				if(R[b] - d > 0)
				{
					eachPathRisk += P[b] * (R[b] - d) / R[b];
				}

			} 
		}
		
		length = sqrt(pow(Xnew - Xend, 2) + pow(Ynew - Yend, 2));   
		/*times = static_cast<int>(length);
		if(times == length)
			times -= 1;*/
		
	    for(int t = 1; t <= times; t++)//dot num
	    {
			float x = Xnew + (Xend-Xnew) / length * t;  //�U�@�Ӫ�x�y�� 
			float y = Ynew + (Yend-Ynew) / length * t;  //�U�@�Ӫ�y�y�� 
					
			for(int b = 0; b < m; b++)//bomb num
			{
				float d = sqrt(pow((x - X[b]), 2) + pow((y - Y[b]), 2));   //�����I�M���u���Z�� 
						
				if(R[b] - d > 0)
				{
					eachPathRisk += P[b] * (R[b] - d) / R[b];
				}
							
			}
	    }
		
		//cout<<eachPathRisk<<" ";
		totalRisk += eachPathRisk;
	}
	
	//cout << totalRisk << '\n';
	return totalRisk;
}

//Function3
float newStart(int distance, float start, float end, float tempL)
{
	float newPoint = start + ((end - start)*distance)/tempL;
	
	return newPoint;
}
/*
//Function4
void findMinCost(float d,int m, int w, int k,int turnTimes,bool **inD, float lowCost, int circleMinX,int circleMaxX,int circleMinY,
					int circleMaxY,int* turnPlace,int &ansK,int *ansXY , float *distance, int* X, int* Y, int* R, int* P, int cut)
{//��k�� 	
	if(k > turnTimes)
		return;
	
}

//Function5
bool repeat(int x,int y, int k, int *turnPlace, int turnTimes)
{
	//���IXY turnPlace[2*turnTimes+2] = Xt,turnPlace[2*turnTimes+3] = Yt; 
	bool check = 0;
	for(int i = 0; i <= k; i++)
	{
		if (x == turnPlace[2*i] && y == turnPlace[2*i+1] )
			check = 1;
	}
	if(x == turnPlace[2*turnTimes+2] && y == turnPlace[2*turnTimes+3])
		check = 1;
	
	return check;
}

//Function6
bool turnback(int x, int y, int k, int* turnPlace, int turnTimes)
{
	//���IXY turnPlace[2*turnTimes+2] = Xt,turnPlace[2*turnTimes+3] = Yt; 
	//turnPlace[2*(k-1)](X,turnPlace[2*k-1] (Y
	int maxX = turnPlace[2*turnTimes+2];
	int minX = turnPlace[2*k-2];
	int maxY = turnPlace[2*turnTimes+3];
	int minY = turnPlace[2*k-1];
	
	int temp = 0;
	if(maxX < minX)
		temp = maxX, maxX = minX, minX = temp;
	if(maxY < minY)
		temp = maxY, maxY = minY, minY = temp;
		
	bool Xout = 0, Yout = 0; 
	if(x > maxX || x < minX)
		Xout = 1;
	if(y > maxY || y < minY)
		Yout = 1;
	
	if(Xout == 1 || Yout ==1)
		return 1;
	else
		return 0;
}*/
