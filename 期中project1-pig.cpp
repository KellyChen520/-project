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
using namespace std;
int main()
{
	//cin
	int n = 0, m = 0, w = 0, d = 0; //��l�I0~n m�ӫ¯��I d�Z������ 
	int Xs = 0, Ys = 0, Xt = 0, Yt = 0; //start(Xs, Ys) terminal(Xt, Yt) 
	cin >> n >> m >> w >> d;
	
	int *X = new int[m]; //�¯��I�y��X 
	for(int i = 0; i < m, i++)
	{
		cin >> X[i];
	}
	
	int *Y = new int[m]; //�¯��I�y��Y 
	for(int i = 0; i < m, i++)
	{
		cin >> Y[i];
	}
	
	int *R = new int[m]; //Radius 
	for(int i = 0; i < m, i++)
	{
		cin >> R[i];
	}
	
	int *P = new int[m]; //���I���� 
	for(int i = 0; i < m, i++)
	{
		cin >> P[i];
	}
	
	cin >> Xs >> Ys >> Xt >> Yt;
	
	//��0����Irisk
	 
	
}
