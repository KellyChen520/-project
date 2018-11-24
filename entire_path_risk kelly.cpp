float totalLineRisk (int *allPoints, int *X, int *Y, int *R, int *P, int m)
{
	float eachPathRisk = 0;
	float totalRisk = 0;
	
	float Xnew = 0;   //�s���_�I��x�y�� 
	float Ynew = 0;   //�s���_�I��y�y��
	
	float Xstart = 0;
	float Ystart = 0;
	float Xend = 0;
	float Yend = 0;
	
	for(int i =0; i <= 2*k + 5; i += 2)
	{
		if(allPoints[i] != -1)
		{
	        float length = sqrt(pow(allPoints[i] - allPoints[i+2],2) + pow(allPoints[i+1] - allPoints[i+3],2));
	        
	        int times = static_cast<int>(length);   //����I�Ӽ� 
	        
	        if(i == 0 )
	        {
	        	Xnew = allPoints[i];
	        	Ynew = allPoints[i+1];
			}
			else
			{
				Xstart = allPoints[i];
				Ystart = allPoints[i+1];
				Xend = allPoints[i+2];
				Yend = allPoints[i+3];
				
				float lengthInt = static_cast<float>(times);   
	            float restLenghth = 1 - (length - lengthInt);   //�U�@�Ӱ_�I������I���Z�� 
	            
	            Xnew = newStart(restLenghth, Xstart,  Xend);   //�s���_�I��x�y�� 
	            Ynew = newStart(restLenghth, Ystart,  Yend);   //�s���_�I��y�y��
			}
	        
	        if(times == length)
		    times -= 1;
	 
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
		}
		
		totalRisk += eachPathRisk;
	}
	
	
	return totalRisk;
}

float newStart(int distance, float start, float end)
{
	float newPoint = start + (end - start)/distance;
	
	return newPoint;
}

