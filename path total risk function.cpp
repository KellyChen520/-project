double(int Xstart, int Xend, int Ystart, int Yend, int *X, int *Y, int *R, int *P)
{
	double totalRisk = 0;
	double length = sqrt(pow(Xstart - Xend,2) + pow(Ystart - Yend,2));
		
	int times = static_cast<int>(length);   //����I�Ӽ� 
		
	if(times == length)
		times -= 1;
	 
	for(int t = 1; t <= times; t++)//dot num
	{
		double x = Xstart + (Xend-Xstart) / length * t;  //�U�@�Ӫ�x�y�� 
		double y = Ystart + (Yend-Ystart) / length * t;  //�U�@�Ӫ�y�y�� 
			
		for(int b = 0; b < m; b++)//bomb num
		{
			double d = sqrt(pow((x - X[b]), 2) + pow((y - Y[b]), 2));   //�����I�M���u���Z�� 
				
			if(R[b] - d > 0)
			{
				totalRisk += P[b] * (R[b] - d) / R[b];
			}
					
		}
	}
	
	return totalRisk;
}

