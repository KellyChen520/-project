#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	
	int X[10] = {0};   
	int Y[10] = {0};    
	int R[10] = {0};
	int P[10] = {0};
	float distance = 0;   //�U�I��¯��I���Z�� 
	float eachDanger = 0;   //�U�I���@�¯��I�����I 
	float maxRisk = 0;   //�Ҧ��I�����̤j���I 
	int maxRiskI = 0;   //�Ҧ��I���̤j���I��x�y�� 
	int maxRiskJ = 0;   //�Ҧ��I���̤j���I��y�y�� 
	
	for(int i = 0; i < m; i++)
	{
		cin >> X[i];
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> Y[i];
	}
	
	for(int i=0; i<m; i++)
	{
		cin >> R[i];
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> P[i];
	}
	
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			float pointRisk = 0;   //�U�I���`���I 
			for(int k = 0; k < m ;k++)
			{
				distance = sqrt (pow (i - X[k], 2) + pow (j - Y[k], 2));   //�p�⦹�I�M�@�ӫ¯��I���Z�� 
				eachDanger = ((R[k] - distance) / R[k]) * P[k];    //�p�⦹�I���@�¯��I�����I 
				
				if(eachDanger < 0)   //�Y���I���t��(�Y���I�D�b�¯��I���¯ٽd��)�A�h�O�����s 
				{
					eachDanger = 0;
				}
				
				pointRisk += eachDanger;   //�p�⦹�I�M�U�ӫ¯��I�����I���M 
				
				if(pointRisk == maxRisk)   //�Y�`���I����ثe���̤j���I�� 
				{
					if(i <= maxRiskI)   //��������I�M�ثe���̤j���I��x�y�СA�Y���I��x�y�Фp�󵥩�̤j���I��x�y�СA�h�A�i��y�y�Ъ���� 
					{
						if(j < maxRiskJ)   //�Y���I��y�y�Фp��e���̤j���I��y�y�СA�h�N���I�O���ثe�̤j���I���I 
						    maxRiskI=i;
					        maxRiskJ=j;
					}
				}
				
				if(pointRisk > maxRisk)   //�Y�`���I�j��ثe���̤j���I�ɡA�O���I���ثe�̤j���I���I 
				{
					maxRisk = pointRisk;
					maxRiskI = i;
					maxRiskJ = j;
				}
			}
		}
	}
	
	cout << maxRiskI << " " << maxRiskJ;

	
	
	return 0;
} 
